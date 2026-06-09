### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX(a, b) ((a) > (b)) ? (a) : (b)

int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int X)
{
    int i = 0;
    int j = 0;
    int grumpyVal = 0;
    int res = 0;

    while (j < customersSize) {
        /* 满意的都加起来 */
        if (grumpy[j] == 0) {
            res += customers[j];
        }

        while (j - i + 1 > X) {
            i++;
        }
        
        /* 计算当前区间里满意数量 */
        int max = 0;
        for (int t = i; t <= j; t++) {
            if (grumpy[t] == 1) {
                max += customers[t];
            }
        }
        grumpyVal = MAX(max, grumpyVal);
        j++;
    }

    return res + grumpyVal;
}
```