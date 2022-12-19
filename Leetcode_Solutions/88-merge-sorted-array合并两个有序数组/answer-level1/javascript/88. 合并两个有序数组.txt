前言：
   合并两个有序数组，第一想法是归并排序中的merge函数。因此，解法就比较简单了。

解法：双指针从前面开始处理
如果从前开始处理，我们需要申请O(m+n)的辅助空间，避免丢失其中的值。
```javascript
var merge = function(nums1, m, nums2, n) {
    let i = 0, j = 0, k = 0;
    let res = new Array(m+n).fill(0);
    while(i <m && j < n) {
        if(nums1[i] < nums2[j]) {
            res[k] = nums1[i];
            i++;
        } else {
            res[k] = nums2[j];
            j++;
        }
        k++;     
    }
    for (; i < m; i++) {
        res[k] = nums1[i];
        k++;
    }

    for (; j < n; j++) {
        res[k] = nums2[j];
        k++;
    } 
    res.forEach((element, index) => nums1[index] = element);
    return nums1;
};
```

解法2： 双指针改进
由于nums1有足够大的空间，因此我们可以从后往前遍历。
```javascript
var merge = function(nums1, m, nums2, n) {
    let i = m - 1;
    let j = n - 1;
    let k = m + n - 1;
    while(i >= 0 && j >= 0) {

        if(nums1[i] < nums2[j]) {
            nums1[k] = nums2[j];
            j--;
        } else {
            nums1[k] = nums1[i];
            i--;
        }
        k--;
        
    }
    if(i < 0) {
        for (; j >=0; j--) {
            nums1[j] = nums2[j]
        }
    }
    
    return nums1;
};

```
这里需要注意nums2先处理完的边界情况，和从前往后遍历不一样的是，如果nums2先处理完，那么剩余未遍历的nums1的位置就是最终的位置。

结论：
最坏时间复杂度O(m+n)
最坏空间复杂度O(1)
