### 解题思路
返回数组中位数为偶数的数字的个数，就要判断给定数组中每个数据元素的位数。让每个元素除以10，商不为0时就代表非个位数。将除以10的次数相加存为count，并在最后判断count能否被2整除。
（小菜鸟第一次写思路，捂脸逃emm~）
### 代码

```java
class Solution {
    public int findNumbers(int[] nums) {
        int res=0;
	for(int i=0;i<nums.length;i++) {
		int count=1;
		while(nums[i]/10!=0) {
			nums[i]/=10;
			count++;
		}
		if(count%2==0)  res++;
	}
	return res;
    }
}
```