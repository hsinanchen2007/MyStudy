### 解题思路

如果我们一开始想不起来如何用dp去做，我们尝试穷举
1.我们可以判断出一个字符串是否符合”有效括号“ 的判断 (利用栈)。
2.我们可以穷举所有情况 

#### 主要逻辑：
----
    for(int i=0;i<n;i++){
        for(int j=i+2;j<=n;j+=2){
            if(isOk(s,i,j)){
                tmpMax = max(tmpMax,j-i); 
            }
        }
    }
----
    bool isOk(string s,int k,int len){
        
        stack <char> stackTmp;
        for(int i=k;i<len;i++){
            if(s[i] == '(' ){
                stackTmp.push(s[i]);
            }else if(!stackTmp.empty() && stackTmp.top() == '('){
                stackTmp.pop();
            }else{
                return false;
            }
        }
        return = stackTmp.empty();
    }

我们可以看到 在计算是否 ”有效“（isOk） 的时候，是有重复项的 比如 isOk(0,4)  在计算 isOk(0,6) 的时候会被重新计算。
但是如何推导 子问题呢？
设dp[n] 表示在 0-n 的范围内最大的 ”有效括号“长度。
dp[0] = 0
dp[i] 如何求得？
首先如果 当前 s[i] == ')' 才有可能 行程 有效的 字符串
此时存在两种情况
....()  =>  dp[i] = dp[i-2] + 2 //因为 dp[i-1]一定不符合
....))  =>  ？

第二种情况是比较复杂的 如下
(...)((xxx))
由两部分构成  dp[i-1] + 2 标示双重括号包围的长度
第一部分则可以标示未 dp[i-dp[i-1]-2] 因为 dp[i-1]是 中间小括号组成的长度 i-dp[i-1] -1 就是与 当前 ）组成组合的 字符（，在此基础上 再 -1 就是所有第一段的长度 
综上所述 状态方程为
dp[i] = dp[i-2]+2                       { s[i] == ')' && s[i-1] == '(' }
dp[i] = dp[i-1]+2 + dp[i-dp[i-1]-2]     { s[i] == ')' && s[i-dp[i-1]-1]]== '('}

既然有了状态方程，朴素算法中的 内循环可以改为此方程即可

### 代码

```cpp
class Solution {
public:
    
    int longestValidParentheses(string s) {
        return longestTwo(s);
    }
    int longestTwo(string s){
        vector<int> dp(s.length(),0);
        int n = s.length();
        int tmpMax = 0;
        for(int i=1;i<n;i++){
            //只有 ) 的情况才可能组成配对
            if(s[i] == ')'){
                //... () 的情况
                if(s[i-1] == '(' ){
                    dp[i] = (i-2>=0 ? dp[i-2] :0)+2;
                    //...)) 的情况 dp[i-1] 标示上一个 可以配对成功的长度  i-dp[i-1]-1 标示 与当前 ）配对 的 （ 
                }else if(i-dp[i-1]-1 >=0 && s[ i-dp[i-1]-1] == '('){
                    dp[i] = (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + dp[i - 1] + 2;
                  
                }
            }
            tmpMax = max(tmpMax,dp[i]);
        }
        return tmpMax;
    }
    
};
```