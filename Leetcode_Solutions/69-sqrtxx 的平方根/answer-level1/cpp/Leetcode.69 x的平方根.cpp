### 解题思路
本题思路与别的解答中的二分法没有差异，只是我在写的时候觉得有一点需要弄清楚
首先1.记住一条x的平方根肯定不大于 x/2 + 1
其次2.代码的最后为什么要返回 a, 本文中设置了a为较大的数，b为较小的数进行二分，平方根必定落在n~n+1之间，倒数第二次循环时a = n+1, b = n,此时我们知道平方根为n.x，取整后为n，但是这时mid = (n+1+n)/2 = n;mid^2必然会小于x,此时b = n+1,随后执行最后一次循环，mid = n+1,必然会导致ans > x,所以这个代码是会以 a = mid - 1,为结尾跳出循环的，且平方根即为a

### 代码

```cpp
class Solution {
public:
    //方法一：记住x的平方根肯定不大于 x/2 + 1,二分法解决
    int mySqrt(int x) {
        long long int a = x/2 + 1;
        long long int b = 0;
        long long int mid;
        while(b <= a)
        {
            mid = (a+b)/2;
            long long int ans = mid * mid;
            if(ans == x)
                return mid;
            if(ans > x)
                a = mid - 1;
            else
            {
                b = mid + 1;//落在此处1
            }
        }
        return a;
    }
};
```