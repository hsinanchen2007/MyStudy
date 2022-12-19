*法一：求中心索引左右两边的和*

缺点：太慢，不可取

```js
var pivotIndex = function(nums) {
    let add = function(arr) {
        var s = 0;
            for (var i = arr.length-1; i >= 0; i--) {
                s += arr[i];
            }
        return s;
    }
    let sum = add(nums);
    let len = nums.length;
    for (let i = 0; i < len; i++) {
        halfSum = (sum - nums[i]) / 2;
        leftArr = nums.slice(0,i).length !== 0 ? nums.slice(0,i) : nums[i];
        rightArr = nums.slice(i+1,len);
        leftSum = add(leftArr)
        rightSum = add(rightArr)
        if (leftSum == rightSum) {
            return i
        }
    }
    return -1
};
```

*法二：只求中心索引左边的和*

改进法一，推荐

1. sumLeft + sumRight + nums[i] = sumTotal;
2. sumLeft = sumRight
3. 可以得出 sumLeft * 2 + nums[i] = sumTotal;

```js
var pivotIndex2 = function(nums) {
    let len = nums.length;
    let sumTotal = 0;
    for (var i = len - 1; i >= 0; i--) {
        sumTotal += nums[i];
    }
    let leftSum = 0;
    for (let i = 0; i < len; i++) {
        if (leftSum * 2 == sumTotal - nums[i]) {
            return i
        }
        leftSum += nums[i];
    }
    return -1
};
```

*法三：双指针*

最终失败，

原因：无法处理负数，比如 [-1,-1,-1,-1,-1,0]

