class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        int count3{0};
        while(n>4){
            n = n-3;
            count3 ++;
        }
        return pow(3, count3) * n;
    }
};