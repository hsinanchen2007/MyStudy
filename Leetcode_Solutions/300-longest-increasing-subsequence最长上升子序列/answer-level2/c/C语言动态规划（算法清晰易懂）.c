解题思路
C语言的动态规划，大家看看吧，在注释里写着易错点和建议

代码

```c
int max(int n,int m){
    if(n<m){
        return m;
    }
    else 
        return n;

}
int lengthOfLIS(int* nums, int numsSize){
    int *new_nums=(int*)malloc(sizeof(int)*numsSize);//注意不能直接定义数组new_nums[numsSize]；
    int i;
    int j;
    int key=0;
    if(numsSize==0){//这个容易忽略，要考虑到数组为空的情况
        return 0;
    }
    for(i=0;i<numsSize;i++){
        new_nums[i]=1;
    }
    for(i=0;i<numsSize;i++){//我第一次这里写成了i=1开始，想着要让j放在i的前面，但是提交测试才发现，如果遇到特殊情况如只有一个数，这个循环进不去，最后结果都是错误0.
        for(j=0;j<i;j++){
            if(nums[j]<nums[i]){
                new_nums[i]=max(new_nums[i],new_nums[j]+1);
            }
        }
    //    key=max(key,new_nums[i]);这个优化会时间更快一些
    }
    key=new_nums[0];
    for(i=1;i<numsSize;i++){
        if(new_nums[i]>key){
            key=new_nums[i];
        }
    }
    return key;
}
```