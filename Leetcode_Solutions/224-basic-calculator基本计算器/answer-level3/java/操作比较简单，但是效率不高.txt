### 解题思路
1、利用字符串替换，切割方法，将输入分割成各个元素（splitString方法）
2、从后往前遍历，将元素入栈（之所以要从后往前，是为了方便数学运算）
3、如果遇到“（”，则将栈中元素出栈进行计算（calculateSome方法）
4、最终得到的可能是一个数字，或者一个没有括号的表达式（再运算一边）

calculateSome方法思路：
不断取出栈中元素，第一个肯定是数字，第二个有三种情况：
1、“-”，则再取出一个元素（肯定是数字），进行减法运算
2、“+”，则再取出一个元素（肯定是数字），进行加法运算
3、“）”,则允许结束。

执行用时 :130 ms, 在所有 java 提交中击败了21.98%的用户
内存消耗 :59.9 MB, 在所有 java 提交中击败了14.02%的用户

### 代码
```java
class Solution {
public static int calculate(String s) {
        Stack<String> stack = new Stack<>();
        String[] items = splitString(s);
        for (int i = items.length - 1; i >= 0 ; i--) {
            switch (items[i]) {
                case ")": case "+": case "-" :
                    stack.push(items[i]);
                    break;
                case "(" :
                    calculateSome(stack);
                    break;
                default:
                    stack.push(items[i]);
            }
        }
        calculateSome(stack);
        return Integer.parseInt(stack.pop());
    }
    private static void calculateSome(Stack<String> stack) {
        int x = Integer.parseInt(stack.pop());
        while (!stack.isEmpty()) {
            if (stack.peek().equals("-")) {
                stack.pop();
                x -= Integer.parseInt(stack.pop());
                continue;
            }
            if (stack.peek().equals("+"))  {
                stack.pop();
                x += Integer.parseInt(stack.pop());
                continue;
            }
            if (stack.peek().equals(")"))  {
                stack.pop();
            }
            break;
        }
        stack.push(Integer.toString(x));
    }
    private static String[] splitString(String s) {
        String res = s.replace("+", ",+,")
                .replace("-", ",-,")
                .replace("(", "(,")
                .replace(")", ",)")
                .replace(" ", "");
        System.out.println(Arrays.asList(res.split(",")));
        return res.split(",");

    }
}
```