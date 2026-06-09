### 解题思路

使用回溯算法+缓存解决此题。

### 代码

```java
class Solution {
    public int minDistance(String word1, String word2) {
        int[][] cache = new int[word1.length()][word2.length()];
        for (int i = 0; i < cache.length; i++) {
            Arrays.fill(cache[i], -1);
        }
        return minDistanceBacktrace(cache, word1, word2, 0, 0);
    }

    private int minDistanceBacktrace(int[][] cache, String word1, String word2, int pos1, int pos2) {
        int result;
        if (pos2 == word2.length()) {
            return word1.length() - pos1;
        } else if (pos1 == word1.length()) {
            return word2.length() - pos2;
        } else if (cache[pos1][pos2] >= 0) {
            return cache[pos1][pos2];
        } else if (word1.charAt(pos1) == word2.charAt(pos2)) {
            result = minDistanceBacktrace(cache, word1, word2, pos1 + 1, pos2 + 1);
        } else {
            result = minDistanceBacktrace(cache, word1, word2, pos1 + 1, pos2) + 1;
            result = Math.min(result, minDistanceBacktrace(cache, word1, word2, pos1, pos2 + 1) + 1);
            result = Math.min(result, minDistanceBacktrace(cache, word1, word2, pos1 + 1, pos2 + 1) + 1);
        }

        cache[pos1][pos2] = result;
        return result;
    }
}
```