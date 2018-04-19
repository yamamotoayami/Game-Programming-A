#include <stdio.h>

// TODO-1: 三次元ベクトル構造体を宣言する
//
struct Vector3
{

};

// TODO-5: ベクトルの長さを計算する関数 Length を作成

int main()
{
    // TODO-2: 2つの三次元ベクトルを宣言
    //  a = (0, 1.0, 0)
    //  b = (1.0, 0, 1.0)

    // TODO-3: ベクトルaとbの和をベクトルcに代入し
    // 計算結果をprintf関数で出力
    Vector3 c;

    // TODO-4: ベクトルaとbの内積をprintf関数で出力

    // TODO-5: ベクトルcの長さlenをprintf関数で出力
    double len = Length(c);

    return 0;
}