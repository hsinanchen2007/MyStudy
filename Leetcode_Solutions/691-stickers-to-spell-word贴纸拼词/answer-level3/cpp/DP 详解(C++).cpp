### 解题思路
假设
```
target="hat"
sticker1="haha"
sticker2="tata"
```

**总共有1<<target.size()种状态**,从开始一张没贴的000到最后全部贴好的111,
**第一次**:
000->我们可以用sticker1截取a,h用来拼,即110
也可以用sticker2截取t,a拼,即011
所以状态110和011所花贴纸均为1:
011->1
110->1
其余地方均为-1.
**第二次**:
向后遍历,遇到-1说明这些地方没有可用的贴纸直接跳过,直到遇到不为-1.
011->此处不为-1,继续截取贴纸拼写,发现可以从haha截取h拼,所以
111->2(tata+haha).
大致过程就是这样,接下来可以享用代码,加深理解

### 代码

```cpp
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int m=target.size();
        vector<int>dp(1<<m,-1);
        dp[0]=0;//长度为0无需贴纸.
        for(int State=0;State<(1<<m);State++){
            if(dp[State]==-1)//无可用贴纸直接跳过
            continue;
            for(string sticker:stickers){
                int initialState=State;//在当前状态下往最终状态继续拼
                for(char ch:sticker){//将贴纸的字符截取
                    for(int i=0;i<m;i++){
                        if((initialState>>i)&1==1)//之前已经贴好,则跳过
                        continue;
                        if(ch==target[i]){//否则就将当前字符取用,换下一个字符
                            initialState|=(1<<i);
                            break;
                        }
                    }
                }
                if(dp[initialState]==-1||dp[initialState]>dp[State]+1)//自己思考思考
                dp[initialState]=dp[State]+1;
            }
        }
        return dp[(1<<m)-1];
    }
};
```
参考[此处](https://leetcode.com/problems/stickers-to-spell-word/discuss/434762/Java-DP-solution-with-explanation),如有解释不到位,还请纠正.