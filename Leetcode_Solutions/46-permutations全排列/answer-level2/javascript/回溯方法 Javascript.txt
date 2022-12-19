### 解题思路
回溯方法

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function (nums) {
  let list = []
  backTrack(list, [], nums)
  return list
};

function backTrack (list, arr, nums) {
  if (arr.length === nums.length) {
    return list.push([...arr])
  }
  for (let i = 0, len = nums.length; i < len; i++) {
    const element = nums[i]
    if (arr.indexOf(element) !== -1) {
      continue
    }
    arr.push(element)
    backTrack(list, arr, nums)
    arr.pop()
  }
}
```