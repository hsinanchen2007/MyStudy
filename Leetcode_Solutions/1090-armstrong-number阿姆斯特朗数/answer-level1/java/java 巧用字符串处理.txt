```
class Solution {
     public static boolean isArmstrong(int N) {
        String tmp = String.valueOf(N);
        int sum = 0;
        for (int i = 0; i < tmp.length(); i++) {
            Integer tp = Integer.parseInt(tmp.charAt(i)+"");
            sum += Math.pow(tp,tmp.length());
        }
        if (sum==N)
            return true;
        return false;
    }
}
```
