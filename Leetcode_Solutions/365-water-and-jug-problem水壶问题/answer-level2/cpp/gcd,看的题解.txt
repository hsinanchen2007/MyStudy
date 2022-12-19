```
class Solution {
public:
    /*
        https://leetcode.com/problems/water-and-jug-problem/discuss/83720/Clear-Explanation-of-Why-Using-GCD
        把问题想成，只能通过x,y来对一个大池子里的水进行  pour in or out.
        即 z = m * x + n * y
        4 = (-2) * 3 + 2 * 5
        其实 3 4 5 的最优解最后就是 进行了2次倒出3，2次装满5 达到的。
        然后一个数学定理
        
        We can always find a and b to satisfy ax + by = d where d = gcd(x, y)

        为什么是 GCD，这样想。
    */
    int gcd(int x,int y){
        return y == 0? x:gcd(y,x %y);
    }
    bool canMeasureWater(int x, int y, int z) {
        return z == 0|| (z <=x +y && z % gcd(x,y)==0 );

    }
};


```
