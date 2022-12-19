### 解题思路
使用object保存字母出现的次数,每次加1
最后比较两个对象是否完全相等.
没有嵌套循环,时间复杂度低

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
    if (s.length !== t.length) return false
    return isEqualObj(setMap(s), setMap(t))
  };
  function setMap(list) {
    let map = {}
    for (let i = 0; i < list.length; i++) {
      const item = list[i];
      if (!map[item]) {
        map[item] = 1
      } else {
        map[item]++
      }
    }
    return map
  }
  function isEqualObj(a, b) {
    let aKeys = Object.keys(a)
    let bKeys = Object.keys(b)
    let flag = true
    bKeys.some(key => {
      flag = a[key] === b[key]
      return a[key] !== b[key]
    })
    return flag
  }
```