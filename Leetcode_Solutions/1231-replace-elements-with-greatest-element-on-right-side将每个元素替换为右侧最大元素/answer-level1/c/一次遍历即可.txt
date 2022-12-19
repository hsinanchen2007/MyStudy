### 解题思路
这个解法个人绝得还是挺巧的
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int now_b(int* arr,int low,int high){
    int big=low;
    int i;
    for(i=low;i<=high;i++){
        if(arr[i]>arr[big]){
            big=i;
        }
    }
    return big;

}
int* replaceElements(int* arr, int arrSize, int* returnSize){
    int *res;
    int i=0;
    int now;
    int big;
    res=(int *)malloc(sizeof(int)*arrSize);
    *returnSize=arrSize;
    big=0;
    while(big<=arrSize-2){
        now=now_b(arr,big+1,arrSize-1);
        for(i=big;i<now;i++){
            res[i]=arr[now];
        }
        big=now;
    }
    res[arrSize-1]=-1;
    return res;
}
```