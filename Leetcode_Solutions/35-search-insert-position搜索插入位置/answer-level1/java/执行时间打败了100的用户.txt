### 解题思路
    不得不说，双指针这个思路非常牛逼，恨自己没有早点掌握这个简单的方法，这道题的解题思路不需要我多说，大家看到代码就一清二楚了。

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        if(target<nums[0])
	    	  return 0;
	      if(target>nums[nums.length-1])
	    	  return nums.length;
		  int c1=0;
		  int c2=1;
		  while(c2<nums.length)
		  {
		  if(nums[c1]==target)
		  {
			 return c1;
		  }
		  else if(nums[c2]==target)
		  {
			  return c2;
		  }
		  else if(nums[c1]<target&&nums[c2]>target)
		  {
			  return c2;
		  }	   
			  c1++;
			  c2++;
		  }
		return 0;
    }
}
```