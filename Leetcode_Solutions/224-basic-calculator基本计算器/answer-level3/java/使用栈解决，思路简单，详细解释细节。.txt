## 分析：
- 这道题思路不难，就是使用一个栈，就像判断括号是否有效那题一样。
- 只不过，遇到右括号不仅需要找到左括号并删除它，还需要把括号内的值全都计算出来，并把计算好的值再放回栈中。
- 这样，当所有的括号都删除后，你就能把括号内的数字都计算出来。
- 不过，如果一个式子它的最外层没有括号,比如例题1和2。你还要在最后再计算一下剩下没有括号时的情况。
- 好了，思路说完了，但是这道题想要实现真的很麻烦。

## 代码：
```python
class Solution:
    def calculate(self, s: str) -> int:
        return eval(s)
```
- 开个玩笑，如果使用这个方法会`MemoryError`,别问我怎么知道的。
```java
class Solution {
    public int calculate(String s) {
        Stack<Integer> stack = new Stack();
        for (char ch : s.toCharArray()) {
            if (ch == ' ') continue;
            if (ch == ')') {//遇到右括号就去找栈内最近的左括号，并把括号内的值计算出来后再放回栈中。
                int sum = 0;// 当前括号计算的值
                while (stack.size() > 0 && stack.peek() != -111111111) {
                    int num = stack.pop();// 一个数字的值
                    if (stack.size() > 0 && stack.peek() == -333333333) sum -= num;//如果是减号就减
                    else sum += num;// 否则是加号就加。
                    if (stack.peek() != -111111111)stack.pop();//把加号或者减号弹出，注意别把左括号也弹出去了，否则就出问题了。
                }
                if (stack.size() > 0 && stack.peek() == -111111111) stack.pop();// 删除左括号
                stack.push(sum);//把括号内算得的数字再入栈。
            } else {
                //   ( -111111111    + -222222222    - -333333333
                if (Character.isDigit(ch)) {//如果是数字的话比较麻烦，因为数字可能不止个位数。
                    //这里取数字写的不好，一直在入栈出栈，欢迎你写出更好的代码一起交流。
                    if (stack.size() > 0 && stack.peek() >= 0) {//由于都是正整数，所以小于0的都是符号，而且不可能有两个算好的数字相连
                        stack.push(stack.pop() * 10 + (int)(ch - '0'));
                    } else {//否则说明这是一个个位数数字。
                        stack.push((int)(ch - '0'));
                    }
                } else if (ch == '+') {
                    stack.push(-222222222);
                } else if (ch == '-'){
                    stack.push(-333333333);
                } else { // 左括号
                    stack.push(-111111111);
                }
            }
        }
        if (stack.size() == 1) return stack.peek();
        //如果栈内只有一种元素，那么只可能是数字，并且是最终答案，因为如果有符号一定不止一个，如果有括号，之前一定将他们都消掉了，因为括号一定是成对出现的。
        int sum = 0;
        while (stack.size() > 0) {//如果不止一个，说明最外层没有括号，之前只会算括号内的数字，然后自己再计算最后一遍，得到答案。
            int num = stack.pop();// 一个数字的值
            if (stack.size() > 0 && stack.peek() == -333333333) sum -= num;
            else sum += num;
            if (stack.size() > 0) stack.pop();
        }
        return sum;
    }
}
```