### 解题思路
动态规划的四步
1. 找状态 回文串为s
    则将回文串s，去掉一头一尾 仍然是回文串
2. 转移方程
    isPail[j][i] == true while isPail[j+1->i-1] == true AND s[j] == s[i]
    s[i->j] 为回文串，当且仅当 内部子串为回文串，以及 s[j] = s[i]
3. 边界条件以及初始值
    边界
    当 i - j <= 2 的时候，s[j] == s[i]  即可推出   S[j->i] == true  （aba , aa） 像这种相邻或者间隔一个字符的只要首尾相     同就是回文串
    初始值 
    第一个回文串 是字符串的首项，max = s.charAt(0)
4. 计算顺序
    从头向后比较，

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    if(s.length == 1){
        return s;
    }
    let isPail = []
    for(let i = 0; i < s.length; i++){
        isPail[i] = [];
    }
    let max = s.charAt(0)
    let i,j;
    for(i=1 ; i<s.length; i++){
        for(j=0; j<s.length-1; j++){// j<s.length-1，防止isPail数组变为 isPail[s.length][i-1] 导致溢出
            if(i==j){
                j = 0;
                break; //=如果 i=j 或者 j == length - 1,  j=0 结束这次循环
            }
            if(s[i] == s[j]){ //如果s[i] == s[j]，检测中间的串是不是回文串,或者中间只有只有一个字符，或者相邻
                if(isPail[j+1][i-1]  && isPail[j+1][i-1] == true || i-j <= 2 ){
                    //如果中间的串是回文串，或者中间只有一个串
                    isPail [j][i] = true
                    if(i-j+1 >= max.length){//如果当前回文子串长度最大，则更新最大回文串
                        max = s.slice(j,i+1);
                    }
                }
            }
        }
    }
    return max; 
};
```