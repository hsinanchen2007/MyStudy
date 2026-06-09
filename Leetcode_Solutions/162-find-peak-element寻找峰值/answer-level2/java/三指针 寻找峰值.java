### 解题思路
多指针，线性扫描
需要理解nums[-1] 和 nums[n] 等于 负无穷大

当组数长度小于3时，单独处理，找出最大那个数的数组下标即可
当数组长度大于等于3时，采用三个指针滑动，只要找到第一个符合条件的就返回

如果遍历过程没有返回，那么这个数组要么严格增序，要么严格逆序(nums[i] != nums[i+1])
此时返回判断第一个和最后一个数值谁大就返回谁的下标。

### 代码

```java
class Solution {
    public int findPeakElement(int[] nums) {
    	
        if(nums.length == 1)
        {
        	return 0;
        }
        
        if(nums.length == 2)
        {
        	if(nums[0] > nums[1])
        	{
        		return 0;
        	}
        	else
        	{
        		return 1;
        	}
        }
        
        int posThird = 2;
        do
        {
        	if(nums[posThird - 1] > nums[posThird - 2] && nums[posThird - 1] > nums[posThird])
        	{
        		return posThird - 1;
        	}
        	posThird++;
        }while (posThird < nums.length);
        
        if(nums[nums.length - 1] > nums[0])
        {
        	return nums.length - 1;
        }
        else
        {
        	return 0;
        }
    }
}
```