### 解题思路
此处撰写解题思路

### 代码

```c
int massage(int* nums, int numsSize){

//动态规划
//dt[i][0]表示第i个顾客不招待，dt[i][1]表述招待
//dt[i+1][0]=Max(dt[i][1],dt[i][0])
//dt[i+1][1]=dt[i][0]+nums[i+1]
if(numsSize==0){
    return 0;
}else{
    int x1=0;//dt[1][0]
    int x2=nums[0];//dt[1][1]

    for(int i=1;i<numsSize;i++){
        int k=x1;//保存x1的原始值
        x1=x1>x2?x1:x2;
        x2=k+nums[i];
    
}
    return x1>x2?x1:x2;//返回最大值
}
}
```