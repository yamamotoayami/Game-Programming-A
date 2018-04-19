#include <stdio.h>

int main(void)
{
    int array1[3] = {1, 2, 3};
    int array2[3] = {4, 5, 6};
    
    // TODO: 配列array1とarray2の中身を入れ替えるプログラムを作成
    //
    // 出力正解
    //  4, 5, 6
    //  1, 2, 3
    
    printf("%d, %d, %d\n", array1[0], array1[1], array1[2]);
    printf("%d, %d, %d\n", array2[0], array2[1], array2[2]);
    
    return 0;
}
