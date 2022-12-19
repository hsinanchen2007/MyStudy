### 解题思路
我只想问一下，真的不用转成boolean？
我控制台测试的不写!!返回的是number啊，虽然在这里不写!!测试也能通过。
有没有人解答一下。

### 代码

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var canWinNim = function(n) {
    return !!(n%4)
};
```