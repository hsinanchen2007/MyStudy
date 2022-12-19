### 解题思路
遍历字符串判断当前位置与后一位置的字符是否相同，定义num记录相同字符的个数。

### 代码

```java
class Solution {
   public String compressString(String S) {
        if(S.equals("")) return S; 
        StringBuffer str = new StringBuffer();
        int num = 1, i = 0;
        while (i < S.length()-1) {
            if(S.charAt(i)==S.charAt(i+1)) {
                num++;
            } else {
                str.append(S.charAt(i)).append(num);
                num = 1;
            }
            i++;
        }
        str.append(S.charAt(i)).append(num);
        String result = str.toString();
        if(result.length() >= S.length()) return S;
        else return result;
    }
}
```