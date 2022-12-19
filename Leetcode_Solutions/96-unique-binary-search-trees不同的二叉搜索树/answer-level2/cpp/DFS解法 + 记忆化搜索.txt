### 解题思路

具体思路见注释
### 代码

```cpp
class Solution {
public:
    vector<int> result;
    int numTrees(int n) {
        if(n<=1) return 1;
        result.resize(n+1,0);
        result[0]=result[1]=1;
        return dfs(n); 
    }
    //dfs表示利用n个不重复的数构建二叉搜索树
    //可以假设就是1~n
    int dfs(int n)
    {
        //记忆化搜索
        if(result[n]>0) return result[n];
        int res=0;
        for(int i=1;i<=n;i++)
        {
            //分别以1~n中的每个数i作为根节点,构建二叉搜索树
            //1.将1~i-1作为左子树
            int left=dfs(i-1);  
            //2.将i+1~n作为右子树(这时候如果抛开根节点i,单独看利用i+1~n这些数构建BST,其种类数其实是和利用1~n-i构建BST是一样的)
            int right=dfs(n-i);  
            //当前以i为根节点构建BST,左右子树是独立的,所以用乘法表示i为根节点构建BST的种类
            res+=left*right;
        } 
        result[n]=res;
        return result[n];
    }
};
```