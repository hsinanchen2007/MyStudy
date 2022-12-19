java 暴力1ms

```
class Solution {
    public int subtractProductAndSum(int n) {
        String xx = String.valueOf(n);
        int sum = 0;
        int plus = 1;
        for (int i=0; i<xx.length();i++) {
            plus *= Integer.valueOf(String.valueOf(xx.charAt(i)));
            sum += Integer.valueOf(String.valueOf(xx.charAt(i)));
        }
        return plus-sum;
    }
}
```