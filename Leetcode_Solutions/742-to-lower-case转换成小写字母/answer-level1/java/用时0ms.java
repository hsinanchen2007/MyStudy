![image.png](https://pic.leetcode-cn.com/284c133f2ba5e58c45ce9e5a1c9f68a3b9ac32f91ff12c00f2ba7310e0a0517a-image.png)
```
class Solution {
        public String toLowerCase(String str) {
            if (str==null)
                return null;
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i <str.length() ; i++) {
                char c = str.charAt(i);
                if (c<='Z' && c>='A'){
                    c = (char)(c-'A' + 'a');
                    sb.append(c);
                }else sb.append(c);
            }
            return sb.toString();
        }
    }
```
