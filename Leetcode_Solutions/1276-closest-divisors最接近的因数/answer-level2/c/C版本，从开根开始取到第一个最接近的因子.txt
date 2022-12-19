### 解题思路
1、NUM+1开根后，从开根后的值开始取得第一个因子，该因子肯定是NUM+1最接近的两个数；
2、同理取NUM+2的值；
3、比较获取到的两个值的差距，取最小的区间；



### 代码

```c
int DivisorsNum(int num)
{
    int tmp = sqrt(num);
    for (int i = tmp; i >= 0; i--) {
        if (num % i == 0) {
            //printf("==%d\r\n", i);
            return i;
        }
    }

    return tmp;
}
int* closestDivisors(int num, int* returnSize)
{
    int *result = NULL;
    int numOneL = 0;
    int numOneR = 0;
    int numTwoL = 0;
    int numTwoR = 0;
    result = malloc(sizeof(int) * 2);
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    memset(result, 0, sizeof(int) * 2);

    numOneL = DivisorsNum(num + 1);
    numTwoL =  DivisorsNum(num + 2);

    numOneR = (num + 1)/numOneL;
    numTwoR = (num + 2)/numTwoL;

    result[0] = numOneL;
    result[1] = numOneR;

    if ((numTwoR - numTwoL) < (numOneR - numOneL)) {
        result[0] = numTwoL;
        result[1] = numTwoR;
    }
    *returnSize = 2;
    return result;
}
```