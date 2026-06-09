### 解题思路
- 利用ES6结构赋值互换首位元素的位置；
- 遍历的范围是数组长度的一半；
### 代码

```javascript
/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var reverseString = function(s) {
    for(i=0;i<s.length/2;i++){
        [s[i],s[s.length-1-i]]=[s[s.length-1-i],s[i]]
    }
};
```