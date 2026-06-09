这个题是在最长递增子序列的题上的变形，求其个数。
刚开始想到的是定义一个length+1长度的count数组，每遇到一种长度情况就加1，然后WA，比如
1,2,4,3,5,4,7,2，最长递增序列有 1,2,4,5,7;1,2,3,5,7;1,2,3,4,7三种情况，但按之前的想法算出来只有两种情况。最后
结合别人的题解，理解如下：
1.还是求最长递增子序列
2.定义一个`int dp[] = new int[len]`用来求以`nums[i]`结尾的最长递增子序列的长度
3.定义一个`int count[] = new int[len];`用来求以`nums[i]`结尾的最长递增子序列的个数（也可以理解为表示递增子序列的组合方式）
4.两者之间的关系：对于i>j,nums[i]>nums[j]的时候，如果`dp[j]+1>dp[i]`，说明第一次找到`dp[j]+1`长度且以`nums[i]`结尾的最长递增子序列，则`count[i]=count[j]`（以`nums[i]`结尾的最长递增子序列的组合方式就等于`nums[j]`目前的组合方式）;
如果`dp[j]+1==dp[i]`说明这个长度的递增序列已找到过一次了，则`count[i]+=count[j]`（现有的组合方式个数加上count[j]的组合方式，即为总的组合方式个数）

以1,2,4,3,5,4,7,2为例：
初始化：`Arrays.fill(dp, 1);
		Arrays.fill(count, 1);`
因为每个元素都可以以自身为一个长度的子序列，所以dp初始化为1；
count也是以自身结尾的最长子序列的情况至少有一种，所以初始化为1。
```
for (int i = 0; i < len; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) {
					if (dp[j] + 1 > dp[i]) {
						dp[i] = Math.max(dp[j] + 1, dp[i]);
						count[i] = count[j];
					} else if (dp[j] + 1 == dp[i])
						count[i] += count[j];
				}
			}
			max = Math.max(max, dp[i]);
		}
```
- i=0时，比它小的没有，`dp[0]=1,count[0]=1`
- i=1时，nums[0]比它小，`dp[1]=2,count[1]=1`
- i=2时，nums[0]和nums[1]都比它小，最终`dp[2]=dp[1]+1=3,count[2]=1`
- i=3时，nums[0]和nums[1]都比它小，最终`dp[3]=dp[1]+1=3,count[3]=1`
- i=4时，前面的数都比它小，j=2时，`dp[4]=dp[2]+1=4,count[4]=1`；重点来了: j=3时，因为`dp[3]+1=4==dp[4]` 说明之前已经存在一种递增序列长度为4的情况了（1,2,4,5），而这个时候又有另一种组合跟nums[4]组合，可以形成长度为4的递增序列（1,2,3,5），因此count[4]就要更新了`count[4]=count[4]+count[3]=2` 
- 后面依次类推。
最终代码

```java []
public int findNumberOfLIS(int[] nums) {
		int len = nums.length;
		if (len == 0)
			return 0;
		int dp[] = new int[len];
		int count[] = new int[len];
		Arrays.fill(dp, 1);
		Arrays.fill(count, 1);
		int max = 0;
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) {
					if (dp[j] + 1 > dp[i]) {
						dp[i] = dp[j] + 1;
						count[i] = count[j];
					} else if (dp[j] + 1 == dp[i])
						count[i] += count[j];
				}
			}
			max = Math.max(max, dp[i]);//找出最长递增子序列的长度是多少
		}
		int ans = 0;
		for (int i = len - 1; i >= 0; i--) {
			if (dp[i] == max) {
				ans += count[i];
			}
		}
		return ans;
	}
```
