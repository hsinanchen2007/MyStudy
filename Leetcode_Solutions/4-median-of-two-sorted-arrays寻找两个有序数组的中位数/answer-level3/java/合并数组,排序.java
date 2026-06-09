### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        double result = 0;
    	int n1=nums1.length;
    	int n2=nums2.length;
    	int n = n1+n2;
    	int [] nums3= new int[n];
    	System.arraycopy(nums1, 0, nums3, 0, nums1.length);
    	System.arraycopy(nums2, 0, nums3, nums1.length, nums2.length);
    	Arrays.sort(nums3);
    	int mid =n/2;
    	if(n%2==0) {
    		result = (nums3[mid-1]+nums3[mid])/2;
    		if((nums3[mid-1]+nums3[mid])%2!=0) {
    			result+=0.5;
    		}
    	}else {
    		result = nums3[mid];
    	}
    	return result;
    }
}
```