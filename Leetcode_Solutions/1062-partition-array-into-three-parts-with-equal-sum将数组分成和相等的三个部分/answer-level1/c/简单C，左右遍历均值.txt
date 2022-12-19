```
bool canThreePartsEqualSum(int* A, int ASize){
    int sum = 0, i, j;
    for (i = 0; i < ASize; i++) {
        sum += A[i];
    }
    if (sum % 3 != 0) return false;
    int left = 0, right = 0, avg = sum / 3;
    for (i = 0; i < ASize - 2; i++) {
        left += A[i];
        if (left == avg) break;
    }
    for (j = ASize - 1; j > 1; j--) {
        right += A[j];
        if (right == avg) break;
    }
    if (i < j - 1) return true;
    return false;
}
```
