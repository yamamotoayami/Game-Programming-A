#include <stdio.h>
#include <math.h>

// 二次元ベクトルクラス
//
class Vector2
{
public:
    // デフォルトコンストラクタ
    Vector2()
    {
        x = 0.0;
        y = 0.0;
    }
    // 初期化子付きコンストラクタ
    Vector2(double ix, double iy)
    {
        x = ix;
        y = iy;
    }
    // デストラクタ
    ~Vector2()
    {
    }
public:
    double GetX() const
    {
        return x;
    }
    double GetY() const
    {
        return x;
    }
    void SetX(double ix)
    {
        x = ix;
    }
    void SetY(double iy)
    {
        y = iy;
    }
    void Set(double ix, double iy)
    {
        x = ix;
        y = iy;
    }
public:
    void operator=(Vector2 src) // 実は問題があるコード　後日の講義を踏まえて修正予定
    {
        x = src.x;
        y = src.y;
    }
    Vector2 operator+(Vector2 v)
    {
        return Vector2(x + v.x, y + v.y);
    }
    Vector2 operator-(Vector2 v)
    {
        return Vector2(x - v.x, y - v.y);
    }
    Vector2 operator*(double scale)
    {
        return Vector2(x * scale, y * scale);
    }
public:
    void ZeroClear()
    {
        x = 0;
        y = 0;
    }
    double Length() const
    {
        return sqrt(x * x + y * y);
    }
    void Print(const char prefix[]) const
    {
        printf("%s[%f,%f]\n", prefix, x, y);
    }
private: // プライベートなメンバは目立たないところ（一番下）に書いている（向井個人的な好み）
    double x;
    double y;
};

int main()
{
    Vector2 a(10.0, 20.0); // 二次元ベクトルaを宣言
    Vector2 b(5.0, -10.0); // 二次元ベクトルbを宣言
    a.Print("a = ");
    b.Print("b = ");

    // 足し算
    Vector2 c = a + b;
    c.Print("a + b = ");
    // 引き算
    (a - b).Print("a - b = ");
    // 拡大縮小
    Vector2 d = a * 3.0;
    d.Print("a * 3 = ");
    // 長さ
    printf("len(a) = %f\n", a.Length());

    return 0;
}
