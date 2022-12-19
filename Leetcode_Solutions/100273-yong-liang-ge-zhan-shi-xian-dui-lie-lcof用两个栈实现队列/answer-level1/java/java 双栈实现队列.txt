
我的思路大概就是，一个栈只负责入队，另一个栈只负责出队
所以在appendTail()函数里面只有stack1.push(),而在出队的时候，因为先进先出，所以在stack2为空的时候，将stack1的数据全部pop()到stack2里面,这样stack2里面存的就是正序的数，这里有一个问题，在stack2中有数据的时候，接收的stack1.pop()的数据是错误的，所以直接从stack2中出队就行了。
```
class CQueue {
    Stack<Integer> stack1 ;
    Stack<Integer> stack2;
    public CQueue() {
        stack1 = new Stack();
        stack2 = new Stack();
    }
    
    public void appendTail(int value) {

        stack1.push(value);
        
    }
    
    public int deleteHead() {
//第一次判断stack2是否为空，还有数的话直接出队
        if(!stack2.empty()) return stack2.pop();
//stack1出，stack2入
        else while(!stack1.empty()) stack2.push(stack1.pop());
        if(!stack2.empty()) return stack2.pop();
        else return -1;
     }
}
```
