### 解题思路
>短代码
>reverse等效替换，不用就自己写一个
>PS: 小心空格坑

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.split(' ').map(item=>{
        return item.split('').reverse().join('');
    }).join(' ');
};
```