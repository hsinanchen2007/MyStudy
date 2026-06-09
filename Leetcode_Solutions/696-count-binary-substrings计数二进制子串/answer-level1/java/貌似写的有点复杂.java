思路：
用栈：
栈为空，入栈，记录栈中0和1的个数
栈不为空，比较当前入栈元素和栈顶元素是否相等，不相等，总数加1，栈顶元素个数设置为1
相等，判断入栈元素（包含入栈）的总个数s是否小于等于另外一个元素的个数，等于+1，不等于继续循环

class Solution {
    public int countBinarySubstrings(String s) {
        //计数
        int count = 0, zero = 0, one = 0;
        char[] ct = s.toCharArray();
        Stack<Character> stack = new Stack<>();

        for (char c : ct) {
            //首次入栈
            if (stack.isEmpty()) {
                stack.push(c);
                //temp只是一个媒介，只是为了给zero和one做三元运算
                int temp = (c == '0' ? zero++ : one++);
            } else {
                //栈不为空和顶部做比较，不相等count++，与当前相等的元素个数设置为1，入栈
                if (stack.peek() != c) {
                    count++;
                    stack.push(c);
                    if (c == '0')
                        zero = 1;
                    else
                        one = 1;

                } else {
                    //顶部相等，比较zero和one的个数是否相等，相等则count++，否则直接入栈，相应变量（zero、one）增加
                    stack.push(c);
                    int temp = (c == '0' ? zero++ : one++);
                    //非当前元素个数大于等于当前元素个数时候
                    
                    if ((c=='0' && zero<=one) || (c=='1' && one<=zero))
                        count++;
                    else
                        continue;
                }
            }
        }

        return count;
    }
}