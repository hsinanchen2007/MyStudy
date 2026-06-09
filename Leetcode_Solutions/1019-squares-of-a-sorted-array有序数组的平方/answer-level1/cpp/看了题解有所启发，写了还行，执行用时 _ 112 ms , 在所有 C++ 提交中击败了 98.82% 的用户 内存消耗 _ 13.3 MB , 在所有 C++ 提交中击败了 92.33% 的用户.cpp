int L=A.size();
       int i=0,j=L-1,a=L-1;
        vector<int> ans=A;
        while(a>=0)
        {
            if(A[i]*A[i]>=A[j]*A[j])
            {
                ans[a]=A[i]*A[i];
                i++;
            }
            else if(A[i]*A[i]<A[j]*A[j])
            {
                 ans[a]=A[j]*A[j];
                j--;
            }
            a--;    
        }
        return ans;