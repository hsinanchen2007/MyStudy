### 解题思路
分治法步骤：
**划分问题**：把问题的实例划分成子问题
**递归求解**：递归解决子问题
**合并问题**：合并子问题的解得到原问题的解

### 代码

```c
int maxsum(int *nums,int x,int y){  //返回数组在左闭右开区间[x,y)中的最大连续和                            
    if(y-x==1)  //只有一个元素直接返回  
        return nums[x];
    int m=x+(y-x)/2;    //分治第一步：划分成[x,m)和[m,y)
    int maxs=max(maxsum(nums,x,m),maxsum(nums,m,y));    //分治第二步：递归求解
    int v,L,R;
    v=0,L=nums[m-1];    //分治第三步：合并（1）——从分界点开始往左的最大连续和L
    for(int i=m-1;i>=x;i--)
        L=max(L,v+=nums[i]);
    v=0;R=nums[m];      //分治第三步：合并（2）——从分界点开始往右的最大连续和R
    for(int i=m;i<y;i++)
        R=max(v+=nums[i],R);
    return max(maxs,L+R);   //把子问题的解与L和R比较
}
int max(int a,int b){
    return a>=b?a:b;
}

int maxSubArray(int* nums, int numsSize){
    return maxsum(nums,0,numsSize);
}

```