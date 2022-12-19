首先，符合两个特征就可以使用动态规划来求解：
1. 具有重叠子问题，也就是对于某些小的问题有好多重复的计算，**这点就和分治法有明显的区别**
2. 具有最优子结构的特性，也就是原问题的最优解可以由子问题的最优解构成
来分析一下这个题，首先，想到的肯定是递归来做，就是先选择戳破一个气球，然后从剩下的气球中再选择一个戳破，这样求出所有的收益的和与结果比较，返回一个较大者，来举一个例子，例如对于[3,1,5,8],它所对应的递归树如下
![image.png](https://pic.leetcode-cn.com/852ca9fdd96819b8f5fdc0b42be8922090ad13605b770982ded8f71eb450b5a8-image.png)
可以发现这其中是有重叠子问题的，并且原问题的最优解来自于子问题的最优解，故可以使用动态规划来解决,我先贴出来对于这道题的递归回溯的写法，肯定是超时的。

### 1. 递归回溯解法（超时）
```
class Solution {
    //设置一个res保存最后的结果
	int res;
	
	//cur保存当前的收益
    void dfs(List<Integer> set,int cur) {
    	//如果集合为空了，说明没有气球了，这时用cur和res进行比较，将较大者赋值给res
    	if(set.size()==0) {
    		res=Math.max(res,cur);
    		return;
    	}
    	
    	//遍历所有要扎爆的气球
    	for(int i=0;i<set.size();i++) {
    		//获得当前气球的左右的气球的价值
    		int l=i-1<0?1:set.get(i-1);
    		int r=i+1==set.size()?1:set.get(i+1);
    		
    		//维护cur的值
    		cur+=(l*set.get(i)*r);
    		
    		//将这个元素删除，继续dfs
    		List<Integer> oth=new ArrayList<Integer>();
    		for(int j=0;j<set.size();j++) {
    			oth.add(set.get(j));
    		}
    		oth.remove(i);
    		
    		dfs(oth, cur);
    		cur-=(l*set.get(i)*r);
    	}
    }
	
	
    public int maxCoins(int[] nums) {
        //获得当前气球的个数
    	int n=nums.length;
    	
    	if(n==0) return 0;
    	
    	//将气球的价值放到一个list集合中
    	List<Integer> set=new ArrayList<Integer>();
    	for(int i=0;i<nums.length;i++) {
    		set.add(nums[i]);
    	}
    	
    	res=Integer.MIN_VALUE;
    	
    	//进行回溯深搜
    	dfs(set,0);
    	
    	return res;
    }
}
```
### 2.动态规划（通过）
我们来分析一下按照上面的那个递归的思路状态转移方程能写吗？如果按照上面的递归的思路，我们定义dp[i][j]表示对于i-j的气球的最大的收益，那状态转移方程就是dp[i][j]=max(coins[k]*coins[k-1]*coins[k+1]+dp[i][k-1]+dp[k+1][j]) k∈[i,j],就按上面的那个例子，[3,1,5,8],来写一下过程
扎爆3   剩下[]和[1,5,8]
扎爆1   剩下[3]和[5,8]
扎爆5   剩下[3,1]和[8]
扎爆8   剩下[3,1,5]和[]
然后在这些里面找到一个最大值返回，这其中对于扎爆3和8的最大的收益这样定义是没有问题的，因为两者都在边界，但是对于扎爆1和5就有问题了，就拿先扎爆1来说，扎爆1，剩下的最大的收益变为了[3]和[5,8]这两个区间的最大的收益的和，这个肯定不对，因为剩下的[3,5,8]区间的最大的收益的和不会是[3]的最大收益和与[5,8]的最大收益和的总和构成的，所以这个状态转移方程是不对的，那应该怎么定义状态转移方程呢，这也就是这道题巧妙的地方，它使用逆向思维，也就是上面的状态转移方程是由某个气球先爆得出来的，那么这里我们让指定的气球最后爆，这样的话状态转移方程为dp[i][j]=max(coins[k]*coins[i-1]*coins[j+1]+dp[i][k-1]+dp[k+1][j]) k∈[i,j]，再来看上面的例子，就对了，也就是对于[i,j]的气球，我们让某个位置的气球最后再爆，求出它左区间的最大的收益和右区间的最大的收益，加上这个气球最后爆掉所获得的收益，一 一比较，返回一个最大值就好了，这里要注意的是，要按区间的长度来进行状态的转移，也就是先求长度为1的，然后2的依次类推，因为这里状态转移方程涉及到了当前位置的后面的区间的最大的收益，但是后面的区间的长度是小于当前区间的长度的，故应该按长度来进行状态的转移。

```
class Solution {
    public int maxCoins(int[] nums) {
        int n=nums.length;
        
        //如果数组中没有气球，返回0
        if(n==0) return 0;
        
        if(n==1) return nums[0];
        
        //这里扩展一下nums数组，便于之后的计算
        int[] num=new int[n+2];
        Arrays.fill(num,1);
        for(int i=1;i<=n;i++){
            num[i]=nums[i-1];
        }
        
        //初始化dp数组
        int[][]dp=new int[n+2][n+2];
        
        //这里要对于每一个长度进行计算
        for(int len=1;len<=n;len++){
            for(int i=1;i<=n-len+1;i++){
                int j=i+len-1;
                for(int k=i;k<=j;k++){
                    dp[i][j]=Math.max(dp[i][j],dp[i][k-1]+dp[k+1][j]+num[k]*num[i-1]*num[j+1]);
                }
            }
        }  
        
        return dp[1][n];
    }
}
```


### 有不足希望dalao们可以指出，一定积极改正

