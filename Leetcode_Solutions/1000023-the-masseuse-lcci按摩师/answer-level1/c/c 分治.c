### 解题思路
此处撰写解题思路

### 代码

```c
int divide(int *nums, int i, int j, int numsSize){
    int max=0,x1=0,x2=0;
    int l1,l2,r1,r2;
    if(j-i+1==5){
        max=nums[i]+nums[i+2]+nums[i+4];
        if(nums[i+1]+nums[i+3]>max) max=nums[i+1]+nums[i+3];
        if(nums[i]+nums[i+3]>max) max=nums[i]+nums[i+3];
        if(nums[i+1]+nums[i+4]>max) max=nums[i+1]+nums[i+4];
        return max;
    }
    if(j-i+1==4){
       max=nums[i]+nums[i+2];
       if(nums[i+1]+nums[i+3]>max) max=nums[i+1]+nums[i+3];
       if(nums[i]+nums[i+3]>max) max=nums[i]+nums[i+3];
       return max;
    }
    if(j-i+1==3){
        max=nums[i]+nums[i+2];
        if(nums[i+1]>max) max=nums[i+1];
        return max;
    }
    if(j-i+1==2){
        if(nums[i]>nums[i+1]) return nums[i];
             else return nums[i+1];
    }
    if(j-i+1==1) return nums[i];
    l1=divide(nums, i, i+(j-i+1)/2-3, numsSize);
    r1=divide(nums, i+(j-i+1)/2+1, j, numsSize);
    l2=divide(nums, i, i+(j-i+1)/2-2, numsSize);
    r2=divide(nums, i+(j-i+1)/2+2, j, numsSize);
    x1=l1+r1+nums[i+(j-i+1)/2-1];
    x2=l2+r2+nums[i+(j-i+1)/2];
    max=l2+r1;
    if((max>x1)&&(max>x2)) return max;
    if(x1>x2) return x1;
        else return x2;
}

int massage(int* nums, int numsSize){
    int x1,x2;
    if(numsSize==0)return 0;
    return divide(nums, 0, numsSize-1, numsSize);
}
```