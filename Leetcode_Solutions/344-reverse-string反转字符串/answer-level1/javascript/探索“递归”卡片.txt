### 解题思路
![image.png](https://pic.leetcode-cn.com/3220aa13bc1fb25a58ef2c80e4e248cfa4af0bc5d5112270e09594164807a496-image.png)

每次从s头部shift一个出来放到tmp，然后递归reverse“shift之后的s”再push(tmp)。

"内存消耗"成绩倒数，是因为递归占的隐含栈的空间吗?

### 代码

```javascript
/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var reverseString = function (s) {
    if (s.length <= 1) return void 0;
    let tmp = s.shift();
    reverseString(s);
    s.push(tmp);
};
```