### 解题思路
将整数转换成二进制字符串后通过split转换成数组,遍历得到数字1的个数

### 代码

```javascript
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
    let num=0;
    n=n.toString(2).split("");
    for(let i of n){
        if(i==1) num++;
    }
    return num;
};
```