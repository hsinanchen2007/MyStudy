### 解题思路
遍历每一个字符，每一次查单词，查过的字符置为0.遍历出能查到的单次，保存长度。

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int maxLength = 0;
        for (String word : words){
            char[] charWord = word.toCharArray();
            char[] chars1 = chars.toCharArray();
            int i;
            for(i = 0; i < charWord.length;) {
                int j;
                for( j = 0; j < chars1.length; j++) {
                    if(charWord[i] == chars1[j]){
                        chars1[j] = 0;
                        i++;
                        break;
                    }
                }
                if(j == chars1.length){
                    break;
                }
            }
            if(i == charWord.length){
                maxLength += word.length();
            }
        }
        return maxLength;
    }
}
```