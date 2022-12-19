菜菜的我第一次参加竞赛，一个半小时就做了一道简单类的题目。看到那些大佬十几分钟就做完了所有的题，真可谓是惊为天人、望尘莫及、瞠目结舌、难以望其项背呀！说说菜鸟的思路吧！

**1、先对字符串进行排序。
2、将排好序的字符按从大到小的顺序塞进栈1当中，这样该栈出栈的时候就是从小到大啦！
3、先判断栈1是否为空，若为空则直接结束；如果不为空则默认出栈顶元素，并且将其添加到结果串的末尾，同时获取该字符作为后面出栈元素的比较字符compare。然后是一个循环，只要栈不为空，就判断栈顶元素是否等于compare,如果等于则将其放入栈2当中（因为是顺序排列且相等说明已经添加过结果串啦！）如果不等于，就将该字符添加到结果串的末尾，同时更新compare。
4、此时栈2出栈就已经是从大到小的啦，逻辑和栈1出栈时是一致的就不再赘述。
5、这里面有一个count是控制最外层循环的，当我们向结果串末尾添加一个字符时就要加一啦，直到count=字符串的长度，就说明整个字符串已经都遍历一次啦！**

继续努力，慢慢能做出两道题、三道题、四道题。然后就是和时间的赛跑了，虽然还很漫长和遥远，but我会加油的！
```
class Solution {
    public String sortString(String s) {
        if (null == s) {
            return "";
        }
        // 对字符串进行排序
        int len = s.length();
        char[] array = s.toCharArray();
        Arrays.sort(array);
        // 用栈1存储从小到大未遍历的字符，用栈2来存储从大到小未遍历的字符
        Stack<Character> stack1 = new Stack<>();
        Stack<Character> stack2 = new Stack<>();
        for (int i = len - 1; i >= 0; i--) {
            stack1.push(array[i]);
        }
        int count = 0;
        StringBuilder stringBuilder = new StringBuilder(len);
        while (count < len) {
            if (stack1.isEmpty()) {
                break;
            }
            char compare = stack1.peek();
            stringBuilder.append(stack1.pop());
            count++;
            while (!stack1.isEmpty()) {
                char temp = stack1.pop();
                if (temp == compare) {
                    stack2.push(temp);
                } else {
                    count++;
                    stringBuilder.append(temp);
                    compare = temp;
                }
            }
            if (stack2.isEmpty()) {
                break;
            }
            compare = stack2.peek();
            count++;
            stringBuilder.append(stack2.pop());
            while (!stack2.isEmpty()) {
                char temp = stack2.pop();
                if (temp == compare) {
                    stack1.push(temp);
                } else {
                    count++;
                    stringBuilder.append(temp);
                    compare = temp;
                }
            }
        }
        return stringBuilder.toString();
    }
}
```
