### 解题思路
直接上代码

### 代码

```java
class StackOfPlates {
    private ArrayList<Stack<Integer>> stacks;
    private int capacity;
    public StackOfPlates(int cap) {
        this.stacks = new ArrayList<Stack<Integer>>();
        this.capacity = cap;
    }
    
    public void push(int val) {
        if (capacity <= 0) 
            return;
        // call push to last stack in the array of stacks
        // create new stack if last stack is at capacity;
        Stack last = getLastStack();
        if (last != null && last.size() < capacity) {
            last.push(val);
        } else {
            Stack<Integer> newStack = new Stack<Integer>();
            newStack.push(val);
            stacks.add(newStack);
        }
    }
    
    public int pop() {
        return popAt(stacks.size() - 1);
    }
    
    public int popAt(int index) {
        if (index < 0 || index >= stacks.size()) {
            return -1;
        }
        Stack<Integer> stack = stacks.get(index);
        if (stack.size() == 0)
            return -1;
        int val = stack.pop();

        // if the stack is empty; remove it from the list of stacks
        if (stack.size() == 0) {
            stacks.remove(index);
        }
        return val;
    }

    public Stack getLastStack() {
        if (stacks.size() == 0)
            return null;
        return stacks.get(stacks.size() - 1);
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