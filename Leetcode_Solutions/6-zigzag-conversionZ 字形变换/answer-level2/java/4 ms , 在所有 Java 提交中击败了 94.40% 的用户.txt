### 解题思路
此处撰写解题思路
直接找规律
### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) return s;
        StringBuffer res = new StringBuffer(s.length());
        for (int i = 0; i < numRows; i++) {
            int j = i;
            int offset1 = j;
            int offset2 = numRows - j - 1;
            boolean flag = true;
            while (j < s.length()) {
                if (flag) {
                    if (offset1 != 0||j==0) res.append(s.charAt(j));
                    j += offset2 << 1;
                } else {
                    if (offset2 != 0) res.append(s.charAt(j));
                    j += offset1 << 1;
                }
                flag = !flag;
            }
        }
        return res.toString();
    }
}
```