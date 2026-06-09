### 思路一：

首先，如果和不能被3整除，直接返回 false 即可。

既然满足均分成三部分，那么三部分的值必相等。所以，关键就是找分割三部分的索引值 i, j

### 代码：

时间复杂度O(n)，空间复杂度O(1)

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        if (A == null || A.length < 3) {
            return false;
        }
        int len = A.length, sum = 0, subSum = 0;
        int i = 0, j = 0, k = 0;
        int firstSum = 0, secondSum = 0, thirdSum = 0;
        for (int n : A) {
            sum += n;
        }
        if (sum % 3 != 0) {
            return false;
        }
        subSum = sum / 3;
        for (i = 0; i < len - 2; i++) {
            firstSum += A[i];
            if (firstSum == subSum) {
                break;
            }
        }
        if (firstSum != subSum) {
            return false;
        }

        for (j = i + 1; j < len - 1; j++) {
            secondSum += A[j];
            if (secondSum == subSum) {
                break;
            }
        }

        if (secondSum != subSum) {
            return false;
        }

        for (k = j + 1; k < len; k++) {
            thirdSum += A[k];
        }

        if (thirdSum != subSum) {
            return false;
        }

        return true;
    }
}
```

### Result：

Runtime：1ms

Your runtime beats 100% of java submissions.

### 思路二：

直接找

### 代码：

时间复杂度O(n)，空间复杂度O(1)

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        if (A == null || A.length < 3) {
            return false;
        }
        
        int sum = 0, partSum = 0, partCount = 0;
        for (int n : A) {
            sum += n;
        }
        if (sum % 3 != 0) {
            return false;
        }

        for (int m : A) {
            partSum += m;
            if (partSum == sum / 3) {
                partSum = 0;
                partCount ++;
            }
        }
        return partCount >= 3;
    }
}
```

### Result：

Runtime：3ms

Your runtime beats 30.87% of java submissions.