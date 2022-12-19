叉积可以判断两条直线的方向向量是否平行、是否共线。

使用叉积计算两条直线的交点，最后判断交点是否落于给定的两条线段内。

使复杂的东西简单化，便是数学的魅力。（不知何时填坑）

```cpp
const double EPS = 1e-8;

class Solution {
public:
    struct vector2{
        double x, y;
        vector2(){}
        vector2(double x0, double y0){ x = x0; y = y0; }
        vector2 operator - (const vector2 &b)const { return vector2(x - b.x, y - b.y); }
        double operator * (const vector2 &b)const { return x * b.x + y * b.y; }
        double operator ^ (const vector2 &b)const { return x * b.y - y * b.x; }
        bool operator == (const vector2 &b) const{  return fabs(x - b.x) < EPS && fabs(y - b.y) < EPS; }
        bool operator < (const vector2 &b) const{ 
            if (fabs(x - b.x) >= EPS) return x < b.x;
            if (fabs(y - b.y) >= EPS) return y < b.y;
            return false;
        }
        bool operator <= (const vector2 &b) const{ 
            if (*this == b) return true;
            return *this < b;
        }
    };

    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        vector2 a = vector2(start1[0], start1[1]), b = vector2(end1[0], end1[1]);
        vector2 p = vector2(start2[0], start2[1]), q = vector2(end2[0], end2[1]);
        
        if (b < a) swap(a, b);
        if (q < p) swap(p, q);

        if (fabs((a - b) ^ (p - q)) < EPS){ // 判断线段的方向向量是否平行
            if (fabs((a - q) ^ (p - b)) < EPS){ // 判断线段所在两条直线是否共线
                if (b < p || q < a) return {}; // 判断共线线段是否重合
                if (a < p) return {p.x, p.y};
                return {a.x, a.y};
            }else return {};
        }

        double len = ((a - p) ^ (p - q)) / ((a - b) ^ (p - q));
        vector2 ans = vector2(a.x + (b.x - a.x) * len, a.y + (b.y - a.y) * len); // 计算交点

        if (a <= ans && ans <= b && p <= ans && ans <= q) return {ans.x, ans.y}; // 判断交点是否落于两条线段内
        
        return {};
    }
};
```
