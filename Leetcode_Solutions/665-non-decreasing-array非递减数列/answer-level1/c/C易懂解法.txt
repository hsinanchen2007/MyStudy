### 结果
![捕获.JPG](https://pic.leetcode-cn.com/0c292ab98f950cc8a757a08608d54e5fae2cdb4e6d5c111c1dc7dfc0f8ce7aab-%E6%8D%95%E8%8E%B7.JPG)

### 思路
此题思路为官方给出的暴力解法，但是有一些细节需要注意，否则会出现错误示例
整体思路是将nums[i-1]复制给nums[i]，这样nums[i-1]<=nums[i]，然后判断是否非递减
特例：4,2,3
当把上述方法应用到这个例子上时，结果为false，但正确结果应该是true

原因：我们需要对i==0时也进行处理，但i-1越界，怎么办？ 可以设置Global_MIN=-32767,当
i==0时，将nums[i]即nums[0]赋值为Global_MIN；
需要注意每次循环一遍，需要将tmp数组重置为原始数组nums

### 代码

```c
int judge(int *A, int len){
    for(int i=0;i<len-1;i++){
        if(A[i]<=A[i+1]){
            continue;
        }
        else
            return 0;
    }
    return 1;
}


bool checkPossibility(int* nums, int numsSize){
    int MIN=-32767;
    if(numsSize==1)
        return true;
    int i=0;
    int *tmp=(int *)calloc(numsSize,sizeof(int));
    for(i;i<numsSize;i++){
        memcpy(tmp, nums, sizeof(int)*numsSize);
        if(i==0)
            tmp[0]=MIN;
        else tmp[i]=tmp[i-1];
        if(judge(tmp,numsSize)==1)
            return true;
        else{
            continue;
        }
    }
    return false;
}
```