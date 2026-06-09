### 解题思路
同时维护一个有序栈

时间复杂度： O(n)

改进：
对于其中的有序栈，其实并不需要完全有序。只要一个“每层max”就好：维护另外一个栈保存原始数据栈中每层的最大值。

### 代码

```java
import java.util.*;


class MaxStack {
    
    Stack<Integer> stack = new Stack<Integer> ();
    Stack<Integer> orderedStack = new Stack<Integer> ();

    /** initialize your data structure here. */
    public MaxStack() {

    }
    
    public void push(int x) {
        stack.push(x);
        Stack<Integer> tmp = new Stack<Integer> ();
        while(!orderedStack.isEmpty()){
            int o = orderedStack.pop();
            if(o > x){
                tmp.push(o);
            }else if(o <= x){
                orderedStack.push(o);
                break;
            }
        }
        orderedStack.push(x);
        while(!tmp.isEmpty()){
            orderedStack.push(tmp.pop());
        }
    }
    
    public int pop() {
        int x = stack.pop();
        Stack<Integer> tmp = new Stack<Integer> ();
        while(!orderedStack.isEmpty()){
            int o = orderedStack.pop();
            if(o == x){
                break;
            }
            tmp.push(o);
        }
        while(!tmp.isEmpty()){
            orderedStack.push(tmp.pop());
        }
        return x;
    }
    
    public int top() {
    	int x = stack.pop();
    	stack.push(x);
    	return x;
    }
    
    public int peekMax() {
    	int x = orderedStack.pop();
    	orderedStack.push(x);
    	return x;
    }
    
    public int popMax() {
    	int x = orderedStack.pop();
        Stack<Integer> tmp = new Stack<Integer> ();
        while(!stack.isEmpty()){
            int o = stack.pop();
            if(o == x){
                break;
            }
            tmp.push(o);
        }
        while(!tmp.isEmpty()){
        	stack.push(tmp.pop());
        }
        return x;
    }


}
```