第一个思路也是最傻的思路，先用C的快排，再找出值与坐标不同的，返回i即可（耗时长，内存多）；
第二种是看了大佬的题解发现的，先求和，再逐个减，最后剩下的即为缺少的；
但是，第一种思路还存在局限性，如果是有重复数字便会出错。第二种思路是针对这题的，若题目改为找出所有缺少的数字，则也不行。

### 代码

```c
方法一：
int comp(int* a,int* b){
    return (*a)>(*b)?1:0;
}

int missingNumber(int* nums, int numsSize){
    qsort(nums,numsSize,sizeof(int),comp);
    for(int i=0;i<numsSize;i++)
        if(nums[i]!=i)
          return i;
    return numsSize;
}

方法二：
int missingNumber(int* nums, int numsSize){
    int i=numsSize,sum=(1+numsSize)*numsSize/2;
    while(i--) sum=sum-nums[i];
    return sum;
}
```