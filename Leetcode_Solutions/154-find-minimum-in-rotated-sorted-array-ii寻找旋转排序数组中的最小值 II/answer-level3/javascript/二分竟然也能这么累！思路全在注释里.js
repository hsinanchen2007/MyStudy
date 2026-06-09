### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    let i = 0;
    let j = nums.length - 1
    // 顺序情景
    if(nums[i] < nums[j]) {
        return nums[i]
    }
    let min = nums[j];
    let mid = Math.floor((i + j) / 2)
    while(true) {
        console.log(i, mid, j, '最小值', min)
        if(mid === i) {
            // 两个值或一个值时，直接判断
            return nums[mid] < min ? nums[mid] : min
        }
        // 三个值时
        if(nums[mid] > min) {
            // 此时判定最小值在右侧, 重新定位索引值，循环判断
            i = i + 1
            mid = Math.floor((i + j) / 2)
        } else if(nums[mid] < min) {
            // 此时判断最小值在mid左边, 或就是mid
            j = mid
            min = nums[j]
            // 此时需要让i置为0
            i = 0
        } else if (nums[mid] === min) {
            // 此时不清楚最小值在左边还是在右边
            j = j - 1 
            if(min < nums[j]) {
                // 此时可以立刻判断最小值是min
                return min
            } else {
                min = nums[j]
            }
            mid = Math.floor((i + j) / 2)
        }
    }

};
```