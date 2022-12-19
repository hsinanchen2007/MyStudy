```
/**
 * 解法一
 *
 * 利用2个栈，一个数字栈numStack，一个字母栈strStack
 * 遍历字符串
 * 1、字符为数字，解析数字（注意连续数字的情况）存入 num
 * 2、字符为字母，拼接字母 存入 str
 * 3、字符为左括号，把之前得到的数字 num 和 字母 str 分别压栈，然后把数字重置为0，字母字符串重置为空串
 * 4、字符为右括号，数字栈栈顶数字出栈，作为重复次数 n，字母栈栈顶字母出栈，作为前缀字母字符串去拼接 str 字母变量，总共拼接 n 次，拼接后的新字母串给 str
 *
 * 例如：
 * 2[abc]3[cd]ef
 *  ↑
 * 遇到左括号，把数字 num=2 和 字母 str="" 入栈，并且 num 和 str 重置
 *    |   |      |    |
 *    |   |      |    |
 *    |_2_|      |_""_|
 *   numStack    strStack
 *
 * 2[abc]3[cd]ef
 *      ↑
 * 遇到左括号，num=0 str="abc"，numStack 和 strStack 栈顶元素出栈 str = strStack.pop() + str \* numStack.pop() = "" + "abc" * 2 =  "abcabc"
 *    |   |      |   |
 *    |   |      |   |
 *    |___|      |___|
 *   numStack    strStack
 *
 * 2[abc]3[cd]ef
 *        ↑
 * 遇到右括号，数字 num=3 和 字母 str="abcabc" 入栈，并且 num 和 str 重置
 *    |   |      |        |
 *    |   |      |        |
 *    |_3_|      |_abcabc_|
 *   numStack    strStack
 *
 * 2[abc]3[cd]ef
 *           ↑
 * 遇到左括号，num=0 str=cd，numStack 和 strStack 栈顶元素出栈 str = "abcabc" + "cd" * 3 = "abcabccdcdcd"
 *    |   |      |        |
 *    |   |      |        |
 *    |_3_|      |_abcabc_|
 *   numStack    strStack
 *
 * 遍历结束，最终结果 str="abcabccdcdcdef"
 */
class Solution1 {

    public String decodeString(String s) {
        //初始化
        LinkedList<Integer> numStack = new LinkedList();
        LinkedList<String> strStack = new LinkedList();
        StringBuilder sb = new StringBuilder();
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                sb.append(c);
            } else if (c == '[') {
                if (num > 0) numStack.push(num);
                strStack.push(sb.toString());
                sb = new StringBuilder();
                num = 0;
            } else {
                //c==']'
                StringBuilder preSB = new StringBuilder().append(strStack.pop());
                int times = numStack.pop();
                for (int j = 0; j < times; j++) {
                    preSB.append(sb);
                }
                sb = preSB;
            }
        }
        return sb.toString();
    }
}
```
