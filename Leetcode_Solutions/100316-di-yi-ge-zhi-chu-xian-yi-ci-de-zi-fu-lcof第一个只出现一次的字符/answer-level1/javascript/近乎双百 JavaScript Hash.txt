### 解题思路
![image.png](https://pic.leetcode-cn.com/4b8c46f5af236b6e52869e8c72fcd169cf58713b17f08df7f340dd1b8ab9b79d-image.png)


### 代码

```javascript
/**
 * @param {string} s
 * @return {character}
 */
var firstUniqChar = function(s) {
    if(s === '') return ' ';
    const len = s.length;
    let hashObj = {};//由于js没有hashMmap，所以要自己创建
    for(let i = 0; i < len; i ++) {
        if(hashObj[s[i]] === undefined) {
            hashObj[s[i]] = 1;//出现一次
        } else {
            hashObj[s[i]] = 0;//出现多次
        }
    }
    for(let item in hashObj) {
        if(hashObj[item] === 1) {
            return item;
        }
    }
    return ' '
};
```