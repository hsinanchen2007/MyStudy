```
class Solution {
    public String intToRoman(int num) {
         String result = "";
        int[] x = {1, 10, 100, 1000};
        String[] xs = {"I", "X", "C", "M"};
        String[] ys = {"V", "L", "D"};

        for (int i = x.length - 1; i >= 0; i--) {
            int z = num / x[i];

            if (z == 9) {
                result += xs[i] + xs[i + 1];
            } else if (z > 5 && z < 9) {
                result += ys[i];
                for (int j = 0; j < z - 5; j++) {
                    result += xs[i];
                }
            } else if (z == 5) {
                result += ys[i];
            } else if (z == 4) {
                result += xs[i] + ys[i];
            } else {
                for (int j = 0; j < z; j++) {
                    result += xs[i];
                }
            }
            num = num % x[i];
            if (num == 0) break;
        }
        return result;
    }
}
```
