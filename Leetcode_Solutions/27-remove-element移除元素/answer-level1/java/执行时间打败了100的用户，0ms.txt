### 解题思路
    这个题目和上一道删除有序数组中的重复元素题目非常相像，都是采用双指针的策略，其实可以说完全一样，只不过比较的对象从不定元素变成了一个确定的数值，难度上并无差异

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
         int c1=0;
	     int c2=0;
	     while(c2<nums.length)
	     {
	    	 if(nums[c2]!=val)
	    	 {
	    		 nums[c1++]=nums[c2++];
	    	 }
	    	 else
	    	 {
	    		 c2++;
	    	 }
	     }
		 return c1;
    }
}
```