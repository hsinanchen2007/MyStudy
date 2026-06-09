class Solution {
public:
    // 能和前面的结合，f(n)=f(n-1)+f(n-2)  不能f(n)=f(n-1)
    int translateNum(int num) {
        string s = to_string(num);
        int len = s.size();
        if(len==1)
            return 1; // 只有一个数字
        int* dp = new int[len];
        dp[0] = 1;
        if(jiehe(s[0], s[1]))
            dp[1] = 2;
        else
            dp[1] = 1;
        for(int i=2; i<len; ++i){
            if(jiehe(s[i-1], s[i]))
                dp[i] = dp[i-1] + dp[i-2];
            else
                dp[i] = dp[i-1];
        }
        return dp[len-1];
    }
    //当前位置的的数字能不能和前面的字符结合
    bool jiehe(char a, char b){
        if(a=='0')
            return false;
        int x = 10*(a-'0')+(b-'0');
        if(x<26)
            return true;
        return false;
    }
};