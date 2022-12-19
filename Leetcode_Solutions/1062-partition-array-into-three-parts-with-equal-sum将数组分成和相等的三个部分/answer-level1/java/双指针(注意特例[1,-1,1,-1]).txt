```Java
public boolean canThreePartsEqualSum(int[] A) {
    // 求和
    int sum = 0;
    for (int i: A) {
        sum += i;
    }
    // 如果总和不能被 3 整除，直接返回false
    if (sum % 3 != 0) {
        return false;
    }

    // 初始化
    int each = sum / 3;
    int i = 0, j = A.length - 1;
    int leftSum = A[i];
    int rightSum = A[j];

    // 双指针向中间逼近
    while (i < j) {
        if (leftSum != each) {
            leftSum += A[++i];
        }
        if (rightSum != each) {
            rightSum += A[--j];
        }
        if (leftSum == each && rightSum == each) {
            // 注意这里的结束条件，必须两指针中间至少相差一个元素
            return j - i > 1;
        }
    }
    return false;
}
```
