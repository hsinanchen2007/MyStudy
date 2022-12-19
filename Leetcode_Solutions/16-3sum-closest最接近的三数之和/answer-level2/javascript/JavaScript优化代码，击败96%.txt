### 解题思路
大方向上是遍历数组+二分搜索
但是加了一个减支优化条件
```js
if (i > 0 && nums[i] === nums[i - 1]) {
    continue;
}
```
排除所有重复元素的干扰，可以在有大量重复元素的数据集中表现出色

### 代码

```javascript
var threeSumClosest = function (nums, target) {
    const len = nums.length;
    if (len < 3) {
        return undefined;
    }
    let res = nums[0] + nums[1] + nums[2];
    nums.sort((a, b) => a - b);
    for (let i = 0; i < len - 2; i++) {
        if (i > 0 && nums[i] === nums[i - 1]) {
            continue;
        }
        let left = i + 1,
            right = len - 1;
        while (left < right) {
            const sum = nums[i] + nums[left] + nums[right];
            if (Math.abs(sum - target) < Math.abs(res - target)) {
                res = sum;
            }
            if (sum > target) {
                right--;
            } else if (sum < target) {
                left++;
            } else return sum;
        }
    }
    return res;
};
```