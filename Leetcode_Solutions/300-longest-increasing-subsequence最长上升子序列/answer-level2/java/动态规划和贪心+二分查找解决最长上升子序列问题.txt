### 解题思路
## 解法一：动态规划（O(n^2)）
dp[i]表示以array[i]结尾的最长上升子序列的长度
dp[i] = max(dp[0] – dp[j]) + 1 (其中j < i 且 array[j] < array[i])
例： 1,7,3,5,9,4,8
（1）dp[i]的元素初值都为1
（2）dp[0]表示以1结尾的最长上升子序列的长度，为1 
（3）dp[1]表示以7结尾的最长上升子序列的长度:

*    看dp[0],因为array[0] < array[1],所以dp[1] = dp[0] + 1 = 2

（4）dp[2]表示以7结尾的最长上升子序列的长度:

    看dp[0],dp[1],只有array[0] < array[2]

    所以dp[2] = dp[0] + 1 = 2

（5）dp[3]表示以5结尾的最长上升子序列的长度:

    看dp[0],dp[1],dp[2],array[0] < array[3],array[2] < array[3]

    dp[0]和dp[2]中取最大值dp[2] = 2

    所以dp[3] = dp[2] + 1 = 3

（6）dp[4]表示以9结尾的最长上升子序列的长度:

    看dp[0],dp[1],dp[2],dp[3]

    array[0],array[1],array[2],array[3]都小于<array[4]

    dp[0],dp[1],dp[2],dp[3]中取最大值dp[3] = 3

    所以dp[3] = dp[3] + 1 = 4

（7）dp[5]表示以4结尾的最长上升子序列的长度:

    看dp[0],dp[1],dp[2],dp[3]，dp[4]

    array[0],array[2]小于<array[5]

    dp[0],dp[2]中取最大值dp[2] = 2

    所以dp[3] = dp[2] + 1 = 3

（8）dp[6]表示以8结尾的最长上升子序列的长度:

    看dp[0],dp[1],dp[2],dp[3],dp[4],dp[5]

    array[0],array[1],array[2],array[3],array[5]都小于<array[6]

    dp[0],dp[1],dp[2],dp[3],dp[5]中取最大值 3

    所以dp[3] = 3 + 1 = 4

(9)遍历完数组array,求dp数组中的最大值即为最长上升子序列的长度

## 解法二：贪心+ 二分查找（O(nlogn)）
对于以某一个数结尾的最长上升子序列，当然是结尾的数越小越好    

创建一个list,初始有一个元素array[0]

从下标为1处开始扫描数组array

如果比list中的最后一个数大，说明可构成上升子序列，直接加入到list中

如果比list中的最后一个数小，则找到list中第一个大于或等于这个数的元素替换

查找用二分查找实现

最终list的长度即为最长上升子序列的长度

### 代码

```java
    class Solution{
        //动态规划法
        public int lengthOfLIS(int[] array) {
            int[] dp = new int[array.length];
            Arrays.fill(dp, 1);
            for (int i = 1; i < dp.length; i++) {
                int max = 0;
                int j = 0;
                for (; j < i; j++) {
                    if(array[j] < array[i]) {
                        if(dp[j] > max) 
                            max = dp[j];
                    }
                }
                dp[i] = max + 1;
            }
            return maxInArray(dp);
        }

    public int maxInArray(int[] dp) {//返回dp数组中的最大值
		int max = 0;
		for (int i = 0; i < dp.length; i++) {
			if(dp[i] > max)
				max = dp[i];
		}
		return max;
	}
}
    


```



```java
class Solution {
    //贪心 + 二分查找 
    public int lengthOfLIS(int[] nums) {
        if(nums.length == 0)
            return 0;
        List<Integer> res = new ArrayList<>();//res中的元素保持升序
        res.add(nums[0]);
        for(int i = 1; i < nums.length; i++){
            if(nums[i] > res.get(res.size() - 1))
                res.add(nums[i]);
            else
                res.set(binarySearch(res, nums[i]), nums[i]);
        }
        return res.size();
    }

    public int binarySearch(List<Integer> res, int key){//找到list中第一个大于key的值，返回下标
        int l = 0;
        int r = res.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(res.get(mid) < key)  //注意：if else 的位置不能换
	                l = mid + 1;
	            else
	                r = mid - 1;
        }
        return l;

    }
}
```