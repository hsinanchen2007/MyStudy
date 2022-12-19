### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> dp(arr.size(),0);
        int max1=-1;
        for(int i=arr.size()-1;i>=0;i--){
            dp[i]=max1;
            max1=max(max1,arr[i]);
        }
        return dp;
    }
};
```