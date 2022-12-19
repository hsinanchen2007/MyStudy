### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
    	int mid = nums.length/2;
    	int start = 0;
    	int end =nums.length;
    	int n = 0;
    	if(nums.length!=0&&nums[end-1]>=target) {
    		while(nums[mid]<target) {
    			start = mid;//找到上边界
    			mid = (mid + end)/2;
    		}
    		if(nums[end-1]==target) {
    			 mid = end-1; //下边界
    		}else {
    			while(nums[mid]==target) {
    				mid = (mid + end)/2;
    			}
    		}
    		for(int i = start;i<mid+1;i++) {
    			if(nums[i]==target) {
    				n++;
    			}
    		}
    	}
    	return n;
    }
}
```