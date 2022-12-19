### 解题思路
![屏幕快照 2019-12-12 上午11.04.52.png](https://pic.leetcode-cn.com/19cbdcc630b409113691d386432b5bf709a2d433c122ce63a2605043aa9d05ef-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-12-12%20%E4%B8%8A%E5%8D%8811.04.52.png)

思路见下方注释


### 代码

```javascript
var buddyStrings = function(A, B) {
  if (A === "" && B === "") {
    return false
  } else if (A.length !== B.length) {
    return false
  } else {
    let first = 0,
      second = 0,
      count = 0 
    const tt = {}

    // 开始遍历，寻找A和B不同的元素
    for (let i = 0; i < A.length; i++) {
      // 遍历的同时记录下每个字母出现过几次，用于之后A和B完全相同时的比较
      if (tt[A[i]]) {
        tt[A[i]]++
      } else {
        tt[A[i]] = 1
      }

      if (A[i] !== B[i]) {
        // count 标记着A和B有几处不同的字母
        count++

        if (count > 2) {
          // 如果发现有第三处不同的地方，直接
          return false
        } else if (count === 2) {
          // 第二处
          second = i
        } else if (count === 1) {
          // 第一处
          first = i
        }
      }
    }

    if (count === 0) {
      // A 和 B 完全相同时，只要有任意一个字母出现过两次就是亲密字符串
      for (let key in tt) {
        if (tt[key] > 1) {
          return true
        }
      }
      return false
    } else if (A[first] === B[second] && A[second] === B[first]) {
      // 包含了只有一处不同和有两处不同的情况
      // 当只有一处不同的时候，亲密字符串只能存在于A和B除了不同处以外的所有字母都相同的情况下，故直接拿second=0去比较没有问题
      // 当有两处不同的时候，没啥好说的
      return true
    } else {
      return false
    }
  }
}

```