### 解题思路
输入数据规律性很好，根据规律性可解题。
returnSize是返回字符串长度
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decompressRLElist(int* nums, int numsSize, int* returnSize){
//统计解压后有几个数字元素
    int length=0;
    int i;
    for(i=0;i<numsSize;i+=2)
        length+=nums[i];
//申请空间，iter是迭代器
    int *result=(int*)malloc(sizeof(int)*length);
    int *iter=result;
//一对一对进行解压
    for(i=0;i<numsSize;i+=2)
    {
        int j=nums[i];
        while(j-->0)
            *iter++=nums[i+1];
    }

    *returnSize=length;
    return result;
}
```