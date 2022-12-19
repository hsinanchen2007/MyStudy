执行用时 :4 ms, 在所有 Java 提交中击败了92.97%的用户
内存消耗 :35.6 MB, 在所有 Java 提交中击败了83.58%的用户
```java
class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        if (words.length <= 0) {
            return 0;
        }
        String[] code = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        Set<String> items = new HashSet<>((int) (words.length / 0.75 - 1));
        StringBuilder sb;
        for (String str : words) {
            sb = new StringBuilder(str.length());
            for (char character : str.toCharArray()) {
                sb.append(code[character - 'a']);
            }
            items.add(sb.toString());
        }
        return items.size();
    }
}
```
总感觉用set有点作弊......