    int climbStairs(int n){

        if(n == 1) return 1;

        int s0,s1,i;
        int s[1024] = {0};
        s[0] = 1;
        s[1] = 1;
        for(i=2;i<=n;i++){
            s[i] = s[i-1] + s[i-2];
        }
        return s[--i];
    }