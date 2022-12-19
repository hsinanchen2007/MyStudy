```js
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