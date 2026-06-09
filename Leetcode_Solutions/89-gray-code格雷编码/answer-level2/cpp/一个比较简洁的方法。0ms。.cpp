构建一棵树，对于所有节点，若为左孩子，则它的左右孩子分别为0和1，若为右孩子，则它的左右孩子分别为1和0，
初始节点的左右孩子为0和1， 树的深度为n。
然后DFS这颗树，每次到达叶子节点时将结果加入到vector中。


```

class Solution {
public:
    vector<int> vec;
    void dfs(int depth, int sum, int l, int r){
        if(depth==0){
            vec.push_back(sum);
            return;
        }

        dfs(depth-1, sum*2+l, 0,1);
        dfs(depth-1, sum*2+r, 1, 0);
    }
    vector<int> grayCode(int n) {
        dfs(n,0,0,1);
        return vec;
    }
};
```
