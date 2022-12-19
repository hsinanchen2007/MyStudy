### 解题思路
用两个array 
int[] values 分成三等分，储存三个栈的值
int[] sizes 储存每个栈的大小

### 代码

```java
class TripleInOne {

// stack 1: [0, n/3)
// stack 2: [n/3, 2n/3)
// stack 3: [2n/3, n)

    private int numberOfStacks= 3;
    private int stackCapacity;
    private int[] values; // storing elements of stack
    private int[] sizes; // size = 3;

    public TripleInOne(int stackSize) {
        stackCapacity = stackSize;
        values = new int[stackSize * numberOfStacks];
        sizes = new int[numberOfStacks];
    }
    
    public void push(int stackNum, int value) {
        if (isFull(stackNum))
            return;
        sizes[stackNum]++;
        values[indexOfTop(stackNum)] = value;
        return;
    }
    
    public int pop(int stackNum) {
        if (isEmpty(stackNum))
            return -1;
        int topIndex = indexOfTop(stackNum);
        int value = values[topIndex]; // Get top
        values[topIndex] = 0;
        sizes[stackNum]--;
        return value;
    }
    
    public int peek(int stackNum) {
        if (isEmpty(stackNum))
            return -1;
        return values[indexOfTop(stackNum)];
    }
    
    public boolean isEmpty(int stackNum) {
        return sizes[stackNum] == 0;
    }

    private boolean isFull(int stackNum) {
        return sizes[stackNum] == stackCapacity;
    }

    private int indexOfTop(int stackNum) {
        int offSet = stackNum * stackCapacity;
        int size = sizes[stackNum];
        return offSet + size - 1;
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