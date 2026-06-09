### 解题思路
将text所有字符存入map
一直遍历balloon字符串，然后map里一直--，直到map中有字符不够的情况，结束循环。

### 代码

```java
class Solution {
    String target = "balloon";

    public int maxNumberOfBalloons(String text) {
        HashMap<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < text.length(); i++) {
            map.put(text.charAt(i), map.getOrDefault(text.charAt(i), 0) + 1);
        }

        int count = 0;
        boolean isBreak = false;
        while (true) {
            for (int i = 0; i < target.length(); i++) {
                Character character = target.charAt(i);
                if (!map.containsKey(character)) {
                    isBreak = true;
                    break;
                }
                if (map.get(character) == 0) {
                    isBreak = true;
                    break;
                }
                if (map.containsKey(target.charAt(i))) {
                    map.put(character, map.get(character) - 1);
                }
            }
            if (isBreak) {
                break;
            }
            count++;
        }
        return count;
    }
}
```