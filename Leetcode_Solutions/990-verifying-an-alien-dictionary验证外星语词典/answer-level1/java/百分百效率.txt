### 解题思路
思路，前后两个字符串，两两比较，如果前面的字符串都相等，长度小的应该排在前面。

### 代码

```java
class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        for (int i = 0; i < words.length - 1; i++) {
            String word1 = words[i];
            String word2 = words[i + 1];
            int index = 0;
            //逐个字符比较
            while (index < word1.length() && index < word2.length()) {
                int priority1 = order.indexOf(word1.charAt(index));
                int priority2 = order.indexOf(word2.charAt(index));
                if (priority1 < priority2) {
                    break;
                }
                if (priority1 > priority2) {
                    return false;
                }
                index++;
            }
            //特殊情况，比如apple 、app这种情况
            if (word1.length() > word2.length() && index == word2.length()) {
                return false;
            }
        }
        return true;
    }
}
```