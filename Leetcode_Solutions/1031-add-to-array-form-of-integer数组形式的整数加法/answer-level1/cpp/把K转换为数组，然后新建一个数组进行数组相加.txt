class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> k;
        while(K!=0)
        {
            k.push_back(K%10);
            K=K/10;
        }
        reverse(k.begin(),k.end());
        int n=max(A.size(),k.size())+1;
        vector<int> a(n,0);
        int n1=A.size();
        int n2=k.size();
        int flag=0;
        for(int i=0;i<n;++i)
        {
            if((n1-1-i>=0)&&(n2-1-i>=0))
                a[i]=A[n1-i-1]+k[n2-i-1]+flag;
            if((n1-1-i<0)&&(n2-1-i>=0))
                a[i]=k[n2-i-1]+flag;
            if((n1-1-i>=0)&&(n2-1-i<0))
                a[i]=A[n1-i-1]+flag;
            if((n1-1-i<0)&&(n2-1-i<0))
                a[i]=flag;
            flag=0;
            if(a[i]>=10)
                {
                    flag=1;
                    a[i]=a[i]%10;
                }
        }
        reverse(a.begin(),a.end());
        if(a[0]==0)
        a.erase(a.begin());
        return a;
    }
};