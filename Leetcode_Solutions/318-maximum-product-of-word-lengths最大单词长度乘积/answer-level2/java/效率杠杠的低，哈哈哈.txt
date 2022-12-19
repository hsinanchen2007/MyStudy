### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    int max = 0;

    public int maxProduct(String[] words) {
        if (words == null || words.length == 0) {
            return max;
        }
        for (int i = 0; i < words.length - 1; i++) {
            for (int j = i + 1; j < words.length; j++) {
                if (isContainSameCharacter(words, i, j)) {
                    continue;
                }
                max = Math.max(max, words[i].length() * words[j].length());
            }
        }
        return max;
    }

    private boolean isContainSameCharacter(String[] words, int i, int j) {
        String stringi = words[i];
        String stringj = words[j];
        for (int k = 0; k < stringi.length(); k++) {
            if (stringj.contains(stringi.charAt(k) + "")) {
                return true;
            }
        }
        return false;
    }
}
```