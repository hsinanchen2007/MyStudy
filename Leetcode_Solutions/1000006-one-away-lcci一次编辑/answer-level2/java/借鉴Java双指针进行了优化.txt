### 解题思路
对于替换操作不用多说，遍历字符，统计相同位置上字符不同的大于一个定值即可
对于删除和插入操作，定义双指针，遍历字符，相同位置上字符不同的，长度长的字符串移动指针，直到不同字符数大于一个定值

### 代码

```java
class Solution {
        public boolean oneEditAway(String first, String second) {
            if (first.equals(second)) {
                return true;
            }
            if (Math.abs(first.length() - second.length()) > 1) {
                return false;
            }
            int count = 0;
            //替换
            if (first.length() == second.length()) {
                for (int i = 0; i < first.length(); i++) {
                    if (first.charAt(i) != second.charAt(i)) {
                        count++;
                    }
                }
                 if (count > 1) {
                      return false;
                }
            } else if (first.length() > second.length()) {//删除
                for (int m = 0, n = 0; n < second.length(); m++) {
                     if (count > 1) {
                       return false;
                    }
                    if (first.charAt(m) != second.charAt(n)) {
                        count++;
                        continue;
                    }
                    n++;
                }

            } else if (first.length() < second.length()) {//插入
                for (int k = 0, h = 0; h < first.length(); k++) {
                    if (count > 1) {
                       return false;
                    }
                    if (second.charAt(k) != first.charAt(h)) {
                        count++;
                        continue;
                    }
                    h++;
                }
            }
            return true;
        }
    }
```