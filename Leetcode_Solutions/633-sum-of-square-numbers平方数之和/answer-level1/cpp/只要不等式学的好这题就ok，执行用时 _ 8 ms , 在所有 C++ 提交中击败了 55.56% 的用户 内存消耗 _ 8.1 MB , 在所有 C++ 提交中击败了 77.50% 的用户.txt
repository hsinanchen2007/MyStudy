class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long i=-sqrt(c);i<=0;i++){
            long long a=c-i*i;
             long long b=sqrt(a);
            if(b==sqrt(a))return true;
        }
        return false;
    }
};