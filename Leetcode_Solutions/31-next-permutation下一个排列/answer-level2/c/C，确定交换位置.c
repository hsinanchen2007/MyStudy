### 解题思路
思路：
1,从后往前遍历，建立一个滑窗，滑窗从头到尾为降序，头指向第一个破坏降序的数字，尾部指向后面比该数字大的数字
2, 交换数字位置，
    1) 将head 至 Tail 之间的数字倒序
    2) 将Tail 至 numsSize 之间的数字倒序
    3) 将Tail 至 numsSize 之间的数字插入到 head 前
### 代码

```c

// 将输入数字倒序
void reversenums(int* nums, int numsSize){
    int     i       = 0;
    int     iTmp    = 0;

    if ((NULL == nums) || (0 == numsSize))
    {
        return nums;
    }

    for (i = 0; i < (numsSize / 2); i++)
    {
        iTmp = nums[i];
        nums[i] = nums[numsSize - i - 1];
        nums[numsSize - i - 1] = iTmp;
    }
    return;
}


//思路：
//从后往前遍历，建立一个滑窗，滑窗从头到尾为降序，头指向第一个破坏降序的数字，尾部指向后面比该数字大的数字
//数字交换
void nextPermutation(int* nums, int numsSize){
    int     i       = 0;
    int     j       = 0;
    int     iTmp    = 0;

    int     iTail   = 0;        //滑窗尾巴
    int     iHead   = 0;        //滑窗头部

    if ((NULL == nums) || (0 == numsSize) || (1 == numsSize))
    {
        return nums;
    }

    iTail = numsSize - 1;
    iHead = numsSize - 1;

    //1, 定位滑窗，head 指向第一个小于 head + 1的位置
    for (i = numsSize - 1; i > 0; i--)
    {
        if (nums[i - 1] < nums[i])
        {
            // 定位滑窗头的位置
            iHead = i - 1;

            // 定位滑窗尾的位置
            for (j = iTail; j > iHead; j--)
            {
                if (nums[i - 1] >= nums[j])
                {
                    iTail -= 1;
                }
            }

            break;
        }
    }

//    printf("[1] head=%d, tail=%d\n", iHead, iTail);
    if (iHead != iTail)
    {
        //2, 交换数字位置，
        //1) 将head 至 Tail 之间的数字倒序
        //2) 将Tail 至 numsSize 之间的数字倒序
        //3) 将Tail 至 numsSize 之间的数字插入到 head 前
        reversenums(&nums[iHead + 1], iTail - iHead - 1);
        reversenums(&nums[iTail + 1], numsSize - iTail - 1);

//        for (i = 0; i < numsSize; i++)
//        {
//            printf("%d ", nums[i]);
//        }
//        printf("\n");

        for (i = numsSize - 1; i >= iTail; i--)
        {
            iTmp = nums[numsSize - 1];
//            memmove(&nums[iHead + 1], &nums[iHead], sizeof(int) * (numsSize - iHead - 1));
            for (j = numsSize - 1; j > iHead; j--)
            {
                nums[j] = nums[j - 1];
            }

            nums[iHead] = iTmp;
        }
    }
    else
    {
        //3, 特殊情况，数字为倒序，不存在更大的排列
        reversenums(nums, numsSize);
    }
    return nums;
}
```