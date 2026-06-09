两行两行比较
执行用时 :
16 ms
, 在所有 C++ 提交中击败了
83.99%
的用户
内存消耗 :
9.6 MB
, 在所有 C++ 提交中击败了
84.35%
的用户
```c++ []
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size()-1;i++)
            for(int j=0;j<matrix[0].size()-1;j++)
                if(matrix[i][j]!=matrix[i+1][j+1])
                    return 0;
        return 1;
    }
};
```

