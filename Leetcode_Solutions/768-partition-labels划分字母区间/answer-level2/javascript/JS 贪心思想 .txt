### 解题思路
首先把字符串中每个字母的最后索引值找到，用贪心思想，将当前索引值及最后索引值之间的那段字符串（片段）遍历，如果发现其中含有最后索引值较大的元素，将该元素的最后索引值设为当前片段的最后索引值，直到遍历完成，即能筛选出最小片段

### 代码

```javascript
/**
 * @param {string} S
 * @return {number[]}
 */
var partitionLabels = function(S) {
  let lastIndexOfChar = new Map();
  for (let i = 0; i < S.length; i++) {
    lastIndexOfChar.set(S[i], i)
  }
  
  let res = [];
  let currentIndex = 0;
  while (currentIndex < S.length) {
    let lastIndex = lastIndexOfChar.get(S[currentIndex]);
    for (let i = currentIndex; i <= lastIndex; i++) {
      lastIndex = Math.max(lastIndex, lastIndexOfChar.get(S[i]))
    }
    res.push(lastIndex - currentIndex + 1);
    currentIndex = lastIndex + 1;
  }
  return res;
};
```