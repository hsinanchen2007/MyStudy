### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> reslt;
        if(numRows == 0) return reslt;
        vector<int> ans;    
        ans.push_back(1);
        reslt.push_back(ans);
        for(int i = 1;i < numRows;i++)
        {
            ans.insert(ans.begin(),0);
            for(int j = 0;j < i;j++) ans[j] = ans[j] + ans[j + 1];
            reslt.push_back(ans);
        }
        return reslt;
    }
};
```