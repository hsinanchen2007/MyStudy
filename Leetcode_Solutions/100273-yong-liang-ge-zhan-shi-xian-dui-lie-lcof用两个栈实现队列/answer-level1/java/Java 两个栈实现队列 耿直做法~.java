### 解题思路
第一反应的思路，比较耿直。
新增只新增到栈A，弹出的时候弹出栈B，如果栈B为空了，就把栈A的值弹出push到栈B中再弹出栈B中的值就行了。

### 代码

```java
class CQueue {

    private Stack<Integer> stackA = new Stack<>();
    private Stack<Integer> stackB = new Stack<>();

    public CQueue() {

    }
    
    public  void appendTail(int value) {
        stackA.push(value);
    }
    
    public  int deleteHead() {
        if (stackB.isEmpty()){
            while (!stackA.isEmpty()){
                stackB.push(stackA.pop());
            }
        }
        

        return stackB.isEmpty() ? -1 : stackB.pop();
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```