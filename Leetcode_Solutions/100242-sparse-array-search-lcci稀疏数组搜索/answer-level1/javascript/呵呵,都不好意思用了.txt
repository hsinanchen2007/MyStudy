### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} s
 * @return {number}
 */
var findString = function(words, s) {
    return words.indexOf(s)
};
```

用字典

``` js
var findString = function(words, s) {
   let map = new Map()
   for(let i = 0; i< words.length; i++){
     map.set(words[i], i)
   }
    return map.has(s) ? map.get(s) : -1 
};
```
