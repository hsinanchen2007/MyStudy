```java
class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int count = 0;
        for (int i = 0; i < customers.length; i++) {
            if (grumpy[i] == 0) {
                count += customers[i];
                customers[i] = 0;
            }
        }

        int max = 0, maxStep = 0;
        for (int i = 0, j = 0; i < customers.length && j < customers.length; ) {
            maxStep += customers[j++];
            if (j - i == X) {
                if (maxStep > max) {
                    max = maxStep;
                }
                maxStep -= customers[i++];
            }
        }
        return count + Math.max(max, maxStep);
    }
}
```