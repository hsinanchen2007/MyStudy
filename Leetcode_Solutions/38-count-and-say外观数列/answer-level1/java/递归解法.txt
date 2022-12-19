### 解题思路
就是个数和字符拼接

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
          String forward = countAndSay(n-1); 
          int index = 0;
          StringBuilder sb = new StringBuilder("");
          for (int i = 0;i < forward.length();i++){
              if (forward.charAt(i) != forward.charAt(index)){
                  sb.append("" + (i - index) + forward.charAt(index));
                     index = i;
              }
          }
          return sb.append("" + (forward.length()-index) + forward.charAt(index)).toString();
    }
}
```