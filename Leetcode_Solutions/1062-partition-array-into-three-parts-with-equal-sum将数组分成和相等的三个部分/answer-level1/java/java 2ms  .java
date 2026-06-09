```
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int len = A.length;
        int sum = 0;
        for (int i = 0; i < len; i++)
            sum += A[i];
        int count = 0;
        int zom = 0;
        for (int i = 0; i < len; i++) {
            zom += A[i];
            if (zom == sum / 3) {
                count++;
                zom = 0;
            }
        }
        return count >= 3;
    }
}
```
