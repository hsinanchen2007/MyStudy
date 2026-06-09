![image.png](https://pic.leetcode-cn.com/96f1fe0c88b16bb9381aa7b6d8c92fb0162484665793a4ccb4461bc88f52eec8-image.png)
解题思路：和左上比较即可。
```
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if(matrix.size()==1 || matrix[0].size()==1) return true;
        for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[0].size(); j++){
                if(matrix[i][j]!=matrix[i-1][j-1]) return false;
            }
        }
        
        return true;
    }
```

