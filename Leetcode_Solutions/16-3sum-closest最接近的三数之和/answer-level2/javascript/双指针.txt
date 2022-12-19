### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    if (!nums || nums.length < 3) return;
    let arr = nums.sort((a, b) => a-b);
   
    let gap, res = 0;
    for (let i = 0; i < arr.length -2 ; i++) {
         let left = i + 1, right = arr.length - 1;
         
        while (left < right) {
            if (arr[i] + arr[left] + arr[right] === target) {
                return target;
            }
            let temp = Math.abs(arr[i] + arr[left] + arr[right] - target);
            if (!gap || temp < gap) {
                gap = temp;
                res = arr[i] + arr[left] + arr[right];
            }
            if (arr[i] + arr[left] + arr[right] > target) {
                right--;
            } else if (arr[i] + arr[left] + arr[right] < target) {
                left++;
            }
         }
         
    }
    return res;
};
```