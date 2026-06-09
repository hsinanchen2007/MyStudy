### 解题思路
用字符串拼接出最大值，再循环插入数组

### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var printNumbers = function(n) {
    let arr=new Array();
    let max="";
    for(let i=1;i<=n;i++)
        max=max.concat(9);
    for(let j=1;j<=max;j++)
        arr.push(j);
    return arr;
};
```