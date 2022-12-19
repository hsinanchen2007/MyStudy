### 解题思路
我将集合重叠与不重叠分来处理，现在不知道复杂度满足不满足题意，过是通过了
### 代码

```java
class Solution {
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {

		double mid = 0.0;
		if((nums1 == null || nums1.length ==0 ) && nums2 != null){
			if((nums2.length & 1) == 0){
				mid = ((double)nums2[nums2.length/2]+(double)nums2[(nums2.length/2)-1])/2.0;
				
			}else{
				mid = nums2[nums2.length/2];
			}
			return mid;
		}else if(nums1 != null && (nums2==null || nums2.length==0)){
			if((nums1.length & 1) == 0){
				mid = ((double)nums1[nums1.length/2]+(double)nums1[(nums1.length/2)-1])/2.0;
				
			}else{
				mid = nums1[nums1.length/2];
			}
			return mid;
		}
		int l1 = nums1.length,l2 = nums2.length;
		if(nums1.length < nums2.length){
			if(nums1[nums1.length-1]<nums2[0]){
				int tmid = ((l1+l2)/2)-nums1.length;
				if(((l1+l2)&1)==0){
					mid = ((double)nums2[tmid]+(double)nums2[tmid-1])/2.0;
				}else{
					mid = nums2[tmid];
				}
			}else if(nums1[0]>nums2[nums2.length-1]){
				int tmid = (l1+l2)/2;
				if(((l1+l2)&1)==0){
					mid = ((double)nums2[tmid]+(double)nums2[tmid-1])/2.0;
				}else{
					mid = nums2[tmid];
				}
			}else{
				int [] nums = merge(nums1,nums2);
				int tmid = nums.length/2;
				if((nums.length & 1) == 0){
					mid = ((double)nums[tmid]+(double)nums[tmid-1])/2.0;
				}else{
					mid = nums[tmid];
				}
			}
			return mid;
		}else if(nums1.length>nums2.length){
			if(nums2[nums2.length-1]<nums1[0]){
				int tmid = ((l1+l2)/2)-nums2.length;
				if(((l1+l2)&1)==0){
					mid = ((double)nums1[tmid]+(double)nums1[tmid-1])/2.0;
				}else{
					mid = nums1[tmid];
				}
			}else if(nums2[0]>nums1[nums1.length-1]){
				int tmid = (l1+l2)/2;
				if(((l1+l2)&1)==0){
					mid = ((double)nums1[tmid]+(double)nums1[tmid-1])/2.0;
				}else{
					mid = nums1[tmid];
				}
			}else{
				int [] nums = merge(nums1,nums2);
				int tmid = nums.length/2;
				if((nums.length & 1) == 0){
					mid = ((double)nums[tmid]+(double)nums[tmid-1])/2.0;
				}else{
					mid = nums[tmid];
				}
			}
			return mid;
		}else{
			if(nums1[nums1.length-1]<nums2[0]){
				mid = ((double)nums1[nums1.length-1]+(double)nums2[0])/2.0;
			}else if(nums1[0]>nums2[nums2.length-1]){
				mid = ((double)nums1[0]+ (double)nums2[nums2.length-1])/2;
			}else{
				int [] nums = merge(nums1, nums2);
				int tmid = nums.length/2;
				if((nums.length & 1) == 0){
					mid = ((double)nums[tmid]+(double)nums[tmid-1])/2.0;
				}else{
					mid = nums[tmid];
				}
			}
			return mid;
		}
    }

	private static int[] merge(int[] nums1, int[] nums2) {
		int newLength = nums1.length+nums2.length;
		int [] nums = new int[newLength];
		int index = 0;
		int i=0,j=0;
		while(i<nums1.length && j<nums2.length){
			if(nums1[i]<=nums2[j]){
				nums[index] = nums1[i];
				i++;
				index++;
			}else{
				nums[index] = nums2[j];
				j++;
				index++;
			}
		}
		
		while(i<nums1.length){
			nums[index++] = nums1[i++];
		}
		while(j<nums2.length){
			nums[index++] = nums2[j++];
		}
		return nums;
	}
}
```