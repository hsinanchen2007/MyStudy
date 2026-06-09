### 解题思路
    有两种思路：一种是回溯法,但是会超过时间限制;一种是动态规划
    下面主要介绍动态规划的思路:
    特点：从后往前遍历
    if s[i]s[i+1]位于[10,26],则
        if s[i+1]=='0',则dp[i]=dp[i+1],i--; e.g "220"只能把"2"和"0"绑定在一起,在考虑前面的字符串
        else 则dp[i]=dp[i+1]+dp[i+2] e.g "112" 则dp["112"] = dp["12"]+dp["2"];
    if s[i]s[i+1]位于[10,26]外部,且s[i+1]!='0',则dp[i] = dp[i+1] e.g "33" 则只能有一种切分方式:"3"+"3"
    if s[i]s[i+1]位于[10,26]外部,且s[i+1]=='0',return 0; e.g "30" 则无法切分

### 代码

```cpp
class Solution {
public:
    void howNum(string& s, int i,int& num){
        if(i>=s.size()){
            num ++;
            return ;
        }
        if(s[i]=='0'){
            return ;
        }
        if(s[i]>='1'&&s[i]<='9'){
            howNum(s,i+1,num);
        }
        if((i+1)<s.size()){
            string str = s;
            stringstream sin(str.substr(i,2));
            int sum ;
            sin>>sum;
            if(sum>=10&&sum<=26){
                 howNum(s,i+2,num);
            }
        }
        return ;
    }
    int numDecodings(string s) {
        //回溯法:每次遍历有两种可能,取两个数字组成一个字符或取一个数字组成一个字符
        /*
        if(s.empty()){
            return 0;
        }
        int result  = 0;
        howNum(s,0,result);
        return result;
        */
        //动态规划
        //特点：从后往前遍历
        //if dp[i]dp[i+1]位于[10,26],则如果d[i+1]=='0',则dp[i]=dp[i+2],i--;否则,则dp[i]=dp[i+1]+dp[i+2]
        //if dp[i]dp[i+1]位于[10,26]外部,且d[i+1]!='0',则 d[i] = dp[i+1]
        //if dp[i]dp[i+1]位于[10,26]外部,且d[i+1]=='0',return 0;
        if(s.size()==0){
            return 0;
        }
        if(s.size()==1){
            if(s[0]>='1'&&s[0]<='9'){
                return 1;
            }else{
                return 0;
            }
        }
        if(s[0]=='0'){
            return 0;
        }
        vector<int>dp(s.size()+1,0);
        dp[s.size()-1]=1;
        dp[s.size()]=1;
        for(int i = s.size()-2;i>=0;i--){
            string s1 = s;
            stringstream sin(s1.substr(i,2));
            int sum ;
            sin>>sum;
            if(sum>=10&&sum<=26){
                if(s[i+1]=='0'){
                    dp[i]=dp[i+1];
                    if((i-1)>=0){
                        dp[i-1] = dp[i];
                        i--;
                    }
                }else{
                    dp[i]=dp[i+1]+dp[i+2];
                }
               
            }else{
                if(s[i+1]!='0'){
                   dp[i]=dp[i+1];
                }else{
                   return 0;
                }
            }
        }
        return dp[0];
    }
};
```