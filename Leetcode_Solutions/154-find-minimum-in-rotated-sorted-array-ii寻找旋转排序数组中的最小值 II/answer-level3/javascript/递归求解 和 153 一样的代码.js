![image.png](https://pic.leetcode-cn.com/64fae2b85b2378f328439fd684254d81f372c6cd6bc3a80192ded3c274086385-image.png)

[153 题解](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/javascript-di-gui-qiu-jie-by-paddingme/)


虽然 递归答案是一样的，但是时间复杂度是不一样的， 153 时间复杂度为 O(logn), 154 则为 O(n);



```
const findMin = nums => {

    const findMinimum = (arr, low, high) => {
        //  1个 或者 2个时 直接比较得出最小
        if (high - low <= 1) return Math.min(arr[low], arr[high]);

        // 有序，直接返回 low
        if (arr[low] < arr[high]) return arr[low];

        let mid = Math.floor(low + (high - low) / 2);

        
        return Math.min(findMinimum(arr, low, mid), findMinimum(arr, mid + 1, high));
    };

    return findMinimum(nums, 0, nums.length - 1);

}
```

