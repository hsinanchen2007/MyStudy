### 解题思路
用一个list存储Stack,push操作只管往最后一个Stack加,当然要判断list是否为空和最后一个Stack是否满了,注意栈最大值为0的情况,pop和popAt操作只要从最后一个Stack里面取就行了,取完判断一下该Stack是否为空,为空直接移除

### 代码

```java
class StackOfPlates {
    ArrayList<Stack<Integer>> stacks = new ArrayList<Stack<Integer>>();
    int max;
    public StackOfPlates(int cap) {
        max = cap;
    }
    
    public void push(int val) {
        if(max!=0){
            if(stacks.size()==0||stacks.get(stacks.size()-1).size()==max){
                Stack stack = new Stack();
                stack.push(val);
                stacks.add(stack);
            } else {
                stacks.get(stacks.size()-1).push(val);
            }
        }
    }
    
    public int pop() {
        if(stacks.size()==0) return -1;
        int n = stacks.get(stacks.size()-1).pop();
        if(stacks.get(stacks.size()-1).size()==0)stacks.remove(stacks.size()-1);
        return n;
    }
    
    public int popAt(int index) {
        if(stacks.size()==0||index>=stacks.size())return -1;
        int n=stacks.get(index).pop();
        if(stacks.get(index).size()==0)stacks.remove(index);
        return n;
    }
}

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates obj = new StackOfPlates(cap);
 * obj.push(val);
 * int param_2 = obj.pop();
 * int param_3 = obj.popAt(index);
 */
```