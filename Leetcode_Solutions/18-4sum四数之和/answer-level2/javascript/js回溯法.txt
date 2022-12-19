### 解题思路
回溯法，之前三数和用回溯法超时了，没想到四数和不会超时

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
const backTrack = function (list, temp, nums, target, start) {
    if (temp.length === 4 && temp[0] + temp[1] + temp[2] + temp[3] === target) return list.push([...temp])
    if (temp.length >= 4 && temp[0] + temp[1] + temp[2] + temp[3] !== target) return
    for (let i = start; i < nums.length; i++) {
        if (i > start && nums[i] === nums[i-1]) continue
        temp.push(nums[i])
        backTrack(list, temp, nums, target, i + 1)
        temp.pop()
    }
}
var fourSum = function(nums, target) {
    let res = []
    backTrack(res, [], nums.sort(), target, 0)
    return res
};
```