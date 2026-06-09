# 写在前面
    利用了桶思想。
	由题意知所有数字都在 0～n-1 的范围内，所以可以设置n个桶；
	由于只需要找出一个重复数字，所以可以将计数数组和元素组处理为同一个数组。这道题的特殊之处就在于不需要计数，一旦重复就返回重复值并结束程序。
    
![QQ截图20200213113930.png](https://pic.leetcode-cn.com/518966779366b448cd8d87752497c31e80399b83c94fd8400512392d21a6f921-QQ%E6%88%AA%E5%9B%BE20200213113930.png)

    这种方法性能上也比较理想
![QQ截图20200213123520.png](https://pic.leetcode-cn.com/5e4a4977d0bbb547729e4c1c444815d9804ba6149d37712f1582d13914241ba9-QQ%E6%88%AA%E5%9B%BE20200213123520.png)


```
class Solution {
    public int findRepeatNumber(int[] nums) {
		for(int i = 0;i<nums.length; i++) {
			while(nums[i] != i) {
				//索引i上的值如果和桶号为nums[i]上的值相等则出现重复值，直接返回；若没则进行交换
				if(nums[i] == nums[nums[i]])  
					return nums[i];
				swap(nums, i, nums[i]);
			}
		}
		//不能返回数值以免干扰结果，故抛错处理
		throw new IllegalArgumentException("没有找到重复数字");
	}
	private static void swap(int[] nums, int pre, int post) {
        int temp = nums[pre];
        nums[pre] = nums[post];
        nums[post] = temp;
    } 
}
```
