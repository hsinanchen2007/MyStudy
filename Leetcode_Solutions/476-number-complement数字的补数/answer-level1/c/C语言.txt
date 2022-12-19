### 解题思路
此处撰写解题思路

### 代码

```c
int findComplement(int num){
    int bitWidth = 0;
    int numTemp = num;
    int i, res;
    unsigned int temp;

    /* 首先判断有几位 */
    while (numTemp) {
        numTemp  = numTemp >> 1;
        bitWidth++;
    }

    res = 0;
    for (i = 0; i < bitWidth; i++) {
        temp = 1U << i;
        if ((num & temp) == 0) {
            res |= temp;
        }
    }

    return res;
}
```