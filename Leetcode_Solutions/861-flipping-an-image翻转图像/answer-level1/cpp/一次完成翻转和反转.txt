```
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int tmp,i,j,k;
        for(i=0; i<A.size(); i++)
        {
            for(j=0, k=A[0].size()-1; j<=k; j++, k--)
            {
                tmp = !A[i][j];
                A[i][j] = !A[i][k];
                A[i][k] = tmp;
            }
        }
        return A;
    }
};
```
