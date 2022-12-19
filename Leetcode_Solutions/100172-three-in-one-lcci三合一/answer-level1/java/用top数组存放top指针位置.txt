模仿栈的实现
```
class TripleInOne {

    int stack[];
    int stackSize;

    //还需三个栈顶指针
    int top[];

    public TripleInOne(int stackSize) {

        this.stackSize = stackSize;
        this.stack = new int[stackSize*3];
        this.top = new int[3];
        for(int i=0;i<3;i++)
            this.top[i]=i*stackSize;
    }
    
    public void push(int stackNum, int value) {
       
        if(top[stackNum]>stackNum*stackSize+stackSize-1)
            return;
        stack[top[stackNum]] = value;
        top[stackNum]++;
        
    }
    
    public int pop(int stackNum) {
        
        if(isEmpty(stackNum))
            return -1;//栈为空
        return stack[--top[stackNum]];
    }
    
    public int peek(int stackNum) {
        
        if(isEmpty(stackNum))
            return -1;//栈为空
        else return stack[top[stackNum]-1];
    }
    
    public boolean isEmpty(int stackNum) {
        
        if(top[stackNum]==stackNum*stackSize)
            return true;//栈为空
        return false;
        
    }
}

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne obj = new TripleInOne(stackSize);
 * obj.push(stackNum,value);
 * int param_2 = obj.pop(stackNum);
 * int param_3 = obj.peek(stackNum);
 * boolean param_4 = obj.isEmpty(stackNum);
 */
```
