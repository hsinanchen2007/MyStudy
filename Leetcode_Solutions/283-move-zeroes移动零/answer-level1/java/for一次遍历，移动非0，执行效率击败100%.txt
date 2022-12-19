使用for循环一次遍历数组，利用 nums[i]!=0判断语句， 将非0的数据覆盖到前pre的位置，因数组除了0就是非0，那么剩下的pre位开始到结束的数据都为0，直接从pre开始付值即可。


```
class Solution {
    public void moveZeroes(int[] nums) {
        int pre=0;
 
        for (int i = 0; i < nums.length; i++) {
			if (nums[i]!=0) {
				nums[pre]=nums[i];
				pre++;
			}
			
		}
        for (int i = pre; i < nums.length; i++) {
			nums[i]=0;
		}
       
       
    }
}
```

