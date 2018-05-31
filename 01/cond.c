#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a[20];
    int i;
    for ( i = 0; i < 20; i++)
    {
        a[i] = rand();
   
    
    if (a[i] % 2 == 0) 
    {
    printf("%2d ,",a[i] );
    }
}
    // TODO: 上記のとおりランダムに生成した20個の
    // 整数を格納した配列から，偶数のみを選択して
    // コンソールに出力するプログラムを作成．

    return 0;
}
