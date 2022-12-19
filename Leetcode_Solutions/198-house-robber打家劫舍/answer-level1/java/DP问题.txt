### 解题思路
有些思路了，不过代码方面细节还存在问题*f[i] = Math.max(f[i-1], f[i-2]+nums[i-1]);*

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        int len = nums.length;
		if(len == 0)
			return 0;
		if(len == 1)
			return nums[0];
		//f[i] = max(f[i-1], f[i-2]+nums[i])
		int[] f = new int[len+1]; //f[i]表示打劫前i家 
		f[0] = 0;
		f[1] = nums[0];
		int max = 0;
		for (int i = 2; i <= len; i++) {
			f[i] = Math.max(f[i-1], f[i-2]+nums[i-1]);
			if(f[i] > max) {
				max = f[i];
			}
		}
		return max;
    }
}
```
![image.png](https://pic.leetcode-cn.com/af937a9ef50702f80a96cab80aa6b4d67bcf874ba33cdd57e5c90e6f8189543c-image.png)
