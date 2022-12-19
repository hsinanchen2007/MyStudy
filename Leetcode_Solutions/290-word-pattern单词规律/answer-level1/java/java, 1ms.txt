### 解题思路
用到了哈希表，想法很简单

### 代码

```java
import java.util.ArrayList;
import java.util.HashMap;
class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] wordList = str.split(" ");
        if (pattern.length() != wordList.length) {
            return false;
        }
        StringBuilder uniquePatterns = new StringBuilder();
        ArrayList<String> uniqueWords = new ArrayList<>();
        HashMap<String,String> match = new HashMap<>();
        String singlePattern;
        String singleWord;
        for (int i = 0; i < pattern.length(); i++) {
            singlePattern = String.valueOf(pattern.charAt(i));
            singleWord = wordList[i];
            if(uniquePatterns.indexOf(singlePattern) == -1){
                match.put(singlePattern,singleWord);
                uniquePatterns.append(singlePattern);
                if (uniqueWords.contains(singleWord)) {
                    return false;
                }
                uniqueWords.add(singleWord);
            }else {
                if (!match.get(singlePattern).equals(singleWord)) {
                    return false;
                }
            }
        }
        return true;
    }
}
```