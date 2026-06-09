- 首先确定上下界，下界定为4 * K, 上界为2 * INT_MAX
- 分别二分找到第一个阶乘末尾0个数大于K和K - 1的数
- 二者差值即为答案

```c
class Solution {
public:
    //返回n!末尾0的个数
    int zerosCnt(long long n) {
        int res = 0;
        while(n) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
    //找到其阶乘末尾0的个数大于k的第一个数
    long long loca(long long left, long long right, int k) {    
        while(left < right) {
            long long mid = (left + right) / 2; 
            if(zerosCnt(mid) > k) {
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
    int preimageSizeFZF(int K) {
        long long left = 4 * (long long)K, right = 2 * (long long) INT_MAX;
        //阶乘末尾0个数大于K的第一个数减去末尾0个数大于K-1的第一个数
        int res = loca(left, right, K) - loca(left, right, K - 1);
        return res;
    }
};
```