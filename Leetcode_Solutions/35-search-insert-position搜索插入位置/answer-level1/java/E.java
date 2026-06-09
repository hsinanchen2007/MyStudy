### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
           int len=nums.length;
		   for(int i=0;i<len;i++){
			   if(nums[i]==target){
				   return i;
			   }else if(nums[i]>target){
				   return i;
			   }
		   }
		   return len;

    }
}
```