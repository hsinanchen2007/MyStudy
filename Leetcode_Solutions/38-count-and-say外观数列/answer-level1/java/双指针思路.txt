### 解题思路
双指针，直接上代码

### 代码

```java
class Solution {
    public String countAndSay(int n) {

        String res = "1";

        String str;

        for (int i = 2; i <= n; i++) {

            str = res;
            res = "";

            int m = 0;
            int j = 1;
            for (; j < str.length(); j++) {
                if (str.charAt(m) != str.charAt(j)) {
                    res += (j - m) + "" + str.charAt(m);
                    m = j;
                }
            }
             res += (j - m) + "" + str.charAt(m);
        }
        return res;   
    }
}
```