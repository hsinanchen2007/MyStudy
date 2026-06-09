### 解题思路
击败了
11.01%
的用户

### 代码

```c
typedef struct {
    int *arr;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *obj = (NumArray *)malloc(sizeof(NumArray));
    obj->arr = nums;
    return obj;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    int sum = 0, x;
    for (x = i; x <= j; x++) sum += obj->arr[x];
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