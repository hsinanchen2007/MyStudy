```java
class Solution {
    public String convertToTitle(int n) {
        StringBuffer res = new StringBuffer();
        while (!(n / 26 == 0 && n % 26 == 0)) {
            int pop = n % 26;
            char letter;
            if (pop == 0) {
                letter = 'Z';
                n = n / 26 - 1;
            } else {
                letter = (char) ('A' + pop - 1);
                n /= 26;
            }
            res.insert(0, letter);
        }
        return res.toString();
    }
}
```
