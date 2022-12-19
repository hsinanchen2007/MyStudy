### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int mod = 2 * (numRows - 1);
        char [] sArr = s.toCharArray();
        StringBuilder sb = new StringBuilder();
        
        for (int i = 0; i < sArr.length; i++) {
            if (i % mod == 0) {
                sb.append(sArr[i]);
            }
        }
        for (int i = 1; i < numRows; i++) {
            for (int j = 0; j < sArr.length; j++) {
                if (j % mod == i || j % mod == mod - i) {
                    sb.append(sArr[j]);
                }
            }
        }
       
        return sb.toString();
    }
}
```