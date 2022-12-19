### 解题思路
核心思路：开2个元素大小的vector，不断迭代，计算到n
注意：根据取余规则，(a+b)%c=(a%c+b%c)%c，每次迭代后就去一次模运算，保证n在很大时也可以顺利保存
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :7.7 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        vector<int>nums(2);
        nums[0]=0,nums[1]=1;
        for(int i=2;i<=n;i++){
            nums[i%2]=(nums[0]+nums[1])%1000000007;
        }
        return n%2==0?nums[0]%1000000007:nums[1]%1000000007;
    }
};
```