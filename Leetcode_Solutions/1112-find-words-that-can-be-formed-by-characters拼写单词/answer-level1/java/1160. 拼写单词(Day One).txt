### 法一
用一个数组记录字母表中相应字母的个数，用一次减掉一个，当发现字母表中没有字母时则表示没有掌握该单词。

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] charCount = new int[26];
        for (int i = 0; i < chars.length(); i++) {
            int index = chars.charAt(i) - 'a';
            if (index >= 26) {
                continue;
            }
            charCount[index] += 1;
        }
        int length = 0;
        boolean yes = true;
        int[] tmpArray = new int[26];
        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            System.arraycopy(charCount, 0, tmpArray, 0, 26);
            yes = true;
            for (int j = 0; j < word.length(); j++) {
                int index = word.charAt(j) - 'a';
                if (index >= 26) {
                    continue;
                }
                if (tmpArray[index] > 0) {
                    tmpArray[index] -= 1;
                    continue;
                }
                yes = false;
                break;
            }
            if (yes) {
                length += word.length();
            }
        }

        return length;
    }
}
```

### 法二

上面的方法要求copy数组，但是如果反过来用辅助数组，则不需copy，有助于提高效率.
```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] charCount = new int[26];
        for (int i = 0; i < chars.length(); i++) {
            int index = chars.charAt(i) - 'a';
            charCount[index] += 1;
        }
        int length = 0;
        boolean yes = true;
        
        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            yes = true;
            int[] tmpArray = new int[26];
            for (int j = 0; j < word.length(); j++) {
                int index = word.charAt(j) - 'a';
                if (tmpArray[index] == charCount[index]) {
                    yes = false;
                    break;
                }
                tmpArray[index]++;
            }
            if (yes) {
                length += word.length();
            }
        }

        return length;
    }
}
```
