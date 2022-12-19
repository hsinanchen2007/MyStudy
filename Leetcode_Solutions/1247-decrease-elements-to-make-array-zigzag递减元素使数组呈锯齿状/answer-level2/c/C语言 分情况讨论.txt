### 解题思路
C语言 分情况讨论


### 代码

```c

int little(int a,int b) 
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}
int decreaseNum(int i, int* nums, int numsSize)
{
    //最左边的数字不考虑左边,要考虑比右边小1
    if (0 == i) {
        //如果本来就比右边小
        if (*nums < *(nums + 1)) {
            return 0;
        } else {
            return (*nums - *(nums + 1) + 1);
        }
        
    }
    //最右边的数字不考虑右边，要考虑比左边小1
    if ((numsSize - 1) == i) {
        //如果本来就比左边小
        if (*(nums + i) < *(nums + i -1)) {
            return 0;
        } else {
            return (*(nums + i) - *(nums + i -1) + 1);
        }
        
    }
    //数字两边都有其他数字
    //如果此数比其他两个都小
    if ((*(nums + i)  < *(nums + i + 1)) && (*(nums + i) < *(nums + i - 1))) {
        return 0;
    } else {
        //取两边数字中最小的，并且还要把此数字减到比两边较小的数字还要小1
        return (*(nums + i) - little (*(nums + i + 1), *(nums + i - 1)) + 1);
    }
}

int movesToMakeZigzag(int* nums, int numsSize){
    int odd = 0;
    int even = 0;
    if ((NULL == nums) || (numsSize == 0) || 
        (numsSize == 1) || (numsSize == 2)) {
        return 0;
    }
    //分情况讨论，一种是偶数索引小，一种是奇数索引小
    //遍历数组，分别使得遍历到的元素，小于两侧的元素，取差值最小的情况。
    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0) {
            odd = odd + decreaseNum(i, nums, numsSize);
        } else {
            even = even + decreaseNum(i, nums, numsSize);
        }
    }
    if (odd > even) {
        return even;
    } else {
        return odd;
    }
}
```