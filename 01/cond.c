#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int array[20];
    for (int i = 0; i < 20; ++i)
    {
        array[i] = random();
    }

    // TODO: 上記のとおりランダムに生成した20個の
    // 整数を格納した配列から，偶数のみを選択して
    // コンソールに出力するプログラムを作成．

    return 0;
}