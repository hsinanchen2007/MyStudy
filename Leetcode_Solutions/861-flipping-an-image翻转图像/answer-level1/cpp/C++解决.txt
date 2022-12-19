执行用时 :
20 ms
, 在所有 C++ 提交中击败了
82.77%
的用户
内存消耗 :
9.4 MB
, 在所有 C++ 提交中击败了
72.98%
的用户
```
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i=0;i<A.size();i++){
            reverse(A[i].begin(),A[i].end());
            for(int j=0;j<A[i].size();j++){
                if(A[i][j]==0)
                    A[i][j]=1;
                else
                    A[i][j]=0;
            }
        }
        return A;
    }
};
```

