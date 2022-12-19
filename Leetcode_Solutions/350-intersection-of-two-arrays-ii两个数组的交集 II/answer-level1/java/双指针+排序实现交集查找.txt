### 解题思路
双指针+排序实现交集查找

### 代码

```java
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        //两个数组进行从小到大排序
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        //初始化两个数组的指针
        int i = 0, j = 0, k = 0;
        while (i < nums1.length && j < nums2.length) {
            //如果数组1的数小于数组2的数，数组1就需要变大，即向右移动
            if (nums1[i] < nums2[j]) {
                i++;
            //如果数组1的数大于数组2的数，数组2就需要变大，即向右移动
            } else if (nums1[i] > nums2[j]) {
                j++;
            //相等的时候，就得出了交集的值，覆盖写回数组1 
            } else {
                nums1[k++] = nums1[i++];
                j++;
            }
        }
        //返回数组1 前k个数 即为公共交集
        return Arrays.copyOfRange(nums1, 0, k);
    }

}
```