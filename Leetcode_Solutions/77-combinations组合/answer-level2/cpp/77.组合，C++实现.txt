### 解题思路
使用回溯的策略

### 代码

```cpp
class Solution {
public:
    int n;
    int k;
    void Backtrack(int first,vector<int>&curr,vector<vector <int >> &res)
    {
       if(curr.size()==this->k)
       {
           res.push_back(curr);
       }
       for(int i=first;i<this->n+1;i++)
       {
           curr.push_back(i);
           Backtrack(i+1,curr,res);
           curr.pop_back();
       }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector <int >> res;
        vector<int>curr;
		this->n=n;
        this->k=k;
        Backtrack(1,curr,res);
		return res;
    }
};
```