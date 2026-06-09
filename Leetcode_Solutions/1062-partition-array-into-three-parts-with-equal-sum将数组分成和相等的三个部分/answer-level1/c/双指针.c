### 解题思路
上代码

### 代码

```c
bool canThreePartsEqualSum(int* A, int ASize){
    int sum = 0;
    for (int i = 0; i < ASize; i++) {
        sum += A[i];
    }
    if (sum % 3 != 0) {
        return false;
    }
    int slice = sum / 3;
    int leftSum = 0, rightSum = 0;
    bool leftStopped = false, rightStopped = false;
    int leftIndex = 0;
    int rightIndex = ASize - 1;
    while (leftIndex + 1 < rightIndex && !(leftStopped && rightStopped)) {
        if (!leftStopped) {
            leftSum += A[leftIndex];
            if (leftSum == slice) {
                leftStopped = true;
            } else {
                leftIndex++;
            }
        }
        if (!rightStopped) {
            rightSum += A[rightIndex];
            if (rightSum == slice) {
                rightStopped = true;
            } else {
                rightIndex--;
            }
        }
        if (leftStopped && rightStopped) {
            return true;
        }
    }
    return false;
}
```