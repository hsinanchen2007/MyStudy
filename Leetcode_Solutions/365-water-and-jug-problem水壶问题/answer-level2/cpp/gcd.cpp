ax + by  = z 求是否有合理的解 ，x ，y 为系数
化简 a * t1 * k + b * t2 * k == z;
然后  k * (a * t1 + b * t2) = z;
也就是说z为 a 和 b 的gcd 的倍数
特判为 0 的时候 以及 使得等式成立的基本条件 x + y >= z
class Solution {
public:

    bool canMeasureWater(int x, int y, int z) {
               
        return z == 0 || ( x + y >= z && z % __gcd( x , y ) == 0);
    }
    
};