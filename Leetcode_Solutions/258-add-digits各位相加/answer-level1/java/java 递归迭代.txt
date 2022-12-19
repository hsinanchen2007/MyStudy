java 递归迭代

```
class Solution {
    public int addDigits(int num) {
        int xx = single(num);
        while (xx / 10 >= 1) {
            xx = single(xx);
        }
        return xx;
    }

    public static int single(int aa) {
        String value = String.valueOf(aa);
        int sum = 0;
        for (int i=0; i<value.length(); i++) {
            sum += Integer.valueOf(String.valueOf(value.charAt(i)));
        }
        return sum;
    }
}
```