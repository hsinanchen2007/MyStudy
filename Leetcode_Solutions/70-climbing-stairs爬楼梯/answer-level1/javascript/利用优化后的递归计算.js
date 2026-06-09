### 解题思路
当数量级大点暴力破解基本上既不能指望了。
思路：首先手动计算前几次的值，归纳出实际上是斐波那契数列，第一次采用的是基本的斐波那契算法，测试用例能通过大概80%，后面的因为数量级太大导致超时，
然后用优化后的递归算法，就是计算之前算出的每一项的值保存起来，把重复计算的问题避免掉。
方案：利用对象的唯一性，把计算的值当作对象中的一组键值对存储，当再次的时候查询就可以。
### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
 var memory = {} ;//利用对象的唯一性，把每一次计算过的值当作对象中的键值对存储起来
    let res = function dp(n) {
        if(n===1 || n===2){
            return n
        }
        if(memory[n-2] ===undefined){
            memory[n-2] = dp(n-2)
        }
        if(memory[n-1] ===undefined){
            memory[n-1] = dp(n-1)
        }
        return memory[n] = memory[n-1] + memory[n-2]
    };
    return res(n)
};
```