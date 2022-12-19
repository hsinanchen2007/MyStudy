解题思路：用栈+哈希表来实现，栈用来实现栈的接口，获取最小值接口用哈希表来维护，哈希表存储当前栈的深度与当前深度最小值的映射。
Talk is cheap, show me the code:

```
class MinStack {

    Stack<Integer> stack;
    Map<Integer,Integer> map;

    /** initialize your data structure here. */
    public MinStack() {
        stack = new Stack();
        map = new HashMap();
        map.put(0, Integer.MAX_VALUE);
    }
    
    public void push(int x) {
        stack.push(x);
        map.put(stack.size(),Math.min(map.get(stack.size()-1),x));
    }
    
    public void pop() {
        map.put(stack.size(), null);
        stack.pop();
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int getMin() {
        return map.get(stack.size());
    }
}
```
