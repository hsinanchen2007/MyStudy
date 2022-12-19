- maxSize肯定没用 如果最佳结果字符串的长度是minSize+1 那么字符串的长度是minSize也一定是最佳结果
- 所以字符串长度一定取minSize
- 通过map以字符串为key 出现次数为value 更新每个字符串出现的次数 得到最终结果 
- 然后滑动窗口数组 temp 来计算当前长度为minSize的每个字母的个数count
- 每次向前滑动一格  减去第一个字母 如果当前字母的个数是1  则--count
- 在最后面添加一个字母  如果当前字母的个数是0  则++count
```
var maxFreq = function (s, maxLetters, minSize, maxSize) {
  let max = 0;
  let map = new Map();
  let str = '';
  let count = 0;
  let temp = new Array(26).fill(0);
  for (let start = 0, end = Math.min(minSize - 1, s.length); start < end; ++start) {
    str += s[start];
    if (temp[s[start].codePointAt() - 97] === 0)++count
    ++temp[s[start].codePointAt() - 97]
  }
  for (let i = 0, len = s.length + 1 - minSize; i < len; ++i) {
    str += s[i + minSize - 1];
    if (temp[s[i + minSize - 1].codePointAt() - 97] === 0)++count;
    ++temp[s[i + minSize - 1].codePointAt() - 97]
    if (count <= maxLetters) {
      map.set(str, (map.get(str) || 0) + 1)
      max = Math.max(max, map.get(str));
    }
    if (temp[s[i].codePointAt() - 97] === 1)--count;
    --temp[s[i].codePointAt() - 97]
    str = str.slice(1)
  }
  return max;
};
```
