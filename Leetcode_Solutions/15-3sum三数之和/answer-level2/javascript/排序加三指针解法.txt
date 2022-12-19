### 解题思路
- 数组从小到大排序
- 固定值从最小到最大循环
- start和end在固定值右侧移动寻找 start + end = -(固定值)
- 如果三数和小于0，说明start对应值太小，应该右移，反之end左移
- 如果三数和等于零就记录下来, L右移，注意如果L的后一个和当前值相等就需要跳过，参考[0,0,0,0]
- L 不能超过 R
- 此时 固定值i 右移，注意后一个i和当前i应该不相等，相等需要跳过，参考[-4,-1,-1,0,1,2]的-1

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
    let i, L, R, sum = 0, store = []
    let newNums = nums.sort((a, b) => { return a - b })
    for (i = 0; i < nums.length; i++) {
        if (nums[i] > 0) break
        if(nums[i] === nums[i - 1]) continue
        L = i + 1
        R = nums.length - 1
        while (L < R) {
            sum = nums[i] + nums[L] + nums[R]
            if (sum === 0) {
                store.push([nums[i], nums[L], nums[R]])
                while (nums[L] === nums[L + 1]) L++
                L++
            } else if (sum < 0) {
                L++
            } else if (sum > 0) {
                R--
            }
        }
    }
    return store
}
```