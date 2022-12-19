解题思路：定义两个指针，快指针与慢指针的前一位进行比较，若不相等则加入到数组中，若相等，快指针取代慢指针
最后返回的current+1就是数组的长度。
class Solution {
    public int removeDuplicates(int[] nums) {
       int current = 1;           
	   for (int i = 2; i < nums.length;i++) 
	{
		if (nums[i] != nums[current - 1]) 
		{
			current += 1;
			nums[current] = nums[i];
		}
	}
	return current+1;
    }
}