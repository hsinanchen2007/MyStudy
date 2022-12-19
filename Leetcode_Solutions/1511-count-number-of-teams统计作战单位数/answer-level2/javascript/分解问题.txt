![image.png](https://pic.leetcode-cn.com/abf3be816e550f5ec9a318b2652c517b8809837a11beec4e17ea63b0dfea4992-image.png)

![image.png](https://pic.leetcode-cn.com/0c297445ec81b816e6570fb0ba68486179ed5c64a96f2f8ab7742f6fb2965dd5-image.png)



### 解题思路
1. 求三个一组保持原顺序的分组
2. 筛选满足条件的分组

### 代码

```javascript
/**
 * @param {number[]} rating
 * @return {number}
 */
var numTeams = function(rating) {
  if (rating.length < 3) {
    return 0
  }
  let res = 0
  function is3ElAscendentOrDescendent (arr) {
    if ((arr[0] > arr[1]) && (arr[1] > arr[2])) {
      return true
    } else if ((arr[0] < arr[1]) && (arr[1] < arr[2])) {
      return true
    } else {
      return false
    }
  }
  function pick3 (arr) {
    const res = []
    for (let i = 0; i < arr.length - 2; ++i) {
      for (let j = i + 1; j < arr.length - 1; ++j) {
        for (let k = j + 1; k < arr.length; ++k) {
          res.push([arr[i], arr[j], arr[k]])
        }
      }
    }
    return res
  }
  const arr = pick3(rating)
  arr.forEach(item => {
    if (is3ElAscendentOrDescendent(item)) {
      ++res
    }
  })
  return res
};
```