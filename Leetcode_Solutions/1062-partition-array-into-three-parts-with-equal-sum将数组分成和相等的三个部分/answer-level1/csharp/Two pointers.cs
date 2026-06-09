### 解题思路
Use two index simultaneously, one from the begining, and one from the end, to sum the array up to figure out if it contains 3 partition with equal values.

### 代码

```csharp
public class Solution {
    public bool CanThreePartsEqualSum(int[] A) {
        int arrayLength = A.Length;
        if (arrayLength == 0) { return false; }

        int sumOfArray = A.Sum();
        if (sumOfArray % 3 != 0) { return false; }

        int sumOfParts = sumOfArray / 3;

        int leftIndex = 0;
        int leftSum = A[leftIndex];

        int rightIndex = arrayLength - 1;
        int rightSum = A[rightIndex];

        while (leftIndex + 1 < rightIndex) {
            if (leftSum == sumOfParts && rightSum == sumOfParts) {
                return true;
            }

            if (leftSum != sumOfParts ) {
                leftSum +=  A[++leftIndex];
            }

            if (rightSum != sumOfParts) {
                rightSum += A[--rightIndex];
            }
        }

        return false;
    }
}
```