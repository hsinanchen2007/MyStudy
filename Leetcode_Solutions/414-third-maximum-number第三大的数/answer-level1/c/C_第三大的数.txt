### 解题思路
1.会输入不足3个数
2.会输入个数大于三个，但是种数小于三个的数组
3.会输入int的最小值
4.前三个最大的数字必须互不相等
### 代码

```c
int thirdMax(int* nums, int numsSize){

    long max[3];
    for(int i=0;i<3;++i)
        max[i]=(long)(((unsigned long)1)<<(sizeof(long)*8-1));

    for(int i=0;i<numsSize;++i)
        for(int j=0;j<3;++j)
            if(nums[i]>max[j]&&nums[i]!=max[0]&&nums[i]!=max[1]&&nums[i]!=max[2])
            {
                for(int k=2;k>j;--k)
                    max[k]=max[k-1];
                max[j]=nums[i];
                break;
            }

    return max[2]==(long)(((unsigned long)1)<<(sizeof(long)*8-1))?max[0]:max[2];
}
```