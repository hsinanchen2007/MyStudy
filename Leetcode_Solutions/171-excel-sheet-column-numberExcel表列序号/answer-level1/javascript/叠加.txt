### 解题思路
此处撰写解题思路
**如 'A'     A = 1**

**如 'AA' 它是 'Z'下一行, Z=26, AA = 26 + 1 = 27**

所以 AA =  26 *  A + A

**如 'AAA' 它是 'ZZ'下一行  ZZ=26\*26 + 26 , AAA = (26\*26 + 26) + 1 = 26 \* 27 + 1**

所以 AAA =  26 *  AA + A


### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var titleToNumber = function(s) {
    let list = s.split('')
    let total = 0
    list.forEach(item=>{
      let num = item.charCodeAt() - 64
      total = total * 26 + num
    })
    return total
};
```