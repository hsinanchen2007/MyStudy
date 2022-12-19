![image.png](https://pic.leetcode-cn.com/be35029e7b23a397fb11aa587161b57b8773184587ce33c5c66263fcbb1cc209-image.png)

基本思想为：
a:【1，6，8，9，10】
b:【2，4，7，8】
看到log级别时间复杂度 基本上要使用二分法，求最小的第k个数
基本思路：设置 k= （len1+len2）/2+1
每次对比 两个数组中 k/2 和 k-k/2 的位置
设k=5
第一次：
a:【1，6，8】【9，10】
b:【2，4】【7，8】
8>4  所以删除 b中的2，4 和 a中的9，10，因为这些都不可能是第k小的数
第二次 k = 5-2 = 3   b: 3/2=1   a:3-1=2
a: 【1，6】【8】
b: 【7】【8】
7>6 所以删除 a中的1，6 和b中的8
第三次 k= 3-2 = 1
a: [8]
b: [7]
8> 7  由于k=1，只要取较小的数，也就是第k小的数是7

以下是详细代码：
```
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len1 = nums1.length;
        int len2 = nums2.length;
        int k = (len1+len2)/2;
        if ((len1+len2)%2==1) {
            return findMinK(nums1, 0, len1-1, nums2, 0, len2-1, k+1)/1.0;
        } else {
            return (findMinK(nums1, 0, len1-1, nums2, 0, len2-1, k) + findMinK(nums1, 0, len1-1, nums2, 0, len2-1, k+1))/2.0;
        }
    }
    public static double findMinK(int[] a, int lowA, int highA, int[] b, int lowB, int highB, int k) {
        int len1 = highA - lowA + 1;
        int len2 = highB - lowB + 1;
        if (len1 > len2) {
            return findMinK(b, lowB, highB, a, lowA, highA, k);
        }
        if (len1 == 0) {
            return (double)b[lowB+k-1];
        }
        if (k==1) {
            return (double)Math.min(a[lowA],b[lowB]);
        }
        int na = Math.min(k/2, len1);
        int nb = k-na;
        if (a[na+lowA-1] < b[nb+lowB-1]) { 
            return findMinK(a, na+lowA, highA, b, lowB, nb+lowB-1, k-na);
        } else if (a[na+lowA-1] == b[nb+lowB-1]) {
            return (double)a[na+lowA-1];
        } else {
            return findMinK(b, nb+lowB, highB, a, lowA, na+lowA-1, k-nb);
        }
    }
}
```
