# 思路
使用桶的思路，用空间换时间
- 因为nums1是nums2的子集，所以算出nums2的最大值和最小值就可以确定桶的大小。
- 但需要注意的是，因为值可能是负数，所以桶的大小:
    - 如果min是负数，桶的大小就是**最大值和最小值的绝对值中大的那个的2倍+1**
    ```java
    max = Math.max(Math.abs(max), Math.abs(min));
    int[] buckets = new int[max + 1];
    ```
    - 如果min是正数，桶的大小就是**max + 1**
    - +1 因为有0
- 把nums2的元素作为桶的下标，nums2的下标做元桶的元素，放入桶中:
    - 如果是有负数的，下标就是在值的基础上+max
    - 如果是没有，下标就直接是这个值
- 记录结果的过程：
    - 遍历nums1，以nums1的元素作为下标查找bucket中存的nums2中相同元素的下标index
    - 从index开始遍历nums2：
        - 记录大于nums1的元素
        - 没有则记录-1
- 遍历结束，返回结果
# 代码
```java[]
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        if (nums1 == null || nums1.length == 0) {
            return new int[0];
        }
        
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;

        for (int num : nums2) {
            min = Math.min(min, num);
            max = Math.max(max, num);
        }

        max = Math.max(Math.abs(min), Math.abs(max));

        boolean hasNeg = false;
        int[] buckets;
        if (min < 0) {
            hasNeg = true;
            buckets = new int[max * 2 + 1];
        } else {
            buckets = new int[max + 1];
        }

        for (int i = 0; i < nums2.length; i++) {
            if (hasNeg) {
                buckets[nums2[i] + max] = i;
            } else {
                buckets[nums2[i]] = i;
            }
        }

        for (int i = 0; i < nums1.length; i++) {
            int index, num = nums1[i];
            if (hasNeg) {
                index = buckets[num + max];
            } else {
                index = buckets[num];
            }

            boolean find = false;
            for (int j = index; j < nums2.length; j++) {
                if (nums2[j] > num) {
                    nums1[i] = nums2[j];
                    find = true;
                    break;
                }
            }

            if (!find) {
                nums1[i] = -1;
            }
        }

        return nums1;
    }
}
```