### 解题思路
还挺简单的，只要掌握了回溯的技巧或者多刷刷回溯的题应该没啥问题

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tmp;
        if(n==0)
            return res;
        if(k==0)
        {
            res.push_back(tmp);
        }
        help(res,tmp,n,k,1);
        return res;
    }
    void help(vector<vector<int>>& res, vector<int>& tmp,int n,int k,int t_num)
    {
        // for(auto w:tmp)
        //     cout<<w<<" ";
        // cout<<endl;
        if(k==0&&n==0)
        {
            res.push_back(tmp);
            return;
        }
        if(k<0||n<0)
            return;
        for(int i=t_num;i<=9;i++)
        {
            tmp.push_back(i);
            help(res,tmp,n-i,k-1,i+1);
            tmp.pop_back();
        }
    }
};
```