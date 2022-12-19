先求和，再取平均值

```
bool canThreePartsEqualSum(int* A, int ASize){
    int sum = 0;
    for (int i = 0; i < ASize; ++i) sum += A[i];
    int avg;
    if (sum % 3) return false;//不能3整除
    avg = sum / 3;

    int tmp = 0;
    int num = 0;
    for (int i = 0; i < ASize; ++i) {
        tmp += A[i];
        if (tmp == avg) {//记录等于avg的次数
            ++num;
            tmp = 0;
        }
    }
    
    return (num == 3 ? true : false);
}
```
