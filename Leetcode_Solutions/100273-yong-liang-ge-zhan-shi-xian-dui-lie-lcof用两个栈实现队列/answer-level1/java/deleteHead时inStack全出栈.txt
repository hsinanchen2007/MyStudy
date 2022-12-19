写一个辅助函数move 
删头时如果out为空则清空in

```
class CQueue {

    public Stack<Integer> in = new Stack();
    public Stack<Integer> out = new Stack();

    public CQueue() {
        
    }
    
    public void appendTail(int value) {
        in.push(value);
    }
    
    public int deleteHead() {
        if(out.isEmpty()) move();
        if(out.isEmpty()) return -1;
        return out.pop();
    }

    public boolean move(){
        if(!out.isEmpty()) return false;
        while(!in.isEmpty())
            out.push(in.pop());
        return true;
    }

}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```
