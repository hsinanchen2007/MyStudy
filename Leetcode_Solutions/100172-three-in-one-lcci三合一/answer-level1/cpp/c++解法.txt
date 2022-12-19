### 解题思路
此处撰写解题思路

### 代码

```cpp
class TripleInOne {
public:
    int *stack;
    int top[3];
    int stackSize;
    TripleInOne(int stackSize):stackSize(stackSize) {
        stack = new int[stackSize*3];
        top[0]=top[1]=top[2]=0;
    }
    
    void push(int stackNum, int value) {
        if(top[stackNum] < stackSize)
            stack[stackSize*stackNum + top[stackNum]++]=value;
    }
    
    int pop(int stackNum) {
        if(top[stackNum] <= 0)
            return -1;
        else
            return stack[stackSize*stackNum + (--top[stackNum])];
    }
    
    int peek(int stackNum) {
        if(top[stackNum] <= 0)
            return -1;
        else
            return stack[stackSize*stackNum + (top[stackNum]-1)];
    }
    
    bool isEmpty(int stackNum) {
        return top[stackNum]==0;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */
```