### 解题思路
看到题目最简单的思路就是合并两个有序数组，然后直接求解，这样的时间复杂度是O(Max(m,n))，也就是扫描一遍最长数组的时间复杂度，当然牺牲了空间new了一个新数组来存储合并后结果。效果还行！
```
执行用时 :3 ms, 在所有 Java 提交中击败了 **88.49%** 的用户
内存消耗 :41.4 MB, 在所有 Java 提交中击败了 **97.54%** 的用户
```

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int unions[] = new int[nums1.length + nums2.length];
        //定义两个指针来合并两个有序数组
        int i = 0, j = 0, k = 0;
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] < nums2[j]) {
                unions[k++] = nums1[i++];
            } else {
                unions[k++] = nums2[j++];
            }
        }
        //两个数组长度不相等的时候必然有一个数组剩下一部分没有拷贝，接着拷贝剩下的部分
        if(i == nums1.length){
            while (j < nums2.length){
                unions[k++] = nums2[j++];
            }
        } else{
            while (i < nums1.length){
                unions[k++] = nums1[i++];
            }
        }
        //求中位数
        if(unions.length%2 != 0){
            return unions[unions.length/2];
        }
        return (unions[unions.length/2] + unions[unions.length/2 - 1])/2.0;
    }
}
```