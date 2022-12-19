### 思路和一些问题
1.直接遍历数组一一比对，第i个（i为0 ~ n-1）与之后的i+1到n相加与目标比较。
2.返回的数组需要自己分配空间：int*ret = (int*)malloc(sizeof(int)*2);
3.题目给出的*returnsize需要赋值为2

### 代码

```c

int* twoSum(int* nums, int numsSize, int target, int *returnSize){
    int i,j,sum;
    *returnSize= 2;//题目中给出的*returnSize需要赋值为2，否则检测结果不正确
    int*ret = (int*)malloc(sizeof(int)*2);
    for(i=0;i<numsSize-1;i++){
        for(j=i+1;j<numsSize;j++){
            if(target == nums[i]+nums[j]){
                ret[0]=i;
                ret[1]=j;
                return ret;
            }//找到所需答案
        }//for 遍历每个数组作为第二个数
    }//for 遍历每个数组作为第一位数
    return ret;
}
```