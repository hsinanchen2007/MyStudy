```
package ZJM_20_有效的括号;

import java.util.HashMap;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        String str1 = "()";
        String str2 = "()[]{}";
        String str3 = "(]";
        String str4 = "";
        String str5 = "()([)]";
        String str6 = "{[]}";

        Solution solution = new Solution();
        System.out.println(solution.isValid(str1));
        System.out.println(solution.isValid(str2));
        System.out.println(solution.isValid(str3));
        System.out.println(solution.isValid(str4));
        System.out.println(solution.isValid(str5));
        System.out.println(solution.isValid(str6));

    }
}

class Solution {
    //    负责映射的哈希表
    private HashMap<Character, Character> mappings;

//        用映射初始化哈希映射。这只会使代码更容易阅读。
    public Solution() {
        this.mappings = new HashMap<Character, Character>();
        this.mappings.put(')', '(');
        this.mappings.put('}', '{');
        this.mappings.put(']', '[');
    }

    public boolean isValid(String s) {
//         初始化要在算法中使用的堆栈。
        Stack<Character> stack = new Stack<Character>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

//            如果当前字符是闭合括号。
            if (this.mappings.containsKey(c)) {

//                获取堆栈的顶部元素。如果堆栈为空，则将虚拟值设置为'#'
                char topElement = stack.empty() ? '#' : stack.pop();

//                 如果此括号的映射与堆栈的top元素不匹配，则返回false。
                if (topElement != this.mappings.get(c)) {
                    return false;
                }
            } else {
//                如果它是一个开括号，将其push到堆栈上。
                stack.push(c);
            }
        }

//        如果堆栈仍然包含元素，则它是无效的表达式。
        return stack.isEmpty();
    }
}

/**
 * 本题使用栈的思维比较容易解决，通过哈希映射使<')', '('>,<'}', '{'>,<']', '['>进行对应匹配
 * 然后将字符串的每一位进行入栈和匹配出栈，最终得到这个字符串的括号是否有效
 */

```
