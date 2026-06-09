  非算法竞赛人，小白分享一下感想和做题的过程。
  这道题第一眼看到n在500以内，知道了用**排列树**一定会超时。
  最后的解法多半是贪心或者动态规划，大概率**动态规划**。
  但依照流程来看，找不到最优子结构。**每次戳气球都会影响之后戳的气球**，状态太多了。
  比如同样是戳数字5号，因为之前戳气球的情况不同，左右邻居不同，这意味着戳5号的情况不能复用。
  就这样想着，完全找不到思路。（后来发现是**被正向思维给限制了**）
  干想也没办法，直接用**动态规划的范式硬做**。
  nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
  想一下递归式，比如现在只剩1号，戳1号后，最后答案为 **戳完前面的3号+戳完后面5，8号+戳1号**，因为是最后戳1号，所以戳1号的值为 start*1号*end，戳前面和后面递归调用即可。一下就有思路了。原来**得逆向戳气球**，假设**最后一次戳气球是x**，这时因为只剩x没有邻居可以直接算出值为x，前面和后面的空缺再递归调用戳气球就可以了！
  其实反思过来**动态规划本身就是逆向的思维**，从最后一步往前推。
  我一直以为自己已经学会动态规划和递归了，没想到一道这么简单的题就把我卡住了，看来**思维方式**还不到位，还有很多地方需要努力！
![image.png](https://pic.leetcode-cn.com/2b164918cc7a1ff1f4c9d1911a757023abef40ed1766e1e9b4583e9d353953d2-image.png)

```
    public int maxCoins(int[] nums) {
        int[] newNums = new int[nums.length+2];
        int[][] dp = new int[newNums.length][newNums.length];
        newNums[0]=1;newNums[nums.length+1]=1;
        for(int i=0;i<nums.length;i++){
            newNums[i+1] = nums[i];
        }
        return maxCoins(newNums,0,newNums.length-1,dp);
    }
    public int maxCoins(int[] nums,int start,int end,int[][] dp){
        if(end - start == 1)return 0;
        if(dp[start][end] != 0)return dp[start][end];
        int max=0;
        for(int i=start+1;i<end;i++){
            max = Math.max(nums[i]*nums[start]*nums[end]+maxCoins(nums, start, i, dp)+maxCoins(nums, i, end, dp),max);
        }
        dp[start][end] = max;
        return max;
    }
```
