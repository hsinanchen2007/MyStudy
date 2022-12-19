![image.png](https://pic.leetcode-cn.com/62a4f8e5941f03a2b021622fdc07a434beb105786340e327bc074568867d7ec1-image.png)
解题思路：传入的矩阵为ixj，新建jxi的矩阵，res[j][i] = A[i][j]，返回res即可。
```
    vector<vector<int>> transpose(vector<vector<int>>& A) {

        vector<vector<int>> res;
        res.resize(A[0].size());

        for(int k = 0;k<res.size();++k)
            res[k].resize(A.size());

        for(int i = 0;i<A.size();++i)
            for(int j = 0;j<A[0].size();++j){
                res[j][i] = A[i][j];
            }
            
        return res;
    }
```

