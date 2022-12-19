- 解题思路：
- 当push（x），x <= min 时先将min进栈，再将x进栈；
- 也就是说在栈中的每一个min下面都存有前一个min（就是比当前min小的那个）
-


```
class MinStack {
    private Stack<Integer> stack;
    private int min;
    /** initialize your data structure here. */
    public MinStack() {
        stack = new Stack<>();
        min = Integer.MAX_VALUE;
    }
    
    public void push(int x) {
        if(x <= min ){//注意：这里要使用<=号
            stack.push(min);//在每一个min入栈之前将它前一个min入栈
            min = x;
        }
        stack.push(x);
    }
    
    public void pop() {
        if(stack.pop() == min){//如果取出来的是当前min，就将压在它低下的前一个min出栈
            min = stack.pop();
        }
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int min() {
        return min;
    }
}
```
