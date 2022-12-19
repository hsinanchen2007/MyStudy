```
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int s = A[0].size();
        for(int i=0; i<A.size(); i++)
        {
            if(s%2 == 0)
            {
                for(int j=0; j<s/2; j++)
                {
                    if(A[i][j] == A[i][s-j-1])
                    {
                        A[i][j] = !A[i][j];
                        A[i][s-j-1] = A[i][j];
                    }
                
                }
            }
            else
            {
                for(int j=0; j<=s/2; j++)
                {
                    if(A[i][j] == A[i][s-j-1])
                    {
                        A[i][j] = !A[i][j];
                        A[i][s-j-1] = A[i][j];
                    }
                
                }
            }
        }
        return A;
    }
};
```
