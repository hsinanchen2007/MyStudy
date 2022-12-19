根据题意，记数组nums的长度为n。下面分**两种情况讨论**：

1. 如果数字n没在nums中出现的话，那么对于所有的0<=i<nums.length肯定nums[i]==i，即索引i处放置数字i，此时所求的缺失数字就是n,（即nums.length）
2. 而如果数字n出现在nums中(肯定是在最后一个位置)，那么前面的位置中必然会出现nums[i]!=i，那个i就是所求的缺失的数字

代码如下：
```java
class Solution{
    public static int missingNumber(int[] nums) {
	// res表示nums缺失的数字,初始化为nums.length
	int res = nums.length;
	for (int i = 0; i < nums.length; i++) {
	    if (nums[i]!=i) {
		    res = i;
		    break;
	    }
	}
	return res;
    }
}
```



