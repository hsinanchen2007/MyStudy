### 解题思路
1.声明一个数组为栈空间
2.声明一个长度为3的数组用来记录对应栈压入弹出记录
3.通过实现stackInx增减来实现push  pop   peek

### 代码

```java
class TripleInOne {

    private int[] stack;
    private int[] stackInx = new int[3];
    private int stackSize;

    public TripleInOne(int stackSize) {
        this.stackSize = stackSize;
        stack = new int[stackSize * 3];
        stackInx[0] = 0; //标记三个栈起始位置
        stackInx[1] = stackSize;
        stackInx[2] = stackSize * 2;
    }
    
    public void push(int stackNum, int value) {
        if(stackInx[stackNum] < (stackNum + 1) * stackSize) { //当前栈未压满
            stack[stackInx[stackNum]++] = value;
        }
    }
    
    public int pop(int stackNum) {
        if(isEmpty(stackNum)) return -1;
        return stack[--stackInx[stackNum]]; //减少栈标记，弹出栈顶值
    }
    
    public int peek(int stackNum) {
        if(isEmpty(stackNum)) return -1;
        return stack[stackInx[stackNum] - 1]; //浮出栈顶值
    }
    
    public boolean isEmpty(int stackNum) {
        return stackInx[stackNum] == stackNum * stackSize;
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