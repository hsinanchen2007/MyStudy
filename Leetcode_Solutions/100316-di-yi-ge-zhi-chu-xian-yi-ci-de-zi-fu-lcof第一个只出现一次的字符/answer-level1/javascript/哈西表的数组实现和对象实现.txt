### 超简单的数组、字符串索引indexof和lastindexof方法
```
代码块
```

### 对象做哈西表

```
/**
 * @param {string} s
 * @return {character}
 */
var firstUniqChar = function(s) {
    const len = s.length;
    let hash = {};
    for(let i = 0; i < len; i++) {
        // 若哈西表键值对应数没有值，赋1
        if(hash[s[i]] == undefined) {
            hash[s[i]] = 1;
        } else {
            // 有值，归零
            hash[s[i]] = 0;
        }
        
    }
    // for...in 遍历对象，key是键值即下标
    for(let key in hash) {
        if(hash[key] == 1) {
            return key;
        }
    }
    return " ";
};
```
### 数组做哈西表
借鉴题解：
```
var firstUniqChar = function(s) {
    let arr = new Array(26).fill(0);

    for (let c of s) {
        arr[c.charCodeAt() - 97] += 1;
    }

    for (let c of s) {
        if (arr[c.charCodeAt() - 97] == 1) {
            return c;
        }
    }
    return ' ';
};
```
