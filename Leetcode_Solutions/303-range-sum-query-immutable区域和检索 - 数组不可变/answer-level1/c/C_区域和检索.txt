### 解题思路

"穿着衣服洗澡"

### 代码

```c
typedef struct {
    int* nums;
    int numsSize;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* a=(NumArray*)malloc(sizeof(NumArray));
    a->nums=nums;
    a->numsSize=numsSize;
    return a;
}
//唯一有用的部分
int numArraySumRange(NumArray* obj, int i, int j) {
    int sum=0;
    for(int iter=i;iter<=j;++iter)
        sum+=obj->nums[iter];
    return sum;
}

void numArrayFree(NumArray* obj) {
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 
 * numArrayFree(obj);
*/
```