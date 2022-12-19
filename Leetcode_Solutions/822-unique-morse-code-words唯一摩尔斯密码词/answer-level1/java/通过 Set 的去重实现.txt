### 解题思路
通过 Set 的去重，可以方便的存放翻译后的各个单词的摩尔斯密码，一旦出现不同的摩尔斯密码才会添加到 Set 中，最终返回 Set 的大小就可以了。

### 代码

```java
class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        Set<String> translate = new HashSet<>();

        for (String word : words) {
            char[] chars = word.toCharArray();
            String translation = "";
            for (char c : chars) {
                int cint = ((int) c) - 97;
                translation = translation + morse[cint];
            }
            translate.add(translation);
        }
        return translate.size();
    }
}
```