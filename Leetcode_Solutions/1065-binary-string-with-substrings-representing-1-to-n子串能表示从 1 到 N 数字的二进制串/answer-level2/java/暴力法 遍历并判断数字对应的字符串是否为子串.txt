```
class Solution {
    public boolean queryString(String S, int N) {
        for (int i = 1; i <= N; i++) {
            if (S.indexOf(tenToTwo(i)) == -1) {
                return false;
            }
        }
        return true;
    }

    private String tenToTwo(int n) {
        String res = "";
        while (n > 1) {
            int tmp = n / 2;
            int left = n % 2;
            res = left + res;
            n = tmp;
        }
        return n + res;
    }
}
```
