## 1.栈
> 遇到( { [ 字符入栈，非则出栈比较
```
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
  if (s % 2) return false;
  let stack = [];
  let map = {
    '{': '}',
    '(': ')',
    '[': ']'
  }
  for (let i = 0; i < s.length; i++) {
    let str = s.charAt(i);
    if (map[str]) {
      stack.push(str);
    } else {
      let popS = stack.pop();
      if (map[popS] !== str) return false;
    }
  }
  return stack.length === 0;
};

```
## 2.不断替换法
>不断替换 () {} [] 这种成对字符，替换后的结果与原结果相同，则说明无法替换，则不存在成对字符了 返回false，最后如果逊汗执行完了  返回true
```
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
  if (s % 2) return false;
  while (s.length) {
    let temp = s;
    s = s.replace('()', '');
    s = s.replace('[]', '');
    s = s.replace('{}', '');
    if (s === temp) return false;
  }
  return true;
};


```
