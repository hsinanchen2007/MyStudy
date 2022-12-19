### 解题思路
此处撰写解题思路

### 代码

```c
bool canThreePartsEqualSum(int* A, int ASize){
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < ASize; i++) {
        sum += A[i];
    }
    if (sum % 3 != 0) {
        return false;
    }
    int avg = sum / 3;
    int tmp = 0;
    for (int i = 0; i < ASize; i++) {
        tmp += A[i];
        if (tmp == avg) {
            cnt++;
            tmp = 0;
        }
    }
    return cnt >= 3 ? true : false;
}
```