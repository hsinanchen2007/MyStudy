```
class Solution {
    public int[] printNumbers(int n) {
        StringBuilder builder = new StringBuilder();
        for (int i=0; i<n;i++) {
            builder.append(9);
        }

        String x = builder.toString();

        int[] aa = new int[Integer.valueOf(x)];
        for (int i=0; i<Integer.valueOf(x); i++) {
            aa[i] = i+1;
        }

        return aa;
    }
}
```