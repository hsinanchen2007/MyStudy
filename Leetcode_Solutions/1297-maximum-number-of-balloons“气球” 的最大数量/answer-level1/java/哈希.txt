```java
class Solution {
    public int maxNumberOfBalloons(String text) {
        int[] count = new int[5];
        for (char c : text.toCharArray()) {
            int i = map(c);
            if (i >= 0) {
                count[i]++;
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < count.length; i++) {
            if (i == 2 || i == 3) {
                ans = Math.min(ans, count[i] / 2);
            } else {
                ans = Math.min(ans, count[i]);
            } 
        }
        return ans;
    }

    private int map(char c) {
        // balloon
        switch (c) {
            case 'b':
                return 0;
            case 'a':
                return 1;
            case 'l':
                return 2;
            case 'o':
                return 3;
            case 'n':
                return 4;
            default:
                return -1;
        }
    }
}
```
