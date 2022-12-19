参考题目中的提示，从尾部添加值。
```
var merge = function(nums1, m, nums2, n) {
    let p1 = m-1,//nums1尾部指针
        p2 = n-1,//nums2尾部指针
        p = m + n - 1;//当前插入位置指针
    for(let i=0;i<n;i++){
        while(nums1[p1] > nums2[p2]){//当nums1尾部值 > 当前要插入的值
            nums1[p] = nums1[p1];//将nums1尾部值向后推
            p--;//由于有值推后,所以插入位置提前
            p1--;//直到找到正确的插入位置
        }
        nums1[p] = nums2[p2];//执行插入操作
        p--;
        p2--;
    }
};
```
