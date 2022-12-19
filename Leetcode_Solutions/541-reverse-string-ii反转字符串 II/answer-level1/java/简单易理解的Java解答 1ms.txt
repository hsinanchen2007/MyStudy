
话不多说，直接上代码！

```java
    public String reverseStr(String s, int k) {
      char[] chs = s.toCharArray();
      for (int i = 0, len = chs.length; i < len; i += 2 * k) {
        reserse(chs, i, Math.min(i + k - 1, len - 1));
      }
      return String.valueOf(chs);
    }

    private void reserse(char[] chs, int start, int end) {
      while (start < end) {
        char temp = chs[start];
        chs[start++] = chs[end];
        chs[end--] = temp;
      }
    }
```
