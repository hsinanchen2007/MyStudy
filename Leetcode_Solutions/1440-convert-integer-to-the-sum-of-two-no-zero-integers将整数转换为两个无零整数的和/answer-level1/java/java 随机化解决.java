用了随机化的思想，以 n 为范围随机出一个数 a，b = n - a，判断 a 和 b 中是否含 0，含 0 的话继续随机。
```
class Solution {
    public int[] getNoZeroIntegers(int n) {
        Random random = new Random();
        int a = random.nextInt(n);
        int b = n - a;
        while (hasZero(a) || hasZero(b)) {
            a = random.nextInt(n);
            b = n - a;
        }
        int[] res = new int[2];
        res[0] = a;
        res[1] = b;
        return res;
    }

    boolean hasZero(int n) {
        String s = String.valueOf(n);
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '0') {
                return true;
            }
        }
        return false;
    }
}
```
