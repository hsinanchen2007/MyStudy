### 解题思路
暴力法加优化

### 代码

```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    if(numsSize==0){
        *returnSize=0;
        return 0;
    }
    int fun(int *nums,int i,int j);
    int max=fun(nums,0,k-1);
    int i,j,index=0;
    int *res=(int*)malloc(sizeof(int)*numsSize);
    res[index++]=max;
    for(j=k;j<numsSize;j++){
        i=j-k+1;
        if(nums[i-1]!=max){ //滑动后最大值仍在窗口内
            if(nums[j]>max)     //只需要比较新加入的数与最大值
                max=nums[j];
        }
        else{
            max=fun(nums,i,j);  //滑动后丢失最大值，遍历寻找最大值
        }
        res[index++]=max;
    }
    *returnSize=index;
    return res;
}

int fun(int *nums,int i,int j){ //在nums数组中下标为[i,j]寻找最大值
    int max=nums[i];
    for(int k=i;k<=j;k++){
        if(nums[k]>max)
        max=nums[k];
    }
    return max;
}
```