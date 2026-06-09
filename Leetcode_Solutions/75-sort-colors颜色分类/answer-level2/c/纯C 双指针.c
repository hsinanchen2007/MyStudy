### 解题思路
纯C 相向双指针 挡板法 三色旗问题

### 代码

```c
#define SWAP(a,b) \
{                 \
    int t = a;    \  
    a = b;        \
    b = t;        \
}

enum color{
    red = 0,
    white,
    blue,
};

void sortColors(int* nums, int numsSize){
    int needBeRed = 0;
    int needBeWhite = 0;
    int needBeBlue = numsSize - 1;

    // red first
    while (needBeRed < needBeBlue)
    {
        while (nums[needBeRed] == red && needBeRed < needBeBlue)
        {
            needBeRed++;
        }

        while (nums[needBeBlue] != red && needBeRed < needBeBlue)
        {
            needBeBlue--;
        }

        SWAP((nums[needBeRed]), (nums[needBeBlue]));
    }

    // sort white and blue
    needBeWhite = needBeRed;
    needBeBlue = numsSize - 1;

    while (needBeWhite < needBeBlue)
    {
        while (nums[needBeWhite] == white && needBeWhite < needBeBlue)
        {
            needBeWhite++;
        }

        while (nums[needBeBlue] != white && needBeWhite < needBeBlue)
        {
            needBeBlue--;
        }

        SWAP((nums[needBeWhite]), (nums[needBeBlue]));
    }
}
```