### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} nums
 * @param {number} r
 * @param {number} c
 * @return {number[][]}
 */
var matrixReshape = function (nums, r, c) {
    let arr = []
    nums.forEach(item => {
      arr = arr.concat(item)
    })
    let list = []
    if (arr.length === r * c) {
      while (arr.length != 0) {
        let a = arr.slice(0, c )
        arr = arr.slice(c )
        list.push(a)
      }
      return list
    }
    return nums
  };
```