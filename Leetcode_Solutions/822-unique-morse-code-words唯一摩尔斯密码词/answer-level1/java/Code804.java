### 解题思路
TreeSet自带过滤重复元素~

### 代码

```java
class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        if (words.length <= 0) {
            return 0;
        }

        String[] morseArr = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        TreeSet<String> treeSet = new TreeSet<>();
        for (int i = 0; i < words.length; i++) {
            String word = words[i];

            StringBuilder sb = new StringBuilder();
            char[] charArr = word.toCharArray();
            for (int j = 0; j < charArr.length; j++) {
                char c = charArr[j];
                String morse = morseArr[c - 97];
                sb.append(morse);
            }

            treeSet.add(sb.toString());
        }

        return treeSet.size();
    }
}
```