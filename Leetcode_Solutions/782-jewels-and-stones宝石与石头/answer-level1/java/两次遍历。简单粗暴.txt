```
public int numJewelsInStones(String J, String S) {
        int count = 0;
        char[] chars = S.toCharArray();
        char[] chars1 = J.toCharArray();
        for (char c : chars1) {
            for (char aChar : chars) {
                if (c == aChar) {
                    count++;
                }
            }
        }
        return count;
    }
```
