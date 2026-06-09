这个题就是单纯的跳台阶的翻版，只不过是加了条件限制，边界处理要画点时间。
- dfs
单纯的dfs用时大概1800ms，下面是带记忆的递归，代码很好懂，看注释就差不多明了了。

```
// class Solution {
// public:
//     int res=0;
//     void helper(string &s,int index,unordered_map<int,int>& map){
//         if(index>=s.size()){//结束条件
//             res++;
//             return;
//         }
//         if(map[index]){//如果字典中能查到的话，就不必继续进行递归。可以节约大量时间（划重点）
//             res+=map[index];
//             return;
//         }
//下面的两个if主要是对当前字符是否为0做处理
//         if(s[index]!='0')//不为0向后递归，跳台阶每次跳一阶
//             helper(s,index+1,map);
//
//         if(index+1<s.size()&&(s[index]<='2'&&s[index+1]<='6'||s[index]=='1')&&s[index]!='0')//跳台阶每次跳2阶
//             helper(s,index+2,map);
//         map[index]=res;//记录当前index对应的结果
//     }
//     int numDecodings(string s) {
//         unordered_map<int,int>map;
//         helper(s,0,map);
//         return res;
//     }
// };
```
- dp

```
class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')return 0;//特例
        vector<int>dp(s.size()+1,0);
        dp[0]=1;
        for(int i=0;i<s.size();i++){
            dp[i+1]=s[i]=='0'?0:dp[i];//跳一阶
            if(i>0&&((s[i-1]=='2'&&s[i]<='6')||s[i-1]=='1')){//跳二阶
                dp[i+1]+=dp[i-1];
            }
        }
        return dp[s.size()];
    }
};
```
以上代码其实只用到前两个值，所以可以用两个int解决。