### 解题思路
此处撰写解题思路
注意最后的返回值应为double类型
### 代码

```java
class Solution {
    public double findMaxAverage(int[] nums, int k) {
        if(nums == null || nums.length < k)
            return 0;
        int i,j,sum = 0,t = 0;
		for(i = 0;i <= nums.length - k ;i++) {
			sum = 0;
			for(j = i;j < k + i;j++) {
				sum = sum + nums[j];
			}
			if(i == 0)	
				t = sum;
			else {
				t = t > sum ? t : sum;
			}
		}
		return (double)t/k;
    }
}
```