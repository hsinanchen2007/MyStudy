### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
  public String replaceSpace(String s) {
    int n = s.length();

    for (char c : s.toCharArray())
      if (c == ' ') n += 2;

    char[] cresult = new char[n];
    int ptr = 0;

    for (char c : s.toCharArray()) {
      if (c != ' ') {
        cresult[ptr++] = c;
        continue;
      }

      cresult[ptr++] = '%';
      cresult[ptr++] = '2';
      cresult[ptr++] = '0';
    }

    return new String(cresult);
  }
}
```