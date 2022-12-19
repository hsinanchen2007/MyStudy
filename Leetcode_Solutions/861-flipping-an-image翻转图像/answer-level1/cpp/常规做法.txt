```
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i=0;i<A.size();i++){
            int j=0;
            while(j<=(A[i].size()-1)/2){
                int tmp=A[i][j];
                A[i][j]=A[i][A[i].size()-1-j];
                A[i][A[i].size()-1-j]=tmp;
                j++;
            }
        }
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[i].size();j++){
                A[i][j]=((A[i][j]==0)?1:0);
            }
        }
        return A;
    }
};
```
