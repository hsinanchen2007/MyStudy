1 * 10 = (1 * 5) * 2 = ((1 * 4) + (1 * 1)) * 2 = ((1 * 2) * 2 + (1 * 1)) * 2 = (((1 * 1) * 2) * 2 + (1 * 1)) * 2
就是按照这个思路。
```
class Solution {
    public int multiply(int A, int B) {
        if (B == 1) {
            return A;
        }
        if (B % 2 == 0) {
            return multiply(A, B / 2) << 1;
        } else {
            return multiply(A, B - 1) + multiply(A, 1);
        }
    }
}
```
