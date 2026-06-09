### 解题思路
如果最后返回的是true，我们发现这样的数组中，改变的那个数字，若把它改成它前一个或者后一个就符合提议，于是就想到了这个解法。虽然很垃圾，但也想了好久。。。

### 代码

```c
bool checkPossibility(int* nums, int numsSize){
    int i,j;
    int *flag;
    if(numsSize==1||numsSize==2){
        return true;
    }
    flag=(int *)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        flag[i]=nums[i];
    }
    for(i=0;i<=numsSize-2;i++){
        flag[i+1]=flag[i];
        j=0;
        while(j<=numsSize-2&&flag[j]<=flag[j+1]){
            j++;
        }
        flag[i+1]=nums[i+1];
        if(j==numsSize-1){
            return true;
        }
    }
    for(i=0;i<=numsSize-2;i++){
        flag[i]=flag[i+1];
        j=0;
        while(j<=numsSize-2&&flag[j]<=flag[j+1]){
            j++;
        }
        flag[i]=nums[i];
        if(j==numsSize-1){
            return true;
        }
    }
    return false; 
}
```