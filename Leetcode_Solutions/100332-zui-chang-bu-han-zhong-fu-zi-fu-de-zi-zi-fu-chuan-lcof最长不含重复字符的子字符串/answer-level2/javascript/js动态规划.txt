### 解题思路
    let dp=[];   //记录到当前索引下无重复字符最长的长度
    let i=0;//记录无重复字符的开始位置
    let j=1;//记录无重复字符的结束位置(包含)

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    if(s.length===0)return 0;
    let dp=[];   //记录到当前索引下无重复字符最长的长度
    let i=0;//记录无重复字符的开始位置
    let j=1;//记录无重复字符的结束位置，包含
    dp[0] = 1;
    while(j<s.length){
        let k=s.slice(0,j).lastIndexOf(s[j]);
        if(k  < i){
            //不包含
            dp[j] = dp[j-1] > j-i+1? dp[j-1] : j-i+1;
            
        }else{

            i = k+1;
            dp[j] = dp[j-1] > j-i+1? dp[j-1] : j-i+1;

        }
        j++;
    }
    //console.log(dp)
    return dp.pop();


};
```