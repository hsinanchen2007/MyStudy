### 解题思路
此处撰写解题思路

### 代码

```c
void moveZeroes(int* nums, int numsSize){
    //遇到0 则交换
    //有多个零
    //双指针
    int posnow,poslastzero;
    for(posnow=0,poslastzero=-1;posnow<numsSize;posnow++)
    {
      //遇到第一个0 交换。记录0的位置
      if(nums[posnow]==0&&poslastzero==-1)
        {
            poslastzero=posnow;
            continue;
        }
    if(nums[posnow]!=0&&poslastzero!=-1)
        {
            //遇到不是0,与最前面的0交换
            int temp;
            temp=nums[posnow];
            nums[posnow]=nums[poslastzero];
            nums[poslastzero]=temp;
            poslastzero++;
        }

    }

}
```