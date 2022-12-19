### 解题思路
建立一个辅助数组

### 代码

```c
int missingNumber(int* nums, int numsSize){
    int *p;
    int i=0;
    p=(int *)malloc(sizeof(int)*(numsSize+1));
    for(i=0;i<numsSize+1;i++){
        p[i]=0;
    }
    for(i=0;i<numsSize;i++){
        p[nums[i]]++;
    }
    for(i=0;i<numsSize+1;i++){
        if(p[i]==0){
            break;
        }
    }
    return i;
}
```