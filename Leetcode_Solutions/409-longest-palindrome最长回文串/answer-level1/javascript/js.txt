### 解题思路
此处撰写解题思路
![屏幕快照 2020-03-19 上午11.22.00.png](https://pic.leetcode-cn.com/3ff6e81fb88533be51246780556a70eb4d4ec6304d10644299f3f61a2b36d666-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-19%20%E4%B8%8A%E5%8D%8811.22.00.png)

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    let obj = {}
    for(let i=0; i<s.length; i++) {
        if(!obj[s[i]]) {
            obj[s[i]] = 1
        }else {
            obj[s[i]] += 1
        }
    }
    let count = 0
    for(let index in obj) {
        if(obj[index]%2 === 0) {
            count += obj[index]
        }else if(obj[index] > 2){
            count += obj[index] - 1
        }
    }
    if(count < s.length) {
        count++
    }
    return count
};
```

