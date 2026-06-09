```javascript []
/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function(x, y) {
//     ^：与（x^y）两二进制上下比较只有位不相等时才取1，否则取零
    // ^ 就是 & 取反
//           14^15  (14  二进制  1110
                  
//                     15    二进制   1111
                  
//                    ^与的结果      0001 ----》结果1)

// 如果 regexp 具有标志 g，则 match() 方法将执行全局检索，找到 stringObject 中的所有匹配子字符串。若没有找到任何匹配的子串，则返回 null。

   let n = x ^ y
   let str = n.toString(2)
   let res = str.match(/1/g)
   return res?res.length:0
};
```
