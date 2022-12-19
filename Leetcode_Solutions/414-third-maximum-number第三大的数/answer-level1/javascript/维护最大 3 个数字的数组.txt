### 解题思路
去重之后，维护一个大小为 3 的有序数组，每次找到更大的数字时，更新数组。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
const sortedPush = (arr, target) => {
    arr.shift();
    if (target > arr[1]) {
        arr.push(target)
    } else if (target < arr[0]) {
        arr.unshift(target);
    } else {
        arr.unshift(arr[0]);
        arr[1] = target;
    }
}

var thirdMax = function(nums) {
    if (!nums.length) return 0;
    const noDumplicateArray = Array.from(new Set(nums));
    const kArray = new Array();
    let isFull = false;
    for (let i = 0; i < noDumplicateArray.length; ++i) {
        if (!isFull) {
            kArray.push(noDumplicateArray[i]);
            isFull = (kArray.length > 2);
            kArray.sort((a, b) => a - b);
        } else if (noDumplicateArray[i] > kArray[0]) {
            sortedPush(kArray, noDumplicateArray[i]);
        }
    }
    return isFull ? kArray[0] : kArray[kArray.length - 1];
};
```

### 复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)