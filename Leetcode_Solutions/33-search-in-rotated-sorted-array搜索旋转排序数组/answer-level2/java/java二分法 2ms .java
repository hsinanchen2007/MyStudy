也算误打误撞写出来的把，看到时间复杂度，有序的基本上就是二分法了。分了四种情况讨论，对nums[low]、nums[mid]、nums[high]三个位置的值讨论，找出左边还是右边是有序的序列，再移动low和high指针

![微信图片_20190709162133.jpg](https://pic.leetcode-cn.com/9138e86d34fc398c3deb400639c563ed676a1e0f184e66c2ed35deff261a05eb-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20190709162133.jpg)
```javascript []
class Solution {
   public int search(int[] nums, int target) {
		 if(nums.length==0)
			 return -1;
		 if(nums.length==1&&target!=nums[0])
			 return -1;
		 int low = 0;
		 int high = nums.length-1;
		 while(low<=high) {
			 int mid = (low+high)/2;
			 if(nums[mid]==target)
				 return mid;
			 if(nums[low]>nums[mid]) {
				 if(nums[mid]<target&&target<=nums[high]) {
					 low = mid+1;
				 }else
					 high = mid-1;
			 } else if(nums[high]<nums[mid]) {
				 if(nums[low]<=target&&target<nums[mid]) {
					 high = mid-1;
				 }else
					 low = mid+1;
			 }else if(target<nums[mid]) {
				 high = mid-1;
			 }else
				 low = mid+1;
		 }
		 return -1;
	 }
}
```



