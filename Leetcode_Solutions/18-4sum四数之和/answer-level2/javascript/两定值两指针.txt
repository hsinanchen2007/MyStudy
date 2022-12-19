### 解题思路
参考三数和问题，多添加一个定值

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function (nums, target) {
    let i, j, L, R, sum = 0, store = [], len = nums.length
    let newArr = nums.sort((a, b) => { return a - b })
    for (i = 0; i < len - 3; i++) {
        if(nums[i] + nums[i+1] + nums[i+2]+ nums[i+3] > target) break
        if(nums[i] + nums[len-1] + nums[len-2] + nums[len - 3] < target) continue
        if(nums[i] === nums[i - 1]) continue
        for (j = i + 1; j < len - 2; j++) {
            if(nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break
            if(nums[i] + nums[j] + nums[len -1] + nums[len-2] < target) continue
            L = j + 1
            R = len - 1
            if(j-i>1 && nums[j] === nums[j - 1]) continue
            while (L < R) {
                sum = nums[i] + nums[j] + nums[L] + nums[R]
                if (sum === target) {
                    console.log(1111)
                    store.push([nums[i], nums[j], nums[L], nums[R]])
                    while(nums[L] === nums[L + 1]) L++
                    L++
                } else if (sum < target) {
                    L++
                } else if (sum > target) {
                    R--
                }
            }
        }
    }
    return store
};
```