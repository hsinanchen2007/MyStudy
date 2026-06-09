### 解题思路
StringBuilder的append方法竟然也能直接传入int型，思路就是一个一个算

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        String previous = "1";
        for (int i = 1; i < n; i++) {
            StringBuilder s = new StringBuilder();
            for (int j = 0; j < previous.length(); j++) {
                int count = 1;
                while (j < previous.length() - 1 && previous.charAt(j) == previous.charAt(j + 1)) {
                    count++;
                    j++;
                }
                s.append(count);
                s.append(previous.charAt(j));
            }
            previous = s.toString();
        }
        return previous;
    }
}
```