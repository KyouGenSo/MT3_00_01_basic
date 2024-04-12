#include <Novice.h>
#include <Vector3Function.h>

const char kWindowTitle[] = "LE2A_10_キョウ_ゲンソ";

void Vector3ScreenPrint(int x, int y, Vector3 v, const char* moji) {
	Novice::ScreenPrintf(x, y, "%.1f, %.1f, %.1f %s", v.x, v.y, v.z, moji);
}

int kRowHeight = 20;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	int windowX = 1280;
	int windowY = 720;
	Novice::Initialize(kWindowTitle, windowX, windowY);


	Vector3 v1 = { 1.0f, 2.0f, 3.0f };
	Vector3 v2 = { 4.0f, 5.0f, 6.0f };
	float k = 2.0f;

	Vector3 resultAdd = Add(v1, v2);
	Vector3 resultSubtract = Subtract(v1, v2);
	Vector3 resultMultiply = Multiply(v1, k);
	float resultDot = Dot(v1, v2);
	double resultLength = Length(v1);
	Vector3 resultNormalize = Normalize(v1);


	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///-------------------///
		/// ↓更新処理ここから///
		///-------------------///



		///-------------------///
		/// ↑更新処理ここまで///
		///-------------------///

		///-------------------///
		/// ↓描画処理ここから///
		///-------------------///


		Vector3ScreenPrint(0, 0, resultAdd, ": Add");
		Vector3ScreenPrint(0, kRowHeight, resultSubtract, ": Subtract");
		Vector3ScreenPrint(0, kRowHeight * 2, resultMultiply, ": Multiply");
		Novice::ScreenPrintf(0, kRowHeight * 3, "%.1f  : Dot", resultDot);
		Novice::ScreenPrintf(0, kRowHeight * 4, "%.1f  : Length", resultLength);
		Vector3ScreenPrint(0, kRowHeight * 5, resultNormalize, ": Normalize");


		///-------------------///
		/// ↑描画処理ここまで///
		///-------------------///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
