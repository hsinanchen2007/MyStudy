![111.png](https://pic.leetcode-cn.com/88942deb863d9fbf8995cb6e93c81ce71f31d9ba7965ebf82762270bfcff8280-111.png)

```
int length = s.length();
        int aNums = 0;
        int lConsistent = 0;

        if (length == 1) {
            return true;
        }

        for (int index = 0; index < length; index++) {
            char charTemp = s.charAt(index);
            if (charTemp == 'A') {
                aNums++;
            }
            if (aNums > 1) {
                return false;
            }
            if (charTemp == 'L') {
                lConsistent++;
            } else {
                lConsistent = 0;
            }
            if (lConsistent > 2) {
                return false;
            }
        }
        return true;
```
