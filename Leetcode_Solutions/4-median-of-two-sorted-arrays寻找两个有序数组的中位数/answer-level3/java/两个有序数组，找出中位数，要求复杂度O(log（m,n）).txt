### 解题思路
此处撰写解题思路
将这个问题看成分割问题,分别找到两个数组的分割点
aPart是数组1的分割点，bPart是数组2的分割点
两个切割点左右的四个边界值,必须满足num1[aPart-1]<num2[baprt] && num2[bPart-1]<num1
### 代码

```java
class Solution {
   public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.length == 0 && nums2.length == 0) {
            return 0;
        }
        if (nums1.length > nums2.length) {
            //交换位置
            int[] temp = nums2;
            nums2 = nums1;
            nums1 = temp;
        }
        int len1 = nums1.length;
        int len2 = nums2.length;
        int start = 0;
        int end = len1;
        int half = (len1 + len2 + 1) / 2;
        //判断两个数组加起来长度是否为偶数
        boolean even = (len1 + len2) % 2 == 0 ? true : false;
        while (start <= end) {
            //对短数组进行二分法查找
            int aPart = (start + end) / 2;  //先找到短数组的中间切割的位置，可能第一次不准，但是后续可以调整位置
            int bPart = half - aPart;
            if (aPart > 0 && nums1[aPart - 1] > nums2[bPart])
                end = aPart - 1; //aPart > start这个条件保证是在对两个数组进行切割，（由aPart=0推导出）避免数组A全部大于B的任意值
            else if (aPart <len1  && nums1[aPart] < nums2[bPart - 1])
                start = aPart + 1; //aPart < len1 这个条件也是同理，避免数组A全部小于B的任意值
            else {
                //获取左边的最大值
                int leftMax = 0;
                //先排除掉两种极端情况
                if (aPart == 0) leftMax = nums2[bPart - 1];  //数组A全部大于B的任意值
                else if (bPart == 0) leftMax = nums1[aPart - 1];  //数组B全部大于A的任意值
                else {
                    leftMax = Math.max(nums1[aPart - 1], nums2[bPart - 1]);
                }  //正常切割找两个切割点左右的四个边界值,必须满足num1[aPart-1]<num2[baprt] && num2[bPart-1]<num1[aPart]
                if (!even) return leftMax;  //奇数直接去左边的最大值

                //获取右边的最小值
                int rightMinx = 0;
                if (aPart == len1) rightMinx = nums2[bPart];
                else if (bPart == len2) rightMinx = nums1[aPart];
                else {
                    rightMinx = Math.min(nums1[aPart], nums2[bPart]);
                }
                return (leftMax + rightMinx)*1.0 / 2;
            }
        }
        return -1;
    }

}
```