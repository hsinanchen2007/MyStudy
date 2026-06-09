### 解题思路
![image.png](https://pic.leetcode-cn.com/8bf7aaab84d72e524debe174a38294aa294a525c841ee0bd72bef9024bbe6749-image.png)

两头的房间最终都是0， 所以先做1次变化，后面再找到重复时变化的次数。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* prisonAfterNDays(int* cells, int cellsSize, int N, int* returnSize){
    //思路： 找到循环1次的天数, 再对剩余天数做处理
    int *nums = malloc(sizeof(int) * cellsSize);
    *returnSize = cellsSize;
    memcpy(nums, cells, sizeof(int) * cellsSize);

    int count = 0;
    //先把第1与最后1个都变为0， 用低8位表示当前的状态，高8位表示下个状态
    nums[0] &= 0x00ff;
    nums[7] &= 0x00ff;
    int a, b;
    //变化1次
    for (int i = 1; i < 7; i++) {
        a = nums[i - 1] & 0xff;
        b = nums[i + 1] & 0xff;
        if ((a == 0 && b == 0 ) || (a == 1 && b == 1)) {
            nums[i] |= 1 << 8;
        } else {
            nums[i] &= 0x00ff;
        }
    }
    for (int i = 0; i < 8; i++) {
        //刷新状态
        nums[i] = (nums[i] >> 8) & 0xff;
        // printf("%d ", nums[i]);
    }
    // printf("\n");

    memcpy(cells, nums, sizeof(int) * cellsSize);
    bool isSame = false;
    while (!isSame) {
        count++;
        //变化1次
        for (int i = 1; i < 7; i++) {
            a = nums[i - 1] & 0xff;
            b = nums[i + 1] & 0xff;
            if ((a == 0 && b == 0 ) || (a == 1 && b == 1)) {
                nums[i] |= 1 << 8;
            } else {
                nums[i] &= 0x00ff;
            }           
        }

        for (int i = 0; i < 8; i++) {
            //刷新状态
            nums[i] = (nums[i] >> 8) & 0xff;
            // printf("%d ", nums[i]);
        }
        // printf("\n");

        //比较nums与cells是否相等
        bool bEnd = true;
        for (int i = 1; i < 7; i++) {
            if (nums[i] != cells[i]) {
                bEnd = false;
                break;
            }
        }

        isSame = bEnd;
    }
    free(nums);
    //cells已经变化了1次，减掉1天，后面的天数计算重复次数
    int nCount = (N - 1) % count;
    printf("count: %d nCount:%d\n", count, nCount);
    //cells继续再做count次就是重复了
    for (int i = 0; i < nCount; i++) {
        for (int i = 1; i < 7; i++) {
            a = cells[i - 1] & 0xff;
            b = cells[i + 1] & 0xff;
            if ((a == 0 && b == 0 ) || (a == 1 && b == 1)) {
                cells[i] |= 1 << 8;
            } else {
                cells[i] &= 0x00ff;
            }           
        }
        for (int i = 1; i < 7; i++) {
            //刷新状态
            cells[i] = (cells[i] >> 8) & 0xff;
        }        
    }

    return cells;
}
```