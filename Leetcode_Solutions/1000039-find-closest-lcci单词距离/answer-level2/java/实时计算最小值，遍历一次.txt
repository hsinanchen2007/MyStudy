### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findClosest(String[] words, String word1, String word2) {
  
        int word1No = -1;
        int word2No = -1;
        int length = -1;

        for (int i = 0; i < words.length; i++) {
            if (words[i].equals(word1)) {
                word1No = i;
            }
            if (words[i].equals(word2)) {
                word2No = i;
            }
            if (word1No >= 0 && word2No >=0 ) {
                int abs = Math.abs(word1No - word2No);
                if (length == -1 || abs < length) {
                    length = abs;
                }
            }
        }
        return length;
    }
}
```