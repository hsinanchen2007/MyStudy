## 解题方案

### 思路

- 标签：从后向前数组遍历
- 因为 `nums1` 的空间都集中在后面，所以从后向前处理排序的数据会更好，节省空间，一边遍历一边将值填充进去
- 设置指针 `len1` 和 `len2` 分别指向 `nums1` 和 `nums2` 的有数字尾部，从尾部值开始比较遍历，同时设置指针 `len` 指向 `nums1` 的最末尾，每次遍历比较值大小之后，则进行填充
- 当 `len1<0` 时遍历结束，此时 `nums2` 中海油数据未拷贝完全，将其直接拷贝到 `nums1` 的前面，最后得到结果数组
- 时间复杂度：$O(m+n)$

### 代码


```Java []
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int len1 = m - 1;
        int len2 = n - 1;
        int len = m + n - 1;
        while(len1 >= 0 && len2 >= 0) {
            // 注意--符号在后面，表示先进行计算再减1，这种缩写缩短了代码
            nums1[len--] = nums1[len1] > nums2[len2] ? nums1[len1--] : nums2[len2--];
        }
        // 表示将nums2数组从下标0位置开始，拷贝到nums1数组中，从下标0位置开始，长度为len2+1
        System.arraycopy(nums2, 0, nums1, 0, len2 + 1);
    }
}
```

```JavaScript []
/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    let len1 = m - 1;
    let len2 = n - 1;
    let len = m + n - 1;
    while(len1 >= 0 && len2 >= 0) {
        // 注意--符号在后面，表示先进行计算再减1，这种缩写缩短了代码
        nums1[len--] = nums1[len1] > nums2[len2] ? nums1[len1--] : nums2[len2--];
    }
    function arrayCopy(src, srcIndex, dest, destIndex, length) {
        dest.splice(destIndex, length, ...src.slice(srcIndex, srcIndex + length));
    }
    // 表示将nums2数组从下标0位置开始，拷贝到nums1数组中，从下标0位置开始，长度为len2+1
    arrayCopy(nums2, 0, nums1, 0, len2 + 1);
};
```


### 画解

<![1.png](https://pic.leetcode-cn.com/2b89af59204b9e77445e33b9613be7f61bcd2a1b0a07c0bde2e2b50603d5efff-1.png),![2.png](https://pic.leetcode-cn.com/bc8d62acb39e43526e7844b62724f43d6193570d9952a96277f55b02cbe4e525-2.png),![3.png](https://pic.leetcode-cn.com/b72c52702e7b932eefbf0459630038a0120bf51cdf0f744bed7bdd317a739677-3.png),![4.png](https://pic.leetcode-cn.com/5b0376aed4cf530afc60594379b030511adb22661b4ba7892601d194b6426200-4.png),![5.png](https://pic.leetcode-cn.com/b6c3890911ddf36786125b65358174d75e1379c561b9dfa150039aacc41ce546-5.png)>

