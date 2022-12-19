其实可以不用新的vector的
当A[i]>B[j]时,只需保存A[i]即可
```
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        if(n==0) return;
        vector<int> t(A);
        A[m]=0x7fffffff;
        B.push_back(0x7fffffff);
        int i=0,j=0;
        int id =0;
        while(id<m+n){
            if(A[i]<=B[j]){
                t[id++] = A[i++];
            }
            else{
                t[id++] = B[j++];
            }     
        } 
        A=t;
        B.pop_back();
    }
};
```