### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseWords(String s) {

            if (s.length() < 1) {
                return s;
            }
            String str = "";

            String[] strings = s.split(" ");

            for (int i = 0; i < strings.length-1; i++) {
                str += reverseString(strings[i].toCharArray()) + " ";
            }
            str += reverseString(strings[strings.length-1].toCharArray());
            //System.out.println(str);
            return str;
    }

            public String reverseString(char[] s) {

            if (s.length < 2) {
                return String.valueOf(s[0]);
            }

            int start = 0, end = s.length-1;

            while (start < end) {
                char c = s[start];
                s[start] = s[end];
                s[end] = c;
                start++;
                end--;
            }

            StringBuilder stringBuilder = new StringBuilder();
            for (int i = 0; i < s.length; i++) {
                stringBuilder.append(s[i]);
            }

            return stringBuilder.toString();
        }
}
```