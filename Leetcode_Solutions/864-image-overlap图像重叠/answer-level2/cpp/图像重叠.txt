```
    int f(int x, int y, vector<vector<int>> &A, vector<vector<int>> &B){
        int m = A.size();
        int n = A[0].size();
        // A.右下角位于pos(x,y)
        int ansA = 0;
        for(int i=0; i<=x; i++){
            for(int j=0; j<=y; j++){
                ansA += A[m-x-1+i][n-y-1+j]*B[i][j];
            }
        }
        // B.右下角位于pos(x,y)
        int ansB = 0;
        for(int i=0; i<=x; i++){
            for(int j=0; j<=y; j++){
                ansB += A[i][j]*B[m-x-1+i][n-y-1+j];
            }
        }
        return max(ansA, ansB);
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        int m = A.size(); if(m==0) return 0;
        int n = A[0].size(); if(n==0) return 0;
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = max(ans, f(i, j, A, B));
            }
        }
        return ans;
    }
```