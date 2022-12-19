```
class Solution {
    public boolean isArmstrong(int N) {
        String in = "" + N;
        int result = 0;
        for (int i = 0; i < in.length(); i++) {
            result += Math.pow(Integer.parseInt(in.substring(i, i + 1)), in.length());
        }
        if (result == N) {
            return true;
        } else {
            return false;
        }
    }
}
```
