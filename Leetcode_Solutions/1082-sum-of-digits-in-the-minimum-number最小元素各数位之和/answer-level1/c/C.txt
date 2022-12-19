遍历最小数
取余拿到每一位
```
int sumOfDigits(int* A, int ASize){
    int min = 0x7FFFFFFF;
    int sum = 0;
    int isFind = 0;
    for (int i = 0; i < ASize; i++)
    {
        if (A[i] < min)
        {
            isFind = 1;
            min = A[i];
        }
    }
    if (isFind)
    {
        while (min != 0)
        {
            sum += min %10;
            min = min / 10;
        }
    }
    return sum & 1 == 1 ? 0 : 1;
}
```
