class Solution {
public:
    void xialv(vector<int>& A,int i){
        if(2*i+1>=A.size())
            return;
        if(2*i+2>=A.size()){
            if(A[i]>A[2*i+1]){
                swap(A[i],A[2*i+1]);
                xialv(A,2*i+1);
            }
        }
        else{
            if(A[2*i+1]>A[2*i+2]){
                if(A[i]>A[2*i+2]){
                    swap(A[i],A[2*i+2]);
                    xialv(A,2*i+2);
                }
                else if(A[i]>A[2*i+1]){
                    swap(A[i],A[2*i+1]);
                    xialv(A,2*i+1);
                }
            }
            else{
                if(A[i]>A[2*i+1]){
                    swap(A[i],A[2*i+1]);
                    xialv(A,2*i+1);
                }
                else if(A[i]>A[2*i+2]){
                    swap(A[i],A[2*i+2]);
                    xialv(A,2*i+2);
                }
            }
        }

    }
    int largestSumAfterKNegations(vector<int>& A, int K) {
        for(int i=A.size()/2;i>=0;i--)
            xialv(A,i);
        while(K>0){
            K--;
            A[0]*=-1;
            xialv(A,0);
        }
        int sum=0;
        for(int i=0;i<A.size();i++)
            sum+=A[i];
        return sum;
    }
};