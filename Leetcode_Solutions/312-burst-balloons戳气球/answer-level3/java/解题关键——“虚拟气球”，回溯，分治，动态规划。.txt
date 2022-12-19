## 1. 解题思路

### 1.1 回溯法

对于求[3, 1, 5, 8]的最大得分，第一次戳破气球有4种情况，假设首先戳破一个气球5，则，问题变成了求[3, 1, 8]的最大得分，问题规模减小一个元素。我们可以想到，采用递归的方法，减而治之，无球可戳后再回溯，当我们回溯完所有的戳法之后，就能找出最大得分。但是该回溯法的时间复杂度显然为O(n!)，而气球个数的取值为[0,500]，必然会有超时的问题。因此我们需要另寻它法。回溯法代码贴在最后。

### 1.2 递归-分而治之
首先思考能不能直接将[3, 1, 5, 8]直接分为类似于[3]、[1, 5, 8]这样两个子问题。这意味着，我们强行认为必须戳完[3]才能戳[1, 5, 8]，或者戳完[1, 5, 8]才能戳[3]，显然这不科学。即这两个子问题之间产生了依赖。
如何消除依赖呢？我们一开始的想法是先假设第一个被戳爆的气球为x，则x两边的气球则产生了依赖；那我们假设不戳爆x，则x两边的气球就没有了依赖关系！这个气球x，我们可以放在最后戳爆它。
这样，对于[3, 1, 5, 8]，假设最后戳爆5，则问题就被划分为如下图所示的两个子问题和一个O(1)的问题。

![image-20200113220939412.png](https://pic.leetcode-cn.com/f91cf0d4f03e32737908aae3d8967f438b2bd2d064a86e0a9e6961cf69769b55-image-20200113220939412.png)

其中，灰色元素表示**不可戳，仅供计分**的“虚拟气球”。而且虚拟气球的值仅与位置有关。假设f(start, end)表示从第start到end个气球的最大得分，nums[i]表示气球上的值，nums[start-1]和nums[end+1]是“虚拟气球”则有：

`f(start, end) = max{f(start,i-1) + nums[start-1]*nums[i]*nums[end+1] + f(i+1,end) ,其中i取值为[start,end]}`

递归结束条件是，start>end。

递归时，我们可以将f[start,end]的值通过二维数组缓存起来。


``` java
class Solution{ //分治法 8ms 72.11 % 
    public int maxCoins(int[] nums){
        cache = new int[nums.length][nums.length];
        for(int i = 0;i<nums.length;i++){
            for(int j = 0;j<nums.length;j++){
                cache[i][j] = -1;
            }
        }
        int result = getMaxCoins(nums,0,nums.length-1);
        return result;
    }
    int[][] cache;
    int getMaxCoins(int[] nums, int start,int end){
        //结束条件
        if(start <= end){
            if(cache[start][end] != -1)
                return cache[start][end];
        }
        if(start == end){
            int result = (start-1<0  ? 1 : nums[start-1]) * nums[start] * (end+1>nums.length-1 ? 1 : nums[end+1]);
            return result;
        }
        int i;
        //状态转移方程
        int maxCoins = 0;
        int temp = 0;
        for(i=start; i<=end;i++){
            temp = (start-1<0 ? 1 : nums[start-1])*nums[i]*(end+1>nums.length-1 ? 1 : nums[end+1]) + getMaxCoins(nums,start,i-1) + getMaxCoins(nums,i+1,end);
            maxCoins = Math.max(maxCoins,temp);
        }
        if(end>=start){
            cache[start][end] = maxCoins;
        }
        return maxCoins;
    }
}


```



### 1.3 迭代-动态规划（继续1.2，自底而上思考）

可将1.2中的缓存表作为DP表，填表即可。通过从最小子问题开始进行简单尝试，可以发现长度为2的子问题的解仅依赖于长度为1子问题的解；长度为3的子问题的解仅依赖于长度为2的子问题的解......

填表过程如下。

![image-20200113223111619.png](https://pic.leetcode-cn.com/ea1c8224509d5ab9af5c52e7b1928d9a7e777458dfa4c86f37de7258cad54fd6-image-20200113223111619.png)

代码如下，注意沙雕测试用例空数组2333

``` Java
class Solution{ //动态规划 5ms 99.82 %
    public int maxCoins(int[] nums){
        int dp[][] = new int[nums.length][nums.length];
        if(nums.length == 0){  //沙雕测试用例[]
            return 0;
        }
        for(int i = 0; i<nums.length; i++){
            for(int j = 0;j<nums.length-i;j++){
                fill(dp,nums,j,j+i);
            }
        }
        return dp[0][nums.length-1];
    }
    void fill(int[][] dp,int nums[],int start,int end){
        int max = 0;
        for(int i=start; i<=end;i++){
            max = Math.max(max,(start-1<0 ? 1 : nums[start-1])*nums[i]*(end+1>nums.length-1 ? 1 : nums[end+1]) + (start>i-1 ? 0 : dp[start][i-1]) + (end < i+1 ? 0 : dp[i+1][end]));
        }
        dp[start][end] = max;
    }
}
```



### 附. 回溯法代码

``` Java
class Solution {  //O(n!) 超时
    public int maxCoins(int[] nums) {
        int[] state = new int[nums.length];
        for(int i = 0;i<nums.length;i++){
            state[i] = 0;
        }
        tryGetCoins(nums,state,0);
        return max;
    }

    int max = 0;
    void tryGetCoins(int[] nums, int[] state,int current){
        int[] tempState = state.clone();
        int i = 0;
        if(finished(state)){
            max = Math.max(max,current);
            return;
        }
        for(i=0;i<nums.length;i++){
            if(state[i] == 1)
                continue;
            tempState[i] = 1;
            tryGetCoins(nums,tempState,current+getCoinsAt(nums,state,i));
            copyArray(tempState,state);
        }
    }
    int getCoinsAt(int[] nums,int[] state,int i){
        int j = 0,result = nums[i];
        for(j = i-1;j>-1;j--){
            if(state[j] == 0){
                result *= nums[j];
                break;
            }
        }
        for(j = i+1;j<state.length;j++){
            if(state[j] == 0){
                result *= nums[j];
                break;
            }
        }
        return result;
    }
    void copyArray(int[] dest,int[] origin){
        for(int i = 0; i<dest.length;i++){
            dest[i] = origin[i];
        }
    }
    boolean finished(int[] state){
        boolean finished = true;
        for(int i = 0; i < state.length;i++){
            if(state[i] == 0)
                finished = false;
        }
        return  finished;
    }
}
```