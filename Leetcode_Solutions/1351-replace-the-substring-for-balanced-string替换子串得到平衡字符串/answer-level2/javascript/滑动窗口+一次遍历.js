1. 滑动窗口，左指针left，右指针right
2. map定义整个字符串QWER的个数  cur定义整个滑块包含的QWER的个数
3. 当map - cur中q、w、e、r的个数均<=字符串长度/4的时候，滑块中的字符串被替换就平衡了
4. 最后移动left和right
5. 如果当前滑块满足条件 应该减少一个字符 即left++ 去寻找可能更短的答案
6. 否则当前滑块不满足条件 需要在右侧添加一个字符 即right++
```
var balancedString = function (s) {
  let map = { Q: 0, W: 0, E: 0, R: 0 };
  let cur = { Q: 0, W: 0, E: 0, R: 0 };
  for (let char of s) {
    map[char]++;
  }
  let avg = s.length / 4;
  let left = 0;
  let right = -1;
  let res = 100000;
  while (right < s.length) {
    if (map.Q - cur.Q <= avg && map.W - cur.W <= avg && map.E - cur.E <= avg && map.R - cur.R <= avg) {
      res = Math.min(right - left + 1, res);
      if (left < right) {
        --cur[s[left++]]
      } else {
        return res;
      }
    } else {
      ++cur[s[++right]]
    }
  }
  return res;
}
```
