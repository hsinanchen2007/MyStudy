class Solution {
public:
    int cuttingRope(int n) {
        if(n<=3)return n-1;
        if(n==4)return 4;
        int a=n/3;
        if(n%3==0)return pow(3,a);
        else if(n%3==1){
            return pow(3,a-1)*4;
        }else{
            return pow(3,a)*2;
        }
    }
};