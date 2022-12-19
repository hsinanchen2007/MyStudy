### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        StringBuilder res = new StringBuilder();
        if (s == null || s.length() < 1|| s.length() == 1&& s.charAt(0) != ' ') return s;

        int end = s.length()-1;
        int i = end-1;
        while (i >=0){
            while (end >= 0&& s.charAt(end) == ' ') end -= 1;
            
            if (i==0||(s.charAt(i) == ' '&& s.charAt(i+1) != ' ')){
                if (i == 0) {
                    res.append(' ');
                }
                res.append(s.substring(i, end+1));
                end = i;
                i -= 1;
            }
            else {
                i -= 1;
            }
        }

        return res.toString().trim();
    }
}
```