```
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int len= A.size();
        int dp1[len]; //the times needed to make A, B sorted and A[i] >= B[i]
        int dp2[len]; //the times needed to make A, B sorted and A[i] <= B[i]
        
        if(A[0]>B[0]){
            dp1[0]=0;
            dp2[0]=1;
        }
        else if (A[0]<B[0])
        {
            dp1[0]=1;
            dp2[0]=0;
        }
        else{
            dp1[0]=0;
            dp2[0]=0;
        }
        
        for (int i=1; i< len; i++){
            int min_cur= min(A[i], B[i]);
            int max_pre= max(A[i-1], B[i-1]);
            if (min_cur> max_pre){
                dp1[i]=min(dp1[i-1], dp2[i-1]);
                dp2[i]=min(dp1[i-1], dp2[i-1]);
            }
            else{
                dp1[i]=dp1[i-1];
                dp2[i]=dp2[i-1];
            }
            if (A[i]<B[i])
                dp1[i]+=1;
            else if (A[i]>B[i])
                dp2[i]+=1;
        }
        
        return min(dp1[len-1], dp2[len-1]);                
    }
};

```

