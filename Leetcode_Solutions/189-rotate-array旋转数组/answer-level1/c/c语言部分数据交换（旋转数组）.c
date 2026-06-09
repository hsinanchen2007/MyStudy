### 解题思路
方法一是新建一个数组然后把左边四个数与右边三个数交换位置，然后再重新赋值给原数组。
方法二是记录最后一个数然后把数据从左往右复制，然后再对第一个数赋值。但该方法超时。貌似其他语言可以。

### 代码
方法一；
```c
void rotate(int* nums, int numsSize, int k){
    int* num=(int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++)
    {
        num[(i+k)%numsSize]=nums[i];
    }
    for(int i=0;i<numsSize;i++)
    {
        nums[i]=num[i];
    }
}
```
方法二；

void rotate(int* nums, int numsSize, int k){
    for(int i=0;i<k;i++)
    {
        int temp=nums[numsSize-1];
        for(int k=numsSize-1;k>=1;k--)
        {
            nums[k]=nums[k-1];
        }
        nums[0]=temp;
    }
}