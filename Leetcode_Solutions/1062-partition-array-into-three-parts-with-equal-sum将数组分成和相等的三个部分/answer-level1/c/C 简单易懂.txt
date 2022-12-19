### 解题思路
此处撰写解题思路

### 代码

```c
bool canThreePartsEqualSum(int *A, int ASize)
{

    int ave = 0, Sum = 0, sum1 = 0, sum2 = 0;
    for (int i = 0; i < ASize; i++)
        Sum += A[i];
    ave = Sum / 3;
    if (Sum - ave * 3 != 0)
        return false;
    for (int j = 0; j < ASize - 2; j++)
    {
        sum1 += A[j];
        if (sum1 == ave)
            for (int x = j + 1; x < ASize - 1; x++)
            {
                sum2 += A[x];
                if (sum2 == ave)
                    return true;
            }
    }
    return false;
}
```