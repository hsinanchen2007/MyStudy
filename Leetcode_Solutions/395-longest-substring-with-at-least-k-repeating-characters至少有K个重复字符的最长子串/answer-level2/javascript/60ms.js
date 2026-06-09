### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var longestSubstring = function(s, k) {
    if(k<=1){ return s.length; }
    else if(s.length < k){ return 0; }
    const map = {};
    // 计算每种字符出现次数
    for(let i=0; i<s.length; i+=1){
        map[s[i]] ? map[s[i]]+=1 : map[s[i]] = 1;
    }
    // 收集不满足的字符
    const keys = [];
    for(key in map){
        if(map[key] < k){
            keys.push(key);
        }
    }
    return keys[0] 
    ? Math.max(// 分割求最大
        ...s.split(new RegExp(keys.join('|'), 'g'))
            .map(x => longestSubstring(x, k))
        )
    : s.length;
};
```