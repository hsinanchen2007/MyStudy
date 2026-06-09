### 解题思路
依次枚举每个数从哪个位置选
1 2 3 4
1 12 123 1234 13 14 
2
3 
4

### 代码

```cpp
class Solution {
public:
    vector<vector<int>>ans;
    vector<int>path;

    vector<vector<int>> combinationSum3(int k, int n) {
    //依次枚举每个数从哪个位置选  
        dfs(k, 1, n);
        return ans;
    }

    //dfs(枚举到了第几个数字，开始枚举的位置，当前选择的所有数的和)
    void dfs(int k , int start , int n)
    {
        if(!k)
        {
            if(!n)ans.push_back(path);
            return;
        }
        for(int i = start; i <= 10 - k; i++)
        {
            path.push_back(i);
            dfs(k - 1, i + 1, n - i);
            path.pop_back();
        }
        return;
    }
};
```