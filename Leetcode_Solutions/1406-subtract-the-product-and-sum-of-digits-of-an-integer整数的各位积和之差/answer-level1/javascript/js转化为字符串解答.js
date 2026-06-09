![image.png](https://pic.leetcode-cn.com/2b0d91f4dbae0126c00ccc0eb76fb25274d0ed6d706fd765c04664ddeee968d9-image.png)
# 思路
  将n转化为字符串，对字符串进行遍历相加和相乘，最后返回相减值
# 代码
```
/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function(n) {
    var str = n.toString();
    var sum = 0,total = 1;
    for(let i = 0 ; i< str.length ; i++){
        sum = sum + parseInt(str[i]);
        total = total * parseInt(str[i]);
    }
    return total - sum;
};
```