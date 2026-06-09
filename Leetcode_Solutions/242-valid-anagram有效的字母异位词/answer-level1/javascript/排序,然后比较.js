### 解题思路
使用快排,然后比较两个字符串是否相等,时间复杂度O(nlogn);

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
    return QuitSort(s.split('')).join('') === QuitSort(t.split('')).join('')
  };
  function QuitSort(list) {
    if (!list) return []
    if (list.length <= 1) return list;
    let povitIndex = Math.floor(list.length / 2)
    let povit = list.splice(povitIndex, 1)[0]
    let left = []
    let right = []
    for (let i = 0; i < list.length; i++) {
      const item = list[i].charCodeAt();
      if (item > povit.charCodeAt()) {
        left.push(list[i])
      } else {
        right.push(list[i])
      }
    }
    return QuitSort(left).concat(povit, QuitSort(right))
  }
```