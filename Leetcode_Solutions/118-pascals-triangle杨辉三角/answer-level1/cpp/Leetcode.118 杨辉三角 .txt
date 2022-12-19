### 解题思路
记住一点：从第三行开始 i--行 j-th 数
    ans[i][j] = ans[i-1][j-1] + ans[i-1][j]

### 代码

```cpp
/*class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = {};
        vector<int> pre;
        for(int i = 1; i <= numRows; i++)
        {
            vector<int> now = {};
            if(i <= 2)
            {
                now.push_back(1);
                if(i == 2)
                    now.push_back(1);
            }
            else
            {
                for(int j = 0; j < i; j++)
                {
                    now.push_back(1);
                    if(j!=0 && j!=i-1)
                        now[j] = pre[j-1] + pre[j];
                }
            }    
            pre = now;
            ans.push_back(now);
        }
        return ans;
    }
};*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i = 0; i < numRows; i++)
            //vector 初始化，i+1 个 1
            ans[i] = vector<int>(i+1, 1);
        
        if(numRows < 2)   return ans;
        
        for(int i = 2; i < numRows; i++)
        {
            for(int j = 1; j < ans[i].size()-1; j++)
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
        return ans;
    }
};





```