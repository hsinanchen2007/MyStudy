### 解题思路
1、利用性质，三等分，所以一定要能被3整除
2、从首位找到三等分点，找的到则为真，否则为假

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        for (int i : A) {
            sum += i;
        }
        if (sum % 3 != 0) {
            return false;
        }
        int left = 0;
        int right = A.length - 1;
        int leftSum = A[left];
        int rightSum = A[right];
        while (left + 1 < right) {
            if (leftSum == sum / 3 && rightSum == sum / 3) {
                return true;
            }
            if (leftSum != sum / 3) {
                left++;
                leftSum += A[left]; 
            }
            if (rightSum != sum / 3) {
                right--;
                rightSum += A[right];
            }
        }
        return false;
    }
}
```