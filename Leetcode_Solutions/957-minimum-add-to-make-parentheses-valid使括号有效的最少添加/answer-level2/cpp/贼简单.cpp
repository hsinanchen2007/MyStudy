class Solution {

    public:
    int minAddToMakeValid(string S) {
        int sum1=0,sum=0;
        for(int i=0;i<S.length();i++){
            if(S[i]=='(') sum1++;
            else sum1--;
            if(sum1<0){
                sum-=sum1;
                sum1=0;
            }
        }
        sum+=sum1;
        return sum;
    }
};