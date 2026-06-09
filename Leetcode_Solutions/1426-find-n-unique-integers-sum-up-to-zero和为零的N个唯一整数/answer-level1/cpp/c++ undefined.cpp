### 解题思路
实在搞不清这道题出来的意义是啥。。。
为啥有100多篇题解。。。。

### 代码

```cpp
class Solution {
public:
    vector<int> sumZero(int n) {
        if(n == 0) return vector<int>();
        vector<int> ans(n, 0);
        int sum = 0;
        for(int i = 0; i < n-1; i++){
            ans[i] = i;
            sum += i;
        }
        ans[n-1] = -sum;
        return ans;
    }
};
```