### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int ans[38]={0,1,1};
    int tribonacci(int n) {
        if(n<=0)return 0;
        if(ans[n])return ans[n];
        ans[n]=tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
        return ans[n];
    }
};
```