### 解题思路
遍历数组
    依次判断数字是否是偶数位数
        如果是，则计数器加一

### 代码

```c
bool isEvenNumber(int n) {
    int c = 0;

    while (n != 0) {
        n /= 10;
        c++;
    }

    return c % 2 == 0;
}

int findNumbers(int* nums, int numsSize){
    int i;
    bool result;
    int c = 0;

    if (nums == NULL || numsSize < 1) {
        return 0;
    }

    for (i = 0; i < numsSize; i++) {
        result = isEvenNumber(nums[i]);
        if (result == true) {
            c++;
        }
    }

    return c;
}

```