### 解题思路
1 String是对象调用的是方法，substring全小写；
2 时间复杂度O(n),n为较长的字符串长度；空间复杂度O(1)。

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        int length1 = str1.length();
        int length2 = str2.length();
        if(length1 < length2) {
            String tempStr = str1;
            str1 = str2;
            str2 = tempStr;
            length1 = str1.length();
            length2 = str2.length();
        }

        for(int i = 0; i < length1; i++) {
            if(str1.charAt(i) != str2.charAt(i % length2)) {
                return "";
            }
        }

        while(length2 != 0) {
            int tempInt = length2;
            length2 = length1 % length2;
            length1 = tempInt;
        }

        return str2.substring(0, length1);
    }
}
```