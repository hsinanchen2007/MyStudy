从后往前遍历，找到第一个下降的值nums[i]，和之后刚刚大于这个值的nums[j]交换位置。再对i之后的进行排序。
```
public void nextPermutation(int[] nums) {
    int temp;
    for (int i = nums.length - 2; i >= 0; i--) {
        for (int j = nums.length - 1; j > i; j--) {
        	if(nums[i] < nums[j]) {
        		temp = nums[i];
    			nums[i] = nums[j];
    			nums[j] = temp;
    			Arrays.sort(nums, i + 1, nums.length);
    			return;
        	}
		}	
	}
     Arrays.sort(nums);
}
```


