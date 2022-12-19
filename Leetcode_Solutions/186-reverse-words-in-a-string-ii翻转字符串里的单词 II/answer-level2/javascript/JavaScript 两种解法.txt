
### splice  插入 单词

```javascript
/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var reverseWords = function(s) {
  const length = s.length;

  let temp = " ";  // 临时存放一个单词

  let i = 0;

  while (i < length) {
    // 不为空则放入临时数组存放
    if (s[i] !== " ") {
      temp += s[i];
    } else {
      // length 后 直接插入新的单词
      s.splice(length, 0, ...temp);
      temp = " ";
    }
    i++;
  }

  // 最后一个单词
  if (temp.length > 1) {
    s.splice(length, 0, ...temp);
  }

  // 删除原数组
  s.splice(0, length + 1);
};
```

### 两次翻转

先翻转整个数组，再翻转单词


```javascript
var reverseWords = function (s) {

  const length = s.length;

  const reverse = function (s, start, end) {
    while (start < end) {
      let temp = s[end];
      s[end] = s[start];
      s[start] = temp;
      start++;
      end--;
    }
  }
  // 整个数组反转
  reverse(s, 0, length - 1);

  let start = 0, end = 0;

  while (end < length) {
    if (s[end] === " ") {
      // 对每个单词进行翻转
      reverse(s, start, end - 1);
      start = end + 1;
    }
    end++;

  }

  // 翻转最后一个单词
  reverse(s, start, end - 1);
}
```