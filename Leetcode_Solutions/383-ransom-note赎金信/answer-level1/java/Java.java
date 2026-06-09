

### 代码

```java
import java.util.HashMap;
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        HashMap<Character, Integer> map = new HashMap<>();
        for (char c : magazine.toCharArray())
            map.put(c, map.getOrDefault(c, 0) + 1);
        for (char c : ransomNote.toCharArray())
            map.put(c, map.getOrDefault(c, 0) - 1);
        return map.values().stream().allMatch(i -> i >= 0);
    }
}
```