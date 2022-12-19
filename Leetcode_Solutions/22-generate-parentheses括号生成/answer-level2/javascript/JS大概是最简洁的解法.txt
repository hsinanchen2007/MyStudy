
经典递归解法，观察发现
1、某一次递归终止时需要将当前字符存入数组
2、 字符任取一个位置左侧必 左括号>=右括号
3、每次递归除了需要传当前字符还需要记情当前左右括号数

```js
    var generateParenthesis = function (n) {
      let res = [];
      //  cur :当前字符  left：当前字符左括号 right:当前字符右括号
      const help = (cur, left, right) => {
        if (cur.length === 2 * n) {
          res.push(cur);
          return;
        }
        if (left < n) {
          help(cur + "(", left + 1, right)
        }
        if (right < left) {
          help(cur + ")", left, right + 1);
        }
      };
      help("", 0, 0);
      return res;
    };
```
