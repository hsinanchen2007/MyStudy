执行用时 :2 ms, 在所有 Java 提交中击败了99.23%的用户
内存消耗 :36.3 MB, 在所有 Java 提交中击败了97.20%的用户

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        s = s.trim();
        String[] wordList = s.split(" ");
        StringBuilder answer = new StringBuilder();
        for (int i = wordList.length - 1; i > -1; i--) {
            if (wordList[i].equals("")) {
                continue;
            } else {
                if (i == 0) {
                    answer.append(wordList[i]);
                } else {
                    answer.append(wordList[i]).append(" ");
                }
            }
        }
        return answer.toString();
    }
}
```