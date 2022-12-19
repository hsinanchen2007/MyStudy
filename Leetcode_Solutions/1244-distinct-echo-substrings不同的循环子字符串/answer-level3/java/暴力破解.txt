### 解题思路
好吧，简单的暴力破解，将所有有重复的放入set中，然后返回set的数量

### 代码

```java
class Solution {
    public int distinctEchoSubstrings(String text) {
        Set<String> set = new HashSet<>();
        for (int i = 1; i < text.length(); i++) {
            int end = i + 1;
            int middle = (i + 1) / 2 + 1;
            for (int j = 1; j < middle; j++) {
                String sub1 = text.substring(end - j, end);
                String sub2 = text.substring(end - j * 2, end - j);
                if (sub1.equals(sub2)) {
                    set.add(sub1);
                }
            }
        }
        return set.size();
    }

}
```