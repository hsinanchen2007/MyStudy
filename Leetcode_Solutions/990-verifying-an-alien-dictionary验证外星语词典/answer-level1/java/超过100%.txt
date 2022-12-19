### 解题思路
![image.png](https://pic.leetcode-cn.com/0f53e4c6e9a98e0eff2c0dca3f07af2d6ac5886ad77a8b8042fb8457ac425686-image.png)


### 代码

```java
class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        int[] map = new int[26];
        for (int i = 0; i < order.length(); i++) {
            map[order.charAt(i) - 'a'] = i;
        }
        for (int i = 0; i < words.length - 1; i++) {
            String word1 = words[i];
            String word2 = words[i + 1];

            boolean isDiff = false;
            for (int j = 0; j < Math.min(word1.length(), word2.length()); j++) {
                if (word1.charAt(j) != word2.charAt(j)) {
                    isDiff = true;
                    if (map[word1.charAt(j) - 'a'] > map[word2.charAt(j) - 'a']) {
                        return false;
                    }
                    break;
                }
            }

            if(!isDiff){
                if (word1.length() > word2.length()) {
                    return false;
                }
            }
        }

        return true;
    }
}
```