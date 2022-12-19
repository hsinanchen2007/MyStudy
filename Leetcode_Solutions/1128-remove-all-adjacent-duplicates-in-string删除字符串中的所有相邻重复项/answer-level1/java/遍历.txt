一次遍历，先往前比较，如果往前比较不同、再往后比较
```
public String removeDuplicates(String S) {
        if (S == null || S.length() == 0) return S;
        char[] chars = S.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] == 0) {
                continue;
            }
            int before = i - 1, after = i + 1;
            //往前走
            char tmp = chars[i];
            checkBefore(chars, i, before, tmp);
            //往后走
            if (chars[i] != 0) {
                checkAfter(chars, i, after, tmp);
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] != 0) {
                sb.append(chars[i]);
            }
        }
        return sb.toString();
    }

    private void checkBefore(char[] chars, int i, int before, char tmp) {
        while (before > -1 && chars[before] == 0) {
            before--;
        }
        if (before == -1) {
            return;
        } else {
            if (chars[before] == tmp) {
                chars[before] = 0;
                chars[i] = 0;
            }
        }
    }

    private void checkAfter(char[] chars, int i, int after, char tmp) {
        while (after < chars.length && chars[after] == 0) {
            after++;
        }
        if (after == chars.length) {
            return;
        } else {
            if (chars[after] == tmp) {
                chars[after] = 0;
                chars[i] = 0;
            }
        }
    }
```
![image.png](https://pic.leetcode-cn.com/aa1ac5a27a10f45340916a6d66c9022d5b06d107fdbd5833082e7b4c69d5ea44-image.png)
