### 解题思路
思路很简单，两个分界点，一个是$\frac{1}{3}$处，一个是$\frac{2}{3}$处，但是写起来还是有点坑的，比如第一部分和和第二部分和初始化的时候都应该为每部分第一个数的值，防止出现每部分和应该为0结果判断时出现有一部分或二部分为空的情况。

### 代码

```c
bool canThreePartsEqualSum(int* A, int ASize){
    if(ASize < 3)
        return 0;
    int sum = 0;
    for(int i = 0;i < ASize;sum += A[i ++]);
    if(sum % 3 != 0)
        return 0;
    int oneThird, twoThird, oneThirdSum, twoThirdSum, finalSum = sum / 3;
    for(oneThird = 1, oneThirdSum = A[0];oneThirdSum != finalSum && oneThird < ASize - 2;oneThirdSum += A[oneThird ++]);
    if(oneThirdSum != finalSum)
        return 0;
    for(twoThird = oneThird + 1, twoThirdSum = oneThirdSum + A[oneThird];twoThirdSum != finalSum * 2 && twoThird < ASize - 1;twoThirdSum += A[twoThird ++]);
    if(twoThirdSum != finalSum * 2)
        return 0;
    else
        return 1;
}
```