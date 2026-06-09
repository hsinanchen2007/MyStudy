
解法是先对数组排序，对外层循环，注意去重，然后再用左右指针向中间收敛（还是要注意去重）去做two sum

时间复杂度 O(n^2)
空间复杂度 O(1)

```javascript
var threeSum = function(nums) {
    nums.sort((num1, num2) => num1 - num2);
    let result = [];
    for (let i = 0; i < nums.length - 2; i++) {
        if (nums[i] > 0) return result; //因为求三数之和为0，如果第一个值已经大于0，那后面不可能有解了，就直接返回结果
        if (i > 0 && nums[i] == nums[i-1]) continue;
        let left = i + 1;
        let right = nums.length - 1;
        while (left < right){          
            if (nums[i] + nums[left] + nums[right] == 0) {
                result.push([nums[i], nums[left], nums[right]]);
                left++;
                right--;
            } else {
                nums[i] + nums[left] + nums[right] > 0 ? right-- : left++;
            }
            while (left > i + 1 && nums[left] == nums[left - 1]) left++;
            while (right < nums.length - 1 && nums[right] == nums[right + 1]) right--;
        }
    }
    return result;
};
```


