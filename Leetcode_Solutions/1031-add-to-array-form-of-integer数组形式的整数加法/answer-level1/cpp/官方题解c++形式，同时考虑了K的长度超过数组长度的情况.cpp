class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int n=A.size();
        A[n-1]=A[n-1]+K;
        int k=0;
        for(int i=0;i<n;++i)
        {
            A[n-1-i]=A[n-1-i]+k;
            k=0;
            if(A[n-1-i]>=10)
               {
                k=A[n-1-i]/10;
                A[n-1-i]=A[n-1-i]%10;
               }
        }
        while(k!=0)
        {
            A.insert(A.begin(),k%10);
            k=k/10;
        }
        return A;
    }
};