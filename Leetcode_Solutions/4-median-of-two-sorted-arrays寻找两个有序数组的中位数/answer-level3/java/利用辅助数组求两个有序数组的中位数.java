### 解题思路
此处撰写解题思路
1、创建辅助数组help，长度等于(num1长度+nums2长度)/2+1,
2、从nums1和nums2向help数组赋值，谁小谁赋值
如果两个数组长度和为奇数，则数组最后一位是中位数，
如果两个数组长度和为偶数，则数组后两位的平均数是中位数，
### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        double res = 0.0;
        int len = nums1.length+nums2.length;
        boolean ty = len%2==0;
        int mid = len/2;
        int p1 = 0,p2 = 0;
        int [] help = new int[mid+1];
        int index = 0;
        while(index<=mid){
            if(p1<nums1.length&&p2<nums2.length){
                if(nums1[p1]<=nums2[p2]){
                    help[index++] = nums1[p1++];
                }else{
                    help[index++] = nums2[p2++];
                }
            }else if(p1<nums1.length){
                help[index++] = nums1[p1++];
            }else {
                help[index++] = nums2[p2++];
            }
        }
        if(ty){
            res = (help[mid]+help[mid-1])/2.0;
        }else{
            res = help[mid];
        }
        return res;
    }
}
```