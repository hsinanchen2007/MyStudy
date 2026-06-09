### 解题思路
1. 数组的和能整除3
2. 只需要找出两段和等于目标值的就可以了
3. 二分查找法

### 代码

```javascript
 /**
 * @param {number[]} A
 * @return {boolean}
 */
  var canThreePartsEqualSum = function (A) {

    // 首先判断是否有可能划分三等份
    sum = A.reduce((prev, cur) => prev + cur)
    if (sum % 3 !== 0) {
      return false
    }
    let avg = sum / 3

    // 其次声明两个指针, 二分查找法
    let [f, l] = [0, A.length - 1]
    let [firstVal, secondVal] = [A[f], A[l]]
    let flag = false

    // 一前一后累计, 满足条件则退出
    while (f < l) {
      if (firstVal !== avg) {
        firstVal += A[++f]
      }
      if (secondVal !== avg) {
        secondVal += A[--l]
      }
      if (firstVal === secondVal && firstVal === avg) {
        flag = true
        break
      }
    }

    // 第二个条件是为了防止数组只能划分成两份, 在均值为 0 的时候
    return flag && f + 1 < l
  };
```