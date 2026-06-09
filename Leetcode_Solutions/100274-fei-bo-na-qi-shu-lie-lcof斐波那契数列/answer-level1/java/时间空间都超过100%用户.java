### 解题思路
基本思想就是算过一次的绝不算第二次



### 代码

```java
class Solution {
    public int fib(int n) {
        int[] nums = new int[n + 1];
		 f(n, nums);
		 return nums[n];
    }
    private int f(int n, int[] nums) {
		 if(nums[n] > 0)
			 return nums[n];
		 if(n == 0)
			 return nums[0] = 0;
		 if(n == 1) 
			 return nums[1] = 1;
		 return nums[n] = ((f(n - 1, nums)) % 1000000007 + (f(n - 2, nums)) % 1000000007) % 1000000007;
	 }
}
```