### 解题思路
1.找到异常处
2.1用较大值替代较小值，验证替换后是否满足
    2.2如果2.1不可以，用较小值替代较大值，再次验证
    2.3若仍不行，则证明替代一次不可行，输出false；若可行，则计数替换1次
3.当计数次数大于等于2时或筛查完成，终止循环
4.根据次数输出true or false

### 代码

```c
bool checkPossibility(int* nums, int numsSize){
    int x=0,i=0;
    while(x<2 && i<numsSize-1){
        if(nums[i]>nums[i+1]){
            int temp1=nums[i];
            int temp2=nums[i+1];
            
            nums[i]=temp2;
            if(i>0&&nums[i-1]>nums[i]){
                nums[i+1]=temp1;
                nums[i]=temp1;
            }
            x++;
        }
            
            i++;

    }
    if(x>=2) return false;
    return true;
}
```