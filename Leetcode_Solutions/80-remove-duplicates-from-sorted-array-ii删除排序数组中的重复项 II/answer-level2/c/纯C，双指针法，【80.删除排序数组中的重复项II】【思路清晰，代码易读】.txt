### 解题思路
方法一：双指针法
1,指针iPosHead 指向修改后数组需要替换的位置,指针iPosTail指向下一个需要替换的位置

### 代码

```c
//方法一：双指针法
//1,指针iPosHead 指向修改后数组需要替换的位置,指针iPosTail指向下一个需要替换的位置
int removeDuplicates(int* nums, int numsSize){
    int     iPosHead    = 0;
    int     iPosTail    = 0;
    int     iTmp        = 0;
    int     iSameNum    = 0;

    if (NULL == nums) return 0;

    for(iPosTail = 0; iPosTail < numsSize; iPosTail++)
    {
        //
        if(iTmp != nums[iPosTail])
        {
            iSameNum = 1;
            iTmp = nums[iPosTail];
            nums[iPosHead] = iTmp;
            iPosHead += 1;
        }
        else
        {
            if(iSameNum < 2)
            {
                nums[iPosHead] = iTmp;
                iPosHead += 1;
                iSameNum += 1;
            }
        }
    }

    return iPosHead;
}
```