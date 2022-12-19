### 解题思路
此处撰写解题思路

### 代码

```java
 class Solution {
        public boolean canThreePartsEqualSum(int[] A) {

            if (A == null || A.length < 1) return false;
            int sum = Arrays.stream(A).sum();
            if (sum % 3 != 0) return false;
            int targetPartition = sum / 3;
            int partCount = 0, partSum = 0;
            for (int i = 0; i < A.length; i++) {
                partSum += A[i];
                if (partSum == targetPartition) {
                    partSum = 0;
                    partCount++;
                }
            }
            //sum=0时，partCount>3;
            return partCount >= 3 ;

        }
    }
```