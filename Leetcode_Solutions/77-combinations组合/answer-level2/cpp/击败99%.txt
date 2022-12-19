如图：
![image.png](https://pic.leetcode-cn.com/7088a52afccab704984e4bb223160150226d08aa8d0ef41da343ac651bd01688-image.png)

注意剪枝！剪枝时考虑，当前cur中元素个数与递归到的位置，如果k>cur.size()+(n+1-i),就算把当前位置i以及之后所有元素都加到cur中，也凑不齐k个元素，所以可以不考虑这个部分。

```
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(ans,cur,n,k,1);
        return ans;
    }
    void dfs(vector<vector<int>> &ans,vector<int> &cur,int n,int k,int a){
        if(cur.size()==k){
            ans.push_back(cur);
            return;
        }   
        for(int i=a;i<=n-(k-cur.size()-1);i++){
            cur.push_back(i);
            dfs(ans,cur,n,k,i+1);
            cur.pop_back();
        }
    }
};
```




