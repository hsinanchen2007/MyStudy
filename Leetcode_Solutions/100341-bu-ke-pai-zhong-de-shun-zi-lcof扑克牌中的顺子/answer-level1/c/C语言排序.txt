### 解题思路
此处撰写解题思路

### 代码

```c
/* 扑克牌中的顺子 */
int cmp(const void *n1, const void *n2)
{
    return *((int *)n1) - *((int *)n2);
}

bool isStraight(int* nums, int numsSize){
    if ((nums == NULL) || (numsSize == 0)) {
        return false;
    }

    int king = 0;
    qsort(nums, numsSize, sizeof(int), cmp); // 对数组进行排序

    for (int index = 0; index < numsSize - 1; index++) {
        if (nums[index] == 0) {  //大王
            king++;
        }  else if (nums[index] + 1 == nums[index + 1]) { // 有序
            // nothing
        } else if ((nums[index] + 2 == nums[index + 1]) && (king != 0)) { // 一张王弥补差一
            king--;
        } else if ((nums[index] + 3 == nums[index + 1]) && (king == 2)) { // 两张王弥补差二
            king = king - 2;
        }  else {
            return false;
        }
    }

    return true;
}
```