### 解题思路
第一个栈只负责加入元素stackAdd
第二个栈只负责取出元素stackPop
例子：原始队列序列 1 2 3 4 5
加入 1 2 3 4后，stackAdd：1 2 3 4，stackPop：空
取出元素1：将stackAdd元素依次pop，然后push进入stackPop，则stackAdd：空，stackPop: 4 3 2 1
取出元素2、3、4：直接从stackPop中pop元素
加入元素直接加入stackAdd
**总结**
1. 加入元素直接加入stackAdd
2. 取出元素先判断stackPop是否为空，不为空，直接从stackPop取
3. 为空，则吧stackAdd元素依次加入stackPop，在从stackPop取
### 代码

```java
class CQueue {

    private Stack<Integer> stackAdd;
    private Stack<Integer> stackPop;

    public CQueue() {
        stackAdd = new Stack<Integer>();
        stackPop = new Stack<Integer>();
    }
    
    public void appendTail(int value) {
        stackAdd.push(value);
    }
    
    public int deleteHead() {
        if(!stackPop.empty()){
            return stackPop.pop();
        }
        if(stackAdd.empty()){
            return -1;
        }else{
            while(!stackAdd.empty()){
                stackPop.push(stackAdd.pop());
            }
        }
        return stackPop.pop();
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```