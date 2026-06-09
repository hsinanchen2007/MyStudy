### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   	 public static int searchInsert(int[] nums, int target) {
		 	if(nums.length==0)return 0;
		 	if(nums.length==1) {
		 		if(nums[0]>=target)return 0;
		 		return 1;
		 	}
		 	int temp=nums.length-1;
		 	if(target>nums[nums.length-1])return nums.length;
		 	while (target<=nums[temp]) {
				if(target==nums[temp]) {
					int tempA=temp-1;
					while (nums[temp]==nums[tempA]) {
						temp=tempA;
					}
					return temp;
                }
				temp--;
                if(temp==0){
                    if(nums[0]>=target)return 0;
		 		    return 1;
                }
				if(nums[temp]<target)return temp+1;
			}
		 	
	        return 0;
	    }
}
```