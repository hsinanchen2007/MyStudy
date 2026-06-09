### 解题思路
1.hash
2.数学求和

### 代码

```c
int missingNumber(int* nums, int numsSize){
    int i;
    int *res=(int*)malloc(sizeof(int)*(numsSize+1));
    for(i=0;i<numsSize+1;i++)res[i]=0;
    for(i=0;i<numsSize;i++){
        res[nums[i]]++;
    }
    for(i=0;i<numsSize+1;i++){
        if(res[i]==0)
            return i;
    }
    return -1;
}


int missingNumber(int* nums, int numsSize){
    int i,res=0;
    for(i=0;i<numsSize;i++){
        res+=nums[i];
    }
    return numsSize*(numsSize+1)/2-res;
}
```