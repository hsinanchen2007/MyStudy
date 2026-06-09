### 思路
1. 先求所有元素的和，假设为`sum`，如果要满足将数组分成和相等的三个部分，那么`sum`必须是`3`的倍数；
2. 假设一部分的和为`onePartSum`(等于`sum / 3`), 然后求前缀和，在求前缀和的过程中，如果在出现某一前缀和是`2 * onePartSum`之前，已经出现了值为`onePartSum`的前缀和（当然`2 * onePartSum`前缀和出现的位置必须不是最后一个），则说明可以将数组分成三个和相等的三部分。否则，不能。

```java
    public boolean canThreePartsEqualSum(int[] arr) {
        int sum = 0;
        for (int num : arr) {
            sum += num;
        }

        if (sum % 3 != 0) {
            return false;
        }

        int onePartSum = sum / 3;
        int len = arr.length;
        int preSum = arr[0];
        boolean hasOneParSum = preSum == onePartSum;
        for (int i = 1; i < len - 1; i++) {
            preSum += arr[i];
            if (preSum == 2 * onePartSum && hasOneParSum) {
                return true;
            }

            if (preSum == onePartSum) {
                hasOneParSum = true;
            }
        }

        return false;
    }
```

### 复杂度分析
时间复杂度：$O(n)$
空间复杂度：$O(1)$