解题思路，先split获得单词数组
然后通过栈<Stack>先进后出的特性翻转单词
拼接字符串

```
public class Main {

    public static void main(String[] args) {
        String a = "Let's take LeetCode contest";
        Solution s = new Solution();
        System.out.println(s.reverseWords(a));
    }
}


class Solution {

    public String reverseWords(String s) {
        Stack<Character> stack = new Stack<>();
        String[] words = s.split(" ");
        StringBuilder builder = new StringBuilder();
        for (String word : words) {
            for (int i = 0; i < word.length(); i++) {
                stack.push(word.charAt(i));
            }
            while (!stack.empty()) {
                builder.append(stack.pop());
            }
            builder.append(" ");
        }
        return builder.deleteCharAt(builder.length() - 1).toString();
    }
}
```
