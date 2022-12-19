### 解题思路
此处撰写解题思路

### 代码

```c
int abs(int x)
{
    if(x<0)
    x=-x;
    return x;
}
int threeSumClosest(int* nums, int numsSize, int target){
int i,j,n,sum,k,min=abs(nums[0]+nums[1]+nums[2]-target),p=nums[0]+nums[1]+nums[2];
if(numsSize<3)
return 0;
for(i=0;i<numsSize;i++){
    for(j=i+1;j<numsSize;j++){
        for(n=j+1;n<numsSize;n++){
            sum=nums[i]+nums[j]+nums[n];
            k=abs(sum-target);
            if(min>k){
                min=k;
                p=sum;
            }
        }
    }
}
return p;
}
```