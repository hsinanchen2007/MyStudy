### 解题思路
可以使用快排来实现。
1. 每次选区最后一个元素作为分区点，将小于qvoit的值放在左边，大于等于qvoit的值放在右边;
2. 重复此步骤，当区间长度小于等于1时回归。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function(nums) {
    let p = 0,
        r = nums.length-1;
    quickSort(nums, p, r);
    return nums;
};

var quickSort = function(nums, p, r){
    if (p >= r) return false;
    var q = partion(nums, p, r);
    quickSort(nums, p, q-1);
    quickSort(nums, q+1, r);
};

var partion  = function(nums, p, r) {
    let qvoit = nums[r];
    let i = p,
        j = p;
    
    for (; j<r;j++) {
        if (nums[j] < qvoit) {
            let temp = nums[j];
            nums[j] = nums[i];
            nums[i++] = temp;
        }
    }

    let temp = nums[i];
    nums[i] = qvoit;
    nums[r] = temp;
    return i;
};


```