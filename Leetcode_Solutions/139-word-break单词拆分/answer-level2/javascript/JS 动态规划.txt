### 解题思路
此处撰写解题思路
1. 找状态
    要想使 s 可以拆分，则拆分掉 s中的最后一个单词(长度为 x )之后，s(0, n-x)仍然是一个成立的单词组，
2. 转移方程
```
            if (s.slice(i,j+1) 在字典中) && (dp[i-1] == true)  
                    dp[j] == true;
```
3. 起始条件与边界问题
            s[i-1]  i-1可能 < 0
            所以应该增加一个      
```
    if (s.slice(i,j+1) 在字典中) && (dp[i-1] == true || i-1 < 0)
    dp[j] == true;
```
4. 顺序 从小到大

        
### 代码

```javascript
/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {boolean}
 */
var wordBreak = function(s, wordDict) {
    let dp = [];
    if(wordDict.length == 0){
        return false;
    }
    if(s.length == 1){
        if(wordDict.indexOf(s) == -1){
            return false;
        }else{
            return true;
        }
    }
    let len = s.length;
    for(let i = 0; i<len;i++){
        for(let j = i; j<len; j++){
            if(wordDict.indexOf(s.slice(i,j+1)) != -1){
                if(dp[i-1] == true || i-1 < 0){
                    dp[j] = true;
                }
            }
        }
    }
    return dp[len-1] ? true : false
};
```