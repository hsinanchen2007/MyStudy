### 解题思路
使用递归调用，对返回的结构字符串进行字符遍历，推算出它的上一项的值。

### 代码

```java
class Solution {
    public String countAndSay(int n) {

        if (n == 1) return "1";

        String res = countAndSay(n - 1);

        char c = res.charAt(0);
        int count = 1;
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i < res.length(); i++) {
            if (res.charAt(i) == c){
                count++;
            }else {
                sb.append(count);
                sb.append(c);
                c = res.charAt(i);
                count = 1;
            }
        }
        sb.append(count);
        sb.append(c);

        return sb.toString();
    }
}
```