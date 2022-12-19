### 解题思路
中位数的位置是在(num1.length+num2.length)/2附近。通过二分插入的方式，将一个数组的length填满至大于(num1.length+num2.length)/2。这里的排序只进行了中位数的前半部分。最后在取出中位数。
  但是后来一想java里的数组排序是基于双轴快排的方式（其实是我懒orz）。最后还是调用jdk（美滋滋~）。
  ps.代码里的时间复杂度是O(nlogn)。
### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] a=new int[nums1.length+nums2.length];
        int sum=nums1.length+nums2.length;

        double mid=0.0d;
        for(int i=0;i<nums1.length;i++) {
            a[i]=nums1[i];
        }
        for(int i=0;i<nums2.length;i++) {
            a[nums1.length+i]=nums2[i];
        }
        Arrays.sort(a);

        mid=sum%2==1?(double)a[sum/2]:(a[sum/2-1]+a[sum/2])/2.0f;
        return mid;
    }
}
```