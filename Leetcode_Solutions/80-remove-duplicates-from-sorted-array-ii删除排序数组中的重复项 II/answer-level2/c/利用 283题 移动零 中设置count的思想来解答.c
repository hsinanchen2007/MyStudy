### 解题思路
此处撰写解题思路

### 代码

```c
/* 借鉴将不等于0的元素移动到数组前面的算法思想，用n来对某一元素的重复次数计数，用count来表示元素需要前移的步数，当n>2时，count才开始累加，最后数组前面numsSize-count个元素为满足条件的元素
*/


int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0 || numsSize==1 || numsSize==2)   //特例
        return numsSize;
    int n=1,count=0;
    for(int i=1;i<numsSize;i++)     //i从1开始
    {
        if(nums[i]==nums[i-1])
        {
            if(n<2)                 //不多于两个重复时，count不增加
                n++;
            else                    //多于两个重复时，count增加
            {
                n++;
                count++;
            }
        }
        else
        {
            n=1;                    //遇到不同元素，n重新置为1
        }
        nums[i-count]=nums[i];      //每一个元素都要向前移动count步
    }
    return numsSize-count;
}
```