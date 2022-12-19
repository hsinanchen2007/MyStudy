### 解题思路
看代码，也扩张题目。

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var sumNums = function(n) {
    //求和公式
    /**
     * 扩展：
     * 计算给定数组 arr 中所有元素的总和
     * var array = [1, 2, 3, 4, 5];
     * 
     * 拿到数组长度: var len = array.length;
     * var num = (len*(len+1))/2
     * */
    //return (n*(n+1)) / 2

    /**
     * && 的短路特性
        A && B
        A 为 true，则返回表达式 B 的 bool 值
        A 为 false，则返回 false
     */
    return  n && (n=n+sumNums(n-1));
};
```