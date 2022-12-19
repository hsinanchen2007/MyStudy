![image.png](https://pic.leetcode-cn.com/82334347d7638553805318f9e31ab613141503b0487ce05651566b2f2c2be339-image.png)

```java
class Solution {
    public String defangIPaddr(String address) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < address.length(); i++) {
            char c = address.charAt(i);
            if (c != '.') {
                sb.append(c);
            } else {
                sb.append("[.]");
            }
        }
        return sb.toString();
    }
}
```
或者直接用`replace`, 一行就可以了
