### 解题思路
本来一行代码解决的事情。。。

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} m
 * @param {number[]} B
 * @param {number} n
 * @return {void} Do not return anything, modify A in-place instead.
 */
var merge = function(A, m, B, n) {
    //不能修改A的引用，在原数组上修改
    //通过splice api修改原数组
    //刚开始我用slice方法，该方法返回一个新的数组对象
    A.splice(m,A.length-m)
    B.splice(n,B.length);
    A.push(...B) ;

    return A.sort((a,b)=>a-b)

};
```