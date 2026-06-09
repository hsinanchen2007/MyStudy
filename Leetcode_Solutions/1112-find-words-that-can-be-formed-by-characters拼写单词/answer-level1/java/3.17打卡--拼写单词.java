

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] table = new int[26];
        int result = 0;
        for(char c: chars.toCharArray()){
            table[c-'a']++;
        }
        for(String s: words){
            int[] count = new int[26];
            boolean sign = true;
            for(char c: s.toCharArray()){
                count[c-'a']++;
                if(count[c-'a']>table[c-'a']){
                    sign = false;
                    break;
                }
            }
            if(sign) result += s.length();
        }
        return result;
    }
}
```