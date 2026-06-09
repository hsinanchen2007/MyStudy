定义一个最大值max，原数组input，初始值为nums，筛选过的数组output，初始值为[]，首先赋值max为数组的最后一个数，然后将input数组从后向前与max比较，如果数字比max大，说明暂不可交换，max变成此数字，并将此数字push到output数组，input数组相应地减去此数字，递归循环；如果数字比max小，则可交换，在output数组内找出比目标数字大得最少的数字a（可以发现output一定是从小到大排列的）然后交换目标数字和a的位置，使用splice更新nums，返回即可

若自始至终input数组前面的数字都大于后面的数字，则nums数组是降序排列的，使用双指针翻转数组即可

```
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function(nums) {
    const len = nums.length
    let descent = true
    let switchIdx = len - 1
    let switchNum = nums[switchIdx]
    let i = len - 2
    const switchFn = (input, output, max) => {
        if (output.length === len) {
            return output
        }
        const idx = input.length - 1
        const ele = input[idx]
        const outLen = output.length
        if (ele < max) {
            descent = false
            let switchNum = 0
            for(let i = outLen - 1; i >= 0; i--) {
                if (i > 0 && output[i] > ele && output[i-1] <= ele || i === 0) {
                    switchNum = output[i]
                    output[i] = ele
                    break
                }
            }
            nums.splice(idx, outLen + 1, switchNum, ...output)
            return
        } else {
            max = ele
            switchFn(input.slice(0, idx), [...output, ele], max)
        }
    }
    switchFn(nums.slice(), [], 0)
        
    if (descent) {
        let mid = Math.floor(len/2)
        for(let i = 0, j = len - 1; i < j; i++, j--) {
            [nums[i], nums[j]] = [nums[j], nums[i]]
        }
    }
    return nums
};
```
