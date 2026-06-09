### 解题思路

直接是遍历每个字符，只要在chars中出现了，就替换，于是乎，时间复杂度和空间复杂度暴增。

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int len = 0;
        for(String word : words) {
            len += process(word, chars);
        }
        return len;
    }

    private int process(String word, String chars){
        for(char aw : word.toCharArray()) {
            if(chars.indexOf(aw) < 0){
                return 0;
            }
            chars = chars.replaceFirst(String.valueOf(aw), "");
        }
        return word.length();
    }
}
```