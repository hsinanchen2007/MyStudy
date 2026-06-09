### 代码

```java
class Solution {
    public int rob(int[] nums) {
        int size = nums.length;
		if(size == 0){
			return 0;
		}
		int[] dp = new int[size];
		for(int i=0;i<size;i++){
			if(i == 0){
				dp[i] = nums[i];
				continue;
			}else if(i == 1){
				dp[i] = Math.max(nums[0], nums[1]);
				continue;
			}
			dp[i] = Math.max(dp[i-2]+nums[i], dp[i-1]);
		}
		return dp[size-1];
    }
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/10d032a04a96a4b84d8a719eba0298901598b4b7d14e71dbdcc67a0481cfa119-1.png)

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/7836eaf26cda9865cda51ea7ae9a81e947f1b81ae6641d13f94a23e55021a44f-wechat.png)

