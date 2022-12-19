### 解题思路
这道题直觉告诉我不能从1开始不断递增平方去与x比较，以此得到结果
这道题使用二分法，
先找到x处于[l,r]的范围，然后再[l,r]中使用二分法找到结果
关键在于找[l,r]的范围，通过(((2^2)^2)...)的方式找到范围，复杂度也为O(logn)
比如x = 100
2 -> 4 -> 16 -> 256，可以得到范围[4,16]，然后再[4,16]中二分法找寻结果即可

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x <= 3) return 1;
        long l = 2;
        while(l*l*l*l < x){
            l = l*l;
        }
        //l < x^(1/2) < l^2
        long r = l*l;
        while(l <= r){
            long mid = (l+r)/2;
            if(mid*mid <= x && (mid+1)*(mid+1) > x){
                return mid;
            }else if(mid*mid < x){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return l;
    }
};
```

### 结果
执行用时 : 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户 
内存消耗 : 5.8 MB , 在所有 C++ 提交中击败了 100.00% 的用户