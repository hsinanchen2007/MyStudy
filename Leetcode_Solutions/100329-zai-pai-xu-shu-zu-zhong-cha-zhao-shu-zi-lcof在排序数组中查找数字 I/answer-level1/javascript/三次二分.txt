三次二分法，写的比较乱，但是更容易理解：
第一次，寻找数字位置`mid`和上一次左边的节点`preLeft`
第二次，以`[ preLeft, mid ]`尽量往左边寻找第一个`target`
第三次，以`[ mid, right ]`尽量向右边寻找最后一个`target`
最后结果为二者差值并+1

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    if (nums.length === 0) return 0;
    let left = 0;
    let right = nums.length - 1;
    let preLeft;
    while (left <= right) {
        const mid = (left + right) >>> 1;
        if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            preLeft = left;
            left = mid;
            break;
        }
    }
    if (preLeft === undefined) return 0;
    const rangeLeft = [preLeft, left];
    const rangeRight = [left, right];
    // 尽可能向左边寻找
    while(rangeLeft[ 0 ] < rangeLeft[ 1 ]) {
        const mid = (rangeLeft[ 0 ] + rangeLeft[ 1 ]) >>> 1;
        if (nums[ mid ] < target) {
            rangeLeft[ 0 ] = mid + 1;
        } else {
            rangeLeft[ 1 ] = mid;
        }
    }
    // 尽可能向右边寻找
    while(rangeRight[ 0 ] < rangeRight[ 1 ]) {
        const mid = (rangeRight[ 0 ] + rangeRight[ 1 ]) >>> 1;
        if (nums[ mid ] > target) {
            rangeRight[ 1 ] = mid - 1;
        } else {
            rangeRight[ 0 ] = mid + 1;
        }
    }
    // 由于以上向右边寻找可能存在多+1情况，因此做一个检测
    if (nums[ rangeRight[ 0 ] ] !== target) rangeRight[ 0 ]--;
    return rangeRight[ 0 ] - rangeLeft[ 0 ] + 1;
};
```
