### 解题思路
# 二分寻找左右边界：
**数据说明**：a,b,mid是二分参数，left是左边界，right同理

**1.首先处理空数组的问题**；

**2.二分寻找左边界：**
    a，b内存在边界值，a>=b退出循环
    第一种情况：
    mid指向的值等于target，mid可能是左边界，应该包含在[a,b]内，又因为是左边界，所以左边界还可能在mid的左边，即[a,mid]，因此b=mid;
    第二种情况：
    mid指向的值大于target，左边界必定不在[mid，b]中,按照标准二分,即[a,mid-1]，b=mid-1;
    （我把第一二种情况合并了，没有影响）
    第三种情况：
    mid指向的值小于target，左边界必定不在[a，mid]中,即[mid+1,b]，a=mid+1；
    最后得到的b指向左边界

**3.如果没有找到左边界，可以直接退出**

**4.二分寻找右边界：**
    **注意无限循环的问题，二分寻找右边界mid要等于（a+b）/2的上界**
    a，b内存在边界值，a>=b退出循环
    第一种情况：
    mid指向的值等于target，mid可能是右边界，应该包含在[a,b]内，又因为是右边界，所以右边界还可能在mid的右边,即[mid,b]，因此a=mid;
    第二种情况：
    mid指向的值小于target，右边界必定不在[a,mid]中,按照标准二分,即[mid+1,b]，a=mid+1;
    （我把第一二种情况合并了，没有影响）
    第三种情况：
    mid指向的值大于target，右边界必定不在[mid，b]中，即[a,mid-1],b=mid-1；
    最后得到的a指向右边界
    输出即可
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */



int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* c=(int *)malloc(sizeof(int)*2);
    *returnSize=2;
    if(numsSize==0){
        c[0]=-1;
        c[1]=-1;
        return c;
    }
    int a=0,b=numsSize-1,mid=(a+b)/2,left=-1,right=-1;
    for(;a<b;){
        mid=(a+b)/2;
        if(nums[mid]>=target){
            b=mid;
        }else{
            a=mid+1;
        }
    }
    
    if(target!=nums[b]){
        c[0]=-1;
        c[1]=-1;
        return c;
    }
    left=b;
    for(a=0,b=numsSize-1;a<b;){
        mid=(a+b)/2+(a+b)%2;
        if(nums[mid]>target){
            b=mid-1;
        }else{
            a=mid;
        }
    }
    right=a;
    c[0]=left;
    c[1]=right;
    return c;
}
```