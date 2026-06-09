```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len == 0) return 0;
        vector<int> pos(128,-1), //用来记录字符最近一次出现的位置
                    dp(len,0); //动态规划数组，
                    //特别的dp[i]表示以s[i]为结尾所能构成的最长无重复字符串
        dp[0] = 1; pos[s[0]] = 0; //初始化
        int ret = 1, //返回值
            ptr = 0; //做为游标使用 
        for(int i=1; i<len; i++){
            if(pos[s[i]] < ptr){ //证明在ptr到i间，没有出现相同的元素
                dp[i] = dp[i-1] + 1;
            }else{ //证明s[i] 在 1~i-1之间出现过
                ptr = max(ptr,pos[s[i]]);//更新ptr的值，是得在(ptr,i)之间没有相同的字符
                if(s[ptr] == s[i]){ //
                    dp[i] = i - ptr;
                    ptr++; //调整ptr的值
                }else{
                    dp[i] = i - ptr + 1;
                }
            }
            pos[s[i]] = i; //更新字符最近出现的位置信息
            ret = max(ret,dp[i]);
        }
        return ret;
    }
};
```
