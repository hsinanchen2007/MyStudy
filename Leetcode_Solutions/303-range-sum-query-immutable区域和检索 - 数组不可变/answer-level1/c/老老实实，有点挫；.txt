### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct {
    int *nums;
    int numsSize;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *obj = (NumArray *)malloc(sizeof(NumArray));
    obj->nums = nums;
    obj->numsSize = numsSize;
    return obj;
}

int numArraySumRange(NumArray* obj, int i, int j) {
   int sum = 0;
   for(int left = i; left <= j && left < obj->numsSize; left++) {
       sum += (obj->nums)[left];
   }
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
![image.png](https://pic.leetcode-cn.com/e2890185971c0148ca0ad8edb54e4ddb7ab3b32abc9bc672510714554982f984-image.png)
