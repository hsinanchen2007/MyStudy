### 解题思路
1.构建数据结构，因涉及插入和删除操作多，故选用LinkedList而非ArrayList
2.push直接调用Stack类的同名方法
3.pop调用坡popAt方法
4.popAt方法总是调用链表里最末尾的栈

### 代码

```java
class StackOfPlates {

    private List<Stack<Integer>> setOfStacks;
    private int cap;
    public StackOfPlates(int cap) {
        this.cap = cap;
        setOfStacks = new LinkedList<>();
    }
    
    public void push(int val) {
        if(cap <= 0) return;
        //如果集合为空，或上一个栈已满，创建新栈
        if(setOfStacks.isEmpty() || setOfStacks.get(setOfStacks.size() - 1).size() == cap) {
            Stack<Integer> stack = new Stack<>();
            stack.push(val);
            setOfStacks.add(stack);
            return;
        }
        setOfStacks.get(setOfStacks.size() - 1).push(val);
    }
    
    public int pop() {
        return popAt(setOfStacks.size() - 1);
    }
    
    public int popAt(int index) {
        //参数校验
        if(index < 0 || index > setOfStacks.size() - 1) return -1;
        //获取当前栈
        Stack<Integer> stack = setOfStacks.get(index);
        if(stack.isEmpty()) {
            setOfStacks.remove(index);
            return -1;
        }
        int result = stack.pop();
        if(stack.isEmpty()) {
            setOfStacks.remove(index);
        }
        return result;
    }
}

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates obj = new StackOfPlates(cap);
 * obj.push(val);
 * int param_2 = obj.pop();
 * int param_3 = obj.popAt(index);
 */
```