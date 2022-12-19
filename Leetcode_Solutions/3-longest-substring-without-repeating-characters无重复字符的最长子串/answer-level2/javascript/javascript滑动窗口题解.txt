### 解题思路
滑动窗口

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let i = 0;
    let j = 0;
    let obj = {};
    let max = 0;
    while(j<=s.length-1){
        if(obj[s[j]]==null||obj[s[j]]<i){        
            max = Math.max(max,j-i+1);
        }
        else{
            i=obj[s[j]]+1;            
        }
        obj[s[j]] = j;
        j++;        
    }
    return max;
};
```