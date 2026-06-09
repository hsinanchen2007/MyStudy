### 解题思路

首先判断两个字符串的相似字符串项，然后求出两个字符串长度的最大公因子，最后即可得出最大相似字符串<br/>
### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if (!str1.concat(str2).equals(str2.concat(str1))) {
            return "";
        }

        String subStr1 = innerGcdOfStrings(str1);
        String subStr2 = innerGcdOfStrings(str2);
        if (subStr1.equals(subStr2)) {
            int aLength = str1.length();
            int bLength = str2.length();
            int factor = aLength;
            int result = 0;
            while(factor != 0) {
                if(aLength % factor == 0 && bLength % factor == 0) {
                    result = factor;
                    break;
                } else {
                    factor--;
                }
            }
            
            if (result % subStr2.length() != 0) {
                return subStr2;
            } else {
                int multiple = result / subStr2.length();
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < multiple; i++) {
                    sb.append(subStr2);
                }
                return sb.toString();

            }
            
        } else {
            return "";
        }
        
    }

    public String innerGcdOfStrings(String parent) {
        char start = parent.charAt(0);
        for (int i = 1; i < parent.length(); i++) {
            char compare = parent.charAt(i);
            if (compare == start) {
                if (2 * i > parent.length()) {
                    return parent;
                }
                boolean flag = true;
                for (int j = 1; j < i; j++) {
                    if (parent.charAt(j) != parent.charAt(i + j)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    String sub = parent.substring(0, i);
                    if (parent.split(sub).length == 0) {
                        return sub;
                    }
                }
            }
        }

        return parent;
    }
}
```