```
typedef struct {
    // 记录从0元素到当前索引的元素之和
    int *s;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *obj = malloc(sizeof(NumArray));
    obj->s = malloc(numsSize*sizeof(int));
    memset(obj->s, 0, numsSize*sizeof(int));
    for(int i=0; i<numsSize; i++){
        obj->s[i] = (i==0) ? nums[0] : obj->s[i-1]+nums[i];
    }
    return obj;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    if(i==0){
        return obj->s[j];
    }
    else{
        // 区间和=元素之和的相减，图像处理中的积分图常规用法。
        return obj->s[j]-obj->s[i-1]; 
    }

}

void numArrayFree(NumArray* obj) {
    free(obj->s);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 
 * numArrayFree(obj);
*/
```