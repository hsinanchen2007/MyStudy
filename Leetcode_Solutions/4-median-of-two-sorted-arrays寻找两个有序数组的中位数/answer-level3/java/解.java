### 解题思路
先判断两个数组是否都是空，是的话返回0
紧接着定义一个数组用来存放nums1和nums2的数据->通过使用Arrays.copyOf(),然后通过sort将里面数据排序
接着就用if来判断
当数据总量为奇数时，采用nums[nums.length/2]就可以定位到其中位数
当数据总量为偶数时，采用(nums[nums.length/2]+nums[nums.length/2-1])/2.0就可以定位到其中位数
如果其中一个数组为空，那么判断是哪一个数组为空然后方法是一样的
### 代码

```java
class Solution {
   public double findMedianSortedArrays(int[] nums1, int[] nums2) {
	if (nums1.length == 0 && nums2.length == 0) {
			return 0;
		}
		int nums[] = Arrays.copyOf(nums1, nums1.length + nums2.length);
		System.arraycopy(nums2, 0, nums, nums1.length, nums2.length);
		Arrays.sort(nums);
		double a = 0;
		if((nums1==null||nums1.length==0)&&nums.length%2==0) {
			a = (nums[nums.length / 2] + nums[nums.length / 2 - 1]) / 2.0;
		}
		else if((nums2==null||nums2.length==0)&&nums.length%2!=0){
			a = nums[nums.length / 2];
		}
		if (nums.length % 2 == 0) {
			a = (nums[nums.length / 2] + nums[nums.length / 2 - 1]) / 2.0;
		} else if (nums.length % 2 != 0) {
			a = nums[nums.length / 2];
		}
		return a;

	}
}
```