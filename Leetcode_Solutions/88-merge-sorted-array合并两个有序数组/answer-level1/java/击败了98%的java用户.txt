## 分析
从右往左排序，指定三个坐标pos = m + n - 1（最终被排在哪个位置）
s1 = m - 1（nums1的最右端), s2 = n-1(nums2的最右端)。
两个数组均从右向左比较，较大的放到pos位置。
## 代码
```java
public void merge(int[] nums1, int m, int[] nums2, int n) {
        int pos = m + n - 1;
        int s1 = m - 1;
        int s2 = n - 1;
        while (s1 >= 0 && s2 >= 0) {
            if (nums1[s1] >= nums2[s2]) {
                nums1[pos--] = nums1[s1--];
            } else {
                nums1[pos--] = nums2[s2--];
            }
        }
        while (s1 >= 0) {
            nums1[pos--] = nums1[s1--];
        }
        while (s2 >= 0) {
            nums1[pos--] = nums2[s2--];
        }

    }
```

# [更多leetcode题解写在本人博客](http://51leetcode.top/tags?tag=leetcode)