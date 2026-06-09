class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans =1;
        int si=0;
        for(int i=1;i<N&&si<N;i++){
            si+=i;
            if((N-si)>=(i+1)&&(N-si)%(i+1)==0){
                ans+=1;
            }
        }
        return ans;
    }
};