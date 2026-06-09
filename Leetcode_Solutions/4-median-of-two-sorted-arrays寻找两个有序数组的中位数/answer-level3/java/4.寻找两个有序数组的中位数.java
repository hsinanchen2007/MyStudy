### 解题思路
	本题目寻找两个有序数组的中位数，即两个数组是有序的，那么我们直接将其合并成一个新的有序数组，然后找新数组中间位置的数，如果新数组长度为奇数，则中位数为中间的一位数，否则为中间的两位数。

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
		int[] nums = new int[nums1.length+nums2.length];
		
		int i=0;
		int j=0;
		int k=0;
		while(i<nums1.length&&j<nums2.length) {
			if(nums1[i]<nums2[j]) nums[k++]=nums1[i++];
			else nums[k++]=nums2[j++];
		}
		
		while(i<nums1.length) nums[k++]=nums1[i++];
		while(j<nums2.length) nums[k++]=nums2[j++];

		double sum=0;//1 1
		if(nums.length%2==1) sum=nums[nums.length/2];
		else sum=1.0*(nums[nums.length/2]+nums[nums.length/2-1])/2;
		
		return sum;
    }
}
```