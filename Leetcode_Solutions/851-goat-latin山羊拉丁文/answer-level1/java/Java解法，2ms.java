执行用时 : 2 ms , 在所有 Java 提交中击败了 95.87% 的用户
内存消耗 : 34.6 MB , 在所有 Java 提交中击败了 96.84% 的用户

### 代码

```java
class Solution {
    public String toGoatLatin(String S) {
        StringBuilder answer = new StringBuilder();
        int index = 1;
        for (String i : S.split(" ")) {
            char l = i.charAt(0);
            if (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u' || l == 'A' || l == 'E' || l == 'I' || l == 'O' || l == 'U') {
                answer.append(i).append("ma");
                for (int j = 0; j < index; j++) answer.append('a');
                answer.append(' ');
                index++;
            } else {
                answer.append(i.substring(1)).append(l).append("ma");
                for (int j = 0; j < index; j++) answer.append('a');
                answer.append(' ');
                index++;
            }
        }
        answer.deleteCharAt(answer.length()-1);
        return answer.toString();
    }
}
```