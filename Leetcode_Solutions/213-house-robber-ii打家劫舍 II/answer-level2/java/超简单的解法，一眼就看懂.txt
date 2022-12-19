**【历史重难点题目】**
* [历史重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)

**【核心思想】**
* 动态规划，状态转移方程`dp[i]=Math.max(dp[i-1],dp[i-2]+nums[i])`
* 围成一个圈意味着偷了第一个房屋，就不能偷最后一个房屋；偷了最后一个房屋，就不能偷第一个房屋。那么意味着第一个房子和最后一个房子中**只能选择一个偷窃**，因此可以把此环状排列房间问题约化为**两个单排排列房间子问题**


**【思路】**
* dp数组存储遍历到当前房屋时，所获得的最大金额。那么有两种情况
1. 前一个房屋偷了，那么当前的房屋就不能偷了，`dp[i]=dp[i-1]`
2. 前一个房屋不偷，那么可以偷当前的房屋，`dp[i]=dp[i-2]+nums[i]`

* 按相反的方向再来一次


**【代码】**
```java
public int rob(int[] nums) {
    if(nums.length==0)
        return 0;
    if(nums.length==1)
        return nums[0];
    int[] dp=new int[nums.length];

    dp[0]=nums[0];
    dp[1]=Math.max(nums[0],nums[1]);
    for(int i=2;i<nums.length-1;i++){
        dp[i]=Math.max(dp[i-1],dp[i-2]+nums[i]);
    }
    int max1=dp[nums.length-2];

    dp[0]=nums[nums.length-1];
    dp[1]=Math.max(nums[nums.length-1],nums[nums.length-2]);
    for(int i=2;i<nums.length-1;i++){
        dp[i]=Math.max(dp[i-1],dp[i-2]+nums[nums.length-1-i]);
    }

    return Math.max(max1,dp[nums.length-2]);
}
```


**【备注】**
* 该动态规划方法可以简化，用两个变量来代替dp数组

```java
 public int rob(int[] nums) {
    if(nums.length==0)
        return 0;
    if(nums.length==1)
        return nums[0];
    int[] dp=new int[nums.length];

    int a=nums[0];
    int b=Math.max(nums[0],nums[1]);
    for(int i=2;i<nums.length-1;i++){
        int temp=b;
        b=Math.max(b,a+nums[i]);
        a=temp;
    }
    int max1=b;

    a=nums[nums.length-1];
    b=Math.max(nums[nums.length-1],nums[nums.length-2]);
    for(int i=2;i<nums.length-1;i++){
        int temp=b;
        b=Math.max(b,a+nums[nums.length-1-i]);
        a=temp;
    }

    return Math.max(max1,b);
}
```


**【关注公众号，带你拿大厂offer】**
![logo_gif.gif](https://pic.leetcode-cn.com/d30a87d7c89a9557dd954511862915394db725b37caca7933bb93cc586f1b836-logo_gif.gif)

