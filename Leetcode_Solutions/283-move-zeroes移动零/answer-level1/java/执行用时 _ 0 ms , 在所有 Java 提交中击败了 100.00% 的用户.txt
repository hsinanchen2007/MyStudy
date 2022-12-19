定义一个快指针i，一个慢指针j,j永远指向下一个非零的数要放位置
当i位置不是0的时候，该数字给到nums[j]，同时i,j往后走
当i位置是0，i不进if，相当于忽略掉继续往前走，i相当于0无视往后找非0
找到一个非0，就给j位置，然后原来的i位置废掉 写成0，这样遍历到最后
所有非0都给了j，所有原来非0位置也都变成了0
```java
class Solution {
    public void moveZeroes(int[] nums) {
        int  j = 0;
	    for(int i=0;i<nums.length;++i){
	    	if(nums[i] != 0){
	    		nums[j] = nums[i];
	    		if(j != i) nums[i] = 0;
	    		j++;
	    	}
	    }
    }
}
```