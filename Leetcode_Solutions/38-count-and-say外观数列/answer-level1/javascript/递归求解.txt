### 解题思路
题目看半天才懂，真的是，就是个递推过程。n的结果得由n-1的值来推出来。推的过程就是，对字符串遍历，数连续相同的数字，其最终结果就是连续的个数+该数字。比如5是`111221`，6就这么得来的，先连续3个1，所以字符串是`31`，然后2个2，所以是`3122`，最后一个1,所以是`312211`。
递归过程大概就是这样。

### 代码

```javascript
/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function (n) {
  if (n == 1) {
    return "1";
  } else {
    let str = countAndSay(n - 1);
    let curChar = str[0];
    let count = 0;
    let ans = "";
    for (var i = 0; i < str.length; i++) {
      if (str[i] == curChar) {
        count++;
      } else {
        ans += count + curChar;
        curChar = str[i];
        count = 1;
      }
    }
    ans += count + curChar;
    return ans;
  }
};

```