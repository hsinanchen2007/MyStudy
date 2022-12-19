### 解题思路
首先说一下，这个方法实际上是归并排序的一种特殊优化，莫名其妙的用时短，估计是官方给的数据量还是太少
![0efcb6cad7da3bf96f2c4dbc5a3fd498.jpg](https://pic.leetcode-cn.com/d277c4499523c52f1d3993de39abe3835180389f7f05c6e7a79cc3a2e62e2d14-0efcb6cad7da3bf96f2c4dbc5a3fd498.jpg)


思路是这样，答案里很多人都是直接将两个数组拼接再排序，这就是走上歧途了，两个数组合并可以看成两个链表合并，而且在本题中，除了计算中位数需要的两个数，之前的数并不需要保存，所以实际上我们只需要合并到一半，找到我们需要的两个数就可以了。

空间复杂度:**O(1)**

时间复杂度:**O(m+n)**
### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int totalLength = nums1.length + nums2.length;
        boolean flag = false;
        int half = half = totalLength / 2 + 1;
        //确定数据的数量是偶数还是奇数
        if(totalLength % 2 == 0){
            flag = true;
        }
        int[] temp = new int[2];
        int p1= 0;
        int p2 = 0;
        while(half  > 0){
            temp[0] = temp[1];
            //两路数组都不为空
            if(p1 < nums1.length && p2 < nums2.length){
                if(nums1[p1] <= nums2[p2]){
                    temp[1] = nums1[p1];
                    p1++;
                }else{
                    temp[1] = nums2[p2];
                    p2++;
                }
            }else{
                //当有一路数组为空
                if(p1 < nums1.length){
                    temp[1] = nums1[p1];
                    p1++;
                }else if(p2 < nums2.length){
                    temp[1] = nums2[p2];
                    p2++;
                }
            }
            half--;
        }
        if(flag){
            return (temp[0]+temp[1])*1.0/2; 
        }else{
            return temp[1];
        }
    }
}
```