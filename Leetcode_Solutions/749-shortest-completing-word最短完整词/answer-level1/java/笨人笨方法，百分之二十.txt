### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    Map<Character, Integer> map = new HashMap<>();

    public String shortestCompletingWord(String licensePlate, String[] words) {
        String result = "11111111111111";
        char[] chars = licensePlate.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if (!Character.isLetter(chars[i])) {
                continue;
            }
            map.put(Character.toLowerCase(chars[i]), map.getOrDefault(Character.toLowerCase(chars[i]), 0) + 1);
        }
        for (int i = 0; i < words.length; i++) {
            if (isOK(words[i])) {
                result = words[i].length() < result.length() ? words[i] : result;
            }
        }
        return result;
    }

    private boolean isOK(String word) {
        HashMap<Character, Integer> mapTmp = new HashMap<>();
        char[] chars = word.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            mapTmp.put(chars[i], mapTmp.getOrDefault(chars[i], 0) + 1);
        }

        for (Map.Entry entry : map.entrySet()) {
            if (!mapTmp.containsKey(entry.getKey())) {
                return false;
            }
            if (map.get(entry.getKey()) > mapTmp.get(entry.getKey())) {
                return false;
            }
        }
        return true;
    }
}
```