### 解题思路
此处撰写解题思路
维护两个指针，
  start 指针指向无重复字符的开始位置
  end 指针指向无重复字符的结束位置
  length 记录最长无重复字符的长度
  curStr 当前无重复子串
  repIndex 记录重复的字符在 curStr 的位置

尽可能的后移 end 指针，当遇到重复的字符时，后移 start 指针直到 start -> end 范围内无重复字符。
每次移动都将当前子串的长度与 length 进行比较， 取其中的较大值。

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    if (s.length == 1) {
    return 1;
  }
  // 滑动窗口
  let start = 0;
  let end = 0;
  let curStr = ''
  let repIndex;
  let length = 0;
  while (end <= s.length - 1) {
    if (curStr.indexOf(s.substr(end, 1)) !== -1) {
      repIndex = curStr.indexOf(s.substr(end, 1))
      start = repIndex + start + 1;
    }
    curStr = s.slice(start, end + 1)
    length < curStr.length && (length = curStr.length);
    end ++;
  }
  return length
};
```