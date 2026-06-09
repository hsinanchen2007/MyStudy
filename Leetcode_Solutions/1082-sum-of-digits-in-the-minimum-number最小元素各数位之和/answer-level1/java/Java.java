```
import java.util.Arrays;

class Solution {
    public int sumOfDigits(int[] A) {
        Arrays.sort(A);
        int S = A[0];
        int sum = 0;
        while (S > 0) {
            sum += S % 10;
            S = S / 10;
        }
        return sum % 2 == 0 ? 1 : 0;
    }
}
```
