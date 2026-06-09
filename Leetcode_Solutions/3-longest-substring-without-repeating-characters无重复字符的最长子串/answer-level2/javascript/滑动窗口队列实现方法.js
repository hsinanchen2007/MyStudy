
先考虑是否是动态规划，感觉不好列出状态方程。在考虑字串是连续的，那么意思可能是双指针，或者滑动窗口。想到滑动窗口就大致有了思路。维护一个窗口，用队列表示即可。遍历每一个字符，判断该字符是否在队列中是的话就把该字符之前的都出队列，然后该字符入队，每次比较队列长度和最大值。

```javascript
var lengthOfLongestSubstring = function(s) {
  let list = [];
  let max = 0;
  for (var i = 0; i < s.length; i++) {
    let index = list.indexOf(s[i]);
    if (index != -1) {
      list = list.slice(index + 1);
    }
    list.push(s[i]);

    if (list.length > max) {
      max = list.length;
    }
  }
  return max;
};

```
