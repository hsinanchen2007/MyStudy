主要特判+循环（可以不用判断是正负数以及末尾是否有0） 
执行用时 : 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户 内存消耗 : 6 MB , 在所有 C++ 提交中击败了 100.00% 的用户

```
class Solution {
public:
    long long reverse(long long x) {
        int max = 0x7fffffff, min = 0x80000000;
        long long result = 0;
        while(x)
        {
            result = 10*result + x % 10;
            x /= 10;
        }
        return result<max&&result>min?result:0;
    }
};
```
