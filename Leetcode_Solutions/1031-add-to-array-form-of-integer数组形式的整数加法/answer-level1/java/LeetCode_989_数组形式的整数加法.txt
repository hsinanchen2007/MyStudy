### 解题思路

先将K与A数组的最后一位相加，然后从A的最后一位开始进位即可。重点在于跳出循环的位置，因A[i]是在循环开头就添加到List中了，所以在跳出循环的时候，i<=0而不是i<0。

### 代码

```java
class Solution {
    public List<Integer> addToArrayForm(int[] A, int K) {
        List<Integer> result = new ArrayList<>();
        A[A.length - 1] += K;

        int num = 0;

        for (int i = A.length - 1; ; i--) {
            if (i >= 0) {
                num += A[i];
            }
            result.add(0, num % 10);
            num /= 10;
            if (num == 0 && i <= 0) {
                break;
            }
        }

        return result;
    }
}
```