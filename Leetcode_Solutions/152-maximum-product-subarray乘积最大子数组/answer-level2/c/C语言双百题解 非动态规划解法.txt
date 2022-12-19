给出一列数 其中包含正负数但不包含0 
如果负数的个数是偶数 
则其乘积最大连续子序列之积应是整个序列之积
如果负数的个数是奇数 
设第一个负数出现的位置是Min
最后一个负数出现的位置是Max
则其乘积最大连续子序列之积应在max(s[Max-1],s[len]/s[Min])中取(s[i]为前缀积)
若该列数中包含0
则该列数中等于0的位置将该列数分成若干段 求出每一段的最大连续子序列之积 再从中选出最大的值
注意边界条件

完整代码如下：
```
int max(int a,int b){
if(a>b) return a;
return b;}
int maxProduct(int* nums, int numsSize){
int i,j,k;
int flag=0; 
int Max,Min;
int MAX=nums[0];
for(i=1;i<numsSize;i++)
MAX=max(MAX,nums[i]);
int s[numsSize];
if(nums[0]<0) {flag=1;Min=0;Max=0;}
if(nums[0]==0) s[0]=0;
else s[0]=nums[0];
for(i=1;i<numsSize;i++)
{if(nums[i]==0){if(flag%2==0) MAX=max(MAX,s[i-1]);else {if(Max==0&&Min==i-1) MAX=max(MAX,nums[0]);else if(Max==0) MAX=max(MAX,s[i-1]/s[Min]);else if(Min==i-1) MAX=max(MAX,s[Max-1]);else MAX=max(MAX,max(s[Max-1],s[i-1]/s[Min]));}flag=0;s[i]=0;continue;}
if(nums[i]<0) {if(flag==0) Min=i;Max=i;flag++;}
if(s[i-1])s[i]=s[i-1]*nums[i];
else s[i]=nums[i];
}
if(flag%2==0) MAX=max(MAX,s[numsSize-1]);
else {if(Max==0&&Min==numsSize-1) MAX=max(MAX,nums[0]);else if(Max==0) MAX=max(MAX,s[numsSize-1]/s[Min]);else if(Min==numsSize-1) MAX=max(MAX,s[Max-1]);else MAX=max(MAX,max(s[Max-1],s[numsSize-1]/s[Min]));}
return MAX;
}
```


运行结果：
![捕获.PNG](https://pic.leetcode-cn.com/7147016377859886c419dec51eb176f6e754201600fcfe356c147bea2debc64b-%E6%8D%95%E8%8E%B7.PNG)

时间复杂度:o(n) 一趟线性遍历就可以求出最大连续子序列之积
空间复杂度:o(n) 引进前缀积数组