### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {

        Map<Character, Integer> charsMap = new HashMap<>();
        for (char c : chars.toCharArray()) {
            int count = charsMap.getOrDefault(c, 0);
            count++;
            charsMap.put(c, count);
        }
        int result = 0;
        Map<Character, Integer> wordMap = new HashMap<>();
        for (String word : words) {
            for (char c : word.toCharArray()) {
                int count = wordMap.getOrDefault(c, 0);
                count++;
                wordMap.put(c, count);
            }
            boolean flag = true;
            for (char c : wordMap.keySet()) {
                if (wordMap.get(c) > charsMap.getOrDefault(c, 0)) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                result += word.length();
            }

            wordMap.clear();
        }

        return result;

    }
}
```