### 解题思路
和快速排序的基本思想差不多，测试用时击败100%


### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
	        int j =0;
	        int n= nums.length-1;
	        for(int i=0;i<n+1;i++){
	            if(nums[i]==val){
	               nums[i]=nums[n];
	               n--;
	               i=i-1;
	            }
	        }
	        return n+1;
	    }
}
```