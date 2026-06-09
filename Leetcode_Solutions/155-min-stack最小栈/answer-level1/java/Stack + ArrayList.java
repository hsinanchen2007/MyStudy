### 解题思路
Stack完成基本的push pop top，使用ArrayList辅助完成最小值的获取，push的同时向ArrayList中按大小顺序插入push的值，pop时同时删除相应的值，getMin方法直接返回ArrayList中的第一个对象，要注意的是push操作的细节比如插入到ArrayList的第一位或者最后一位的处理，以及stack为空的情况。

### 代码

```java
import java.util.*;

class MinStack {
    private Stack<Integer> stack;
    private List<Integer> list;
    /** initialize your data structure here. */
    public MinStack() {
        stack = new Stack<Integer>();
        list = new ArrayList<Integer>();
    }
    
    public void push(int x) {
        stack.push(x);
        if(list.size()==0||list.get(list.size()-1)<=x)list.add(x);
        else{
            for(int i = 0; i<list.size();i++){
                if(x<list.get(i)){
                    list.add(i,x);
                    break;
                }
            }
        }
        
    }
    
    public void pop() {
        if(list.size()!=0){
            int i =stack.pop();
            list.remove(new Integer(i));
        }else{
            throw new RuntimeException("栈中元素为空，此操作非法");
        }
    }
    
    public int top() {
        if(list.size()!=0)
        return stack.peek();
        throw new RuntimeException("栈中元素为空，此操作非法");
    }
    
    public int getMin() {
        if(list.size()!=0)
        return list.get(0);
        throw new RuntimeException("栈中元素为空，此操作非法");
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
```