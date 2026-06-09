### 解题思路
此处撰写解题思路
单独写一个移动函数，输入参数有该数组，需要顶替的首位，已经尾位，将元素依次被其后的元素代替
设置一个值last与数组长度相同，没当检测到一维需要删除的，便将其减少一位，同时可以作为还需检测的数组末尾。
循环该数组每一位，如果该位元素与需要删除元素相同，将该位用移动函数处理
如果相同而且是末尾元素，则直接将返回长度减一即可
如果不相同，指针向后移动一位
最后输出last即可
### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    if(numsSize==0) return 0;
    int last = numsSize;
    int i=0;
    while(i<last)
    {
        if(nums[i]==val&&i<last-1)   //将i位置顶替 i后还有元素
        {
            turnOne(nums,i,last-1);
            last--;
        }
        if(nums[i]==val&&i==last-1)  // i位置需要舍弃 且i是最后一个需要判断的元素，直接缩短1 
        {
            last--;
            break;

        }
        if(nums[i]!=val) //非相同元素 指针向后移动。 不可用else，逻辑上与上一个if搭配，执行会出错。
        {
            i++;
        }
    }
    return last;
}

void turnOne(int *nums,int first,int last) 
//用于顶替掉位置为nums[first]的元素，末尾元素为numa[last]。
{
    while (first<last)
    {
        nums[first] = nums[first+1];
        first++;
    }
}
```