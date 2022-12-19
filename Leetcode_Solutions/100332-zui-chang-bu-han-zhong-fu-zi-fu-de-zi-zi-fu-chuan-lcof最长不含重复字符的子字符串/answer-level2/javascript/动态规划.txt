### 解题思路
用一个map存储已经遍历过的字符串的最新值
dp储存当前字符串对应的最长的无重复字符的长度

for(遍历s){
    if(已经遍历过当前的字符){
        let dis = 当前字符和之前字符的距离        
            if(dis大于前一个字符所对应的最大长度，即超过这个范围)
            dp[i + 1] = dp[i] + 1;
        else
            dp[i + 1] = dis;
    }
    else{
        dp[ i + 1] = dp[i] + 1;
    }
    更新max值
    更新map
}



### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let max = 0;
    let map = new Map();
    let dp = new Array(s.length +1 ).fill(0);
    for(let i = 0; i < s.length ; i++){
        let char = s[i];
        if(map.has(char)){
            let dis = i - map.get(char);
            if(dis > dp[i]){
                dp[i+1] = dp[i] + 1;
            }else{
                dp[i+1] = i - map.get(char)
            }
        }else{
            dp[i+1] = dp[i] + 1;
        }
        if(max < dp[i+1]){
            max = dp[i+1];
        }
        map.set(char,i);
    }
    return max;
};
```