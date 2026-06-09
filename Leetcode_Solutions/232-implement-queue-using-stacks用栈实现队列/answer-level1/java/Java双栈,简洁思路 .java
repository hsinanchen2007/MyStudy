![Screen Shot 2020-01-14 at 14.47.53.png](https://pic.leetcode-cn.com/7b5d4f63dc4ff14cb69201a6b6c5b6b10902262d565e0665a28b6cca0b891a75-Screen%20Shot%202020-01-14%20at%2014.47.53.png)
### 解题思路
输入输出双栈
辅助方法transfer() 将输入栈内容全部转移到输出栈 完成元素逆序
空间一个额外辅助栈O(N) 时间push/empty O(1) pop/peek均摊O(1)
**只有在输出栈为空时才transfer！！！** 这样可以保证均摊O(1)时间复杂度 同时能够保证一直返回最老元素
例子
转移前
input:  bottom 1 2 top
output: bottom     top
转移后 输入栈12已被逆序到输出栈为21
input:  bottom     top
output: bottom 2 1 top
若此时push(3) pop()  我们直接transfer
会得到 
input:  bottom       top
output: bottom 2 1 3 top
pop得到3并非最老的元素  **在非空的情况下我们应该pop已有的直到清空输出栈为止再考虑转移**
### 代码
```java
class MyQueue {
    Stack<Integer> input = new Stack<>(), output = new Stack<>();
    public void push(int x) { input.push(x); }
    public boolean empty() { return input.isEmpty() && output.isEmpty(); }
    private void transfer(){
        while(input.isEmpty() == false) output.push(input.pop());
    }
    public int pop() {
        if(output.isEmpty()) transfer();
        return output.pop();
    }
    public int peek() {
        if(output.isEmpty()) transfer();
        return output.peek();
    }
}
```