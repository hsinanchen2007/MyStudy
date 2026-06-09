### 解题思路
时间复杂度:O(n),n为数组长度
空间复杂度：O(1)

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    let [low, high, count] = [0, nums.length-1, 0];
    while (low <= high) {
        let mid = low + ((high-low)>>1);
        let tmp = mid;
        if (nums[mid] === target) {
            count++;
            while(nums[mid-1] === nums[mid]){
                count++;
                mid--;
            }
            while(nums[tmp+1] === nums[tmp]){
                count++;
                tmp++;
            }
            return count;
        }else if (nums[mid] >target) {
            high = mid - 1;
        }else {
            low = mid+1;
        }
    }
    return 0;
};
```