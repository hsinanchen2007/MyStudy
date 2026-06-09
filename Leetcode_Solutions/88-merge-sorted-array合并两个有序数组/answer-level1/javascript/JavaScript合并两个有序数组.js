#### 思路一
将`nums1`中后面的`0`替换成`nums2`的数，再排序即可。
#### 代码
```
var merge = function(nums1, m, nums2, n) {
    nums1.splice(m, n, ...nums2)
    nums1.sort((a, b) => a - b)
};
```
#### 思路二（双指针）
1. `i`指向`nums1`的末尾，即`i = m + n -1`；
2. `j`指向`nums1`最后一个数，即`j = m - 1`；
3. `k`指向`nums2`末尾，即`k = n - 1`；
4. 比较`nums1[j]、nums2[k]`大小，把大的数赋值给`nums[i]，i--`；
5. 谁大移动谁的指针；
#### 代码
```
var merge = function(nums1, m, nums2, n) {
    let i = m + n - 1;
    let j = m - 1;
    let k = n - 1;
    while (k >= 0 && j >= 0) {
        if (nums1[j] < nums2[k]) {
            nums1[i] = nums2[k]
            k--;
        } else {
            nums1[i] = nums1[j];
            j--;
        }
        i--;
        // 可以简化上面代码
        // nums1[i--] = nums1[j] < nums2[k] ? nums2[k--] : nums1[j--];
    }
    // 存在nums1比较完了，nums2还有剩余数字的情况
    // 比如：nums1=[4,5,6,0,0,0]，nums2=[1,2,3]
    // 此时：nums1=[4,5,6,4,5,6]，需要将nums2剩余的数赋值给nums1
    for (let i = 0; i < k+1; i++) {
        nums1[i] = nums2[i];
    }
};
```

