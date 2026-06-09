### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n<4)return n;
        vector<int> ans;
        ans.push_back(1);
        ans.push_back(2);
        for(int i=2;i<n;i++)ans.push_back(ans[i-1]+ans[i-2]);
        return ans[n-1];


        
    }
};
```