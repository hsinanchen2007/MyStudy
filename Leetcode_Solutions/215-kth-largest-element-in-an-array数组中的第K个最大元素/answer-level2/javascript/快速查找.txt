```js
// 参考快排序的快速查找
var findKthLargest = function (nums, k) {
    
    function swap(a, b) {
        let temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
    
    // 查找nums[start]正确的排序位置
    // 直到找到排在第k-1位的。就是所求结果
    function findLocation(start, end) {
        if (start === end) return nums[start];
    
        let i = start;
        let j = end + 1;
        
        while (true) {

            while (nums[++i] > nums[start]) if (i === end) break;
            while (nums[--j] < nums[start]) if (j === start) break;
            
            if (i < j) swap(i, j) // 交换左右边元素，保证左分支元素 大于 右分支元素

            if (i >= j) {
                swap(start, j)
                break
            }
        }
        
        // 找到所求元素
        if (j === k - 1) return nums[j];
        
        // j>k-1 从nums[j]的左边分支开始查找
        // 否则 从右边分支查找
        if (j > k - 1) return findLocation(start, j - 1);
        
        else return findLocation(j + 1, end);
    }

    return findLocation(0, nums.length - 1)

};
```
