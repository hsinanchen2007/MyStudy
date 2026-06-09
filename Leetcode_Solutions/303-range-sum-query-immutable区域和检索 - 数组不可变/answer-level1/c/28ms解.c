在结构体中定义一个足够大的整型数组，数组中第i个元素记录0~i项之和。NumArray* numArrayCreate(int* nums, int numsSize)中，把结构体中的数组针对问题初始化。
```
typedef struct {
    int a[10000];
} NumArray;
NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* a;
    a=(NumArray*)malloc(sizeof(NumArray));
    if(numsSize==0)
        return a;
    a->a[0]=nums[0];
    for(int i=1;i<numsSize;i++)
        a->a[i]=nums[i]+a->a[i-1];
    return a;
}
int numArraySumRange(NumArray* obj, int i, int j) {
    if(i==0)
        return obj->a[j];
    return obj->a[j]-obj->a[i-1];
}
void numArrayFree(NumArray* obj) {
    
}
```
