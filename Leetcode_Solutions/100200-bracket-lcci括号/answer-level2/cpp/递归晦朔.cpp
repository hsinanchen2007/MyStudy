### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        dfs("",0,0,n);
        return ans;
    }
    void dfs(string temp,int left,int right,int n){
        if(temp.length()==2*n){
            ans.push_back(temp);
            return;
        }
        if(left<n){
            dfs(temp+'(',left+1,right,n);
        }
        if(right<left){
            dfs(temp+')',left,right+1,n);
        }
    }
};
```