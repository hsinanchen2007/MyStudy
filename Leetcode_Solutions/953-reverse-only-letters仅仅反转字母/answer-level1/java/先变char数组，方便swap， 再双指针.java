![image.png](https://pic.leetcode-cn.com/04ab0a9955deed8288a7721a46251d50f4dba3a3327308f4681377fae1656639-image.png)

```
    public String reverseOnlyLetters(String S) {
        int i = 0, j = S.length() - 1;
        char[] c = S.toCharArray();
        while(i < j) {
            while(i < j && !Character.isLetter(c[i])) {
                i++;
            }
            while(i < j && !Character.isLetter(c[j])) {
                j--;
            }
            char t = c[i];
            c[i] = c[j];
            c[j] = t;
            i++;
            j--;
        }
        return String.valueOf(c);
    }
```
