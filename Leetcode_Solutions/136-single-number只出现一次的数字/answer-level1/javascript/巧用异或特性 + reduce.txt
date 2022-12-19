### 解题思路
此处撰写解题思路
异或特性：转为二进制 相同为0 不同为1
0^n => n 0异或任何数得任何数
n^n => 0 任何数异或自身得0
a^b^a => a^a^b => 0^b => b 异或运算满足交换律
猜想运行时 runtime：
2^1^2
2^1 => 0010 ^ 0001 => 0011 => 3 对位相同为0 不同为1 再转为十进制
3^2 => 0011 ^ 0010 => 0001 => 1 对位相同为0 不同为1 再转为十进制
最终为 1
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = nums => nums.reduce((acc, next) => acc^next)
```