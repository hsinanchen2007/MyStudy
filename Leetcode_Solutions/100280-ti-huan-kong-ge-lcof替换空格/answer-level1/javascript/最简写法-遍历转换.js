### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var replaceSpace = function(s) {
//法一  遍历转换
    var res='';
    for(let i of s){
        res+= i==" "? "\%20":i
    }
    return res

};
```