### 解题思路
该题有些许类似于斐波那契数列算法，有多种思路，采用动态规划的思想着手。
可以注意到nums[n]中，**无论有多少种数字组合，一定以数组中某一元素作为结束元素**。
设立dp[n]数组，对于nums数组第i个元素，可以假设i-1已经存放了以nums[i]结尾的最大和，
若nums[i-1]<0,则只要包含前面的数据，一定会变小,所以直接抛弃前面数据，以nums[i]为最大和。

分析完后，每次只需要判断以i-1结束的数据和的最大值正负即可，所以采用pre单个变量存储即可。



### 代码

```c
//#define MAX(a,b) ((a)>(b)?(a):(b))
//O(n)算法
int maxSubArray(int* nums, int numsSize){
    if(!numsSize) return 0;
    int i=0;//dp[numsSize+1];
    int max=nums[0];//max存最大和
    int pre = nums [0];//pre存 i-1 结尾的最大和
    for(i=1;i<numsSize;i++)
    {
        if(pre>=0)
            pre+=nums[i]; //若i-1结尾最大和为正，可以继续利用
        else
            pre = nums[i];  //若为负，则抛弃不用，新开一局
        //max=MAX(max,pre); 
        if(pre>max)
            max=pre;          
    }
    return max;
}



```