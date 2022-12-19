### 解题思路
此处撰写解题思路
从前往后扫描：当碰到负数时，也不怕，只要当前的和仍为正数，就继续（期望后面会加回来），但是我的最大值会存在res变量里，并且每次循环都看看current有没有变大，如果变大了就更新；
如果当前current变成了负数，那这一串数没必要要了，从下一个新数重新开始。
想法还是很巧妙的！！
### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
		int len = nums.length;
		int res = nums[0];
		int current = nums[0];
		for (int i=1; i<len; i++) {
			if (current<0) current = nums[i];
			else current+=nums[i];
			if (current>res) res = current;
		}
		return res;
    }
}
```