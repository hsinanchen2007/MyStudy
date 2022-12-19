由于元素的数量超过元素的一半，所以将数组中的元素进行排序，中间的元素即为数量过半的元素
```
public int majorityElement(int[] nums) {
	Arrays.sort(nums);
	return nums[nums.length/2];
}
```
