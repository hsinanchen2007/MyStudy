定义一个二维数组保存数据，然后最后一个位置放当前栈长度
```
class TripleInOne {

    /**
     * 最后一位保留当前栈的长度
     */
    private int[][] stacks;
    public TripleInOne(int stackSize) {
        stacks = new int[3][stackSize+1];
    }

    public void push(int stackNum, int value) {
        if(stacks[stackNum][stacks[0].length-1] < stacks[0].length-1){
            stacks[stackNum][(stacks[stackNum][stacks[0].length-1])] = value;
            stacks[stackNum][stacks[0].length-1]+=1;
        }
    }

    public int pop(int stackNum) {
        if(stacks[stackNum][stacks[0].length-1] == 0){
            return -1;
        }else {
            int temp =  stacks[stackNum][(stacks[stackNum][stacks[0].length-1]-1)];
            stacks[stackNum][stacks[0].length-1]-=1;
            return temp;
        }
    }

    public int peek(int stackNum) {
        if(stacks[stackNum][stacks[0].length-1] == 0){
            return -1;
        }else {
            return stacks[stackNum][(stacks[stackNum][stacks[0].length-1]-1)];
        }
    }

    public boolean isEmpty(int stackNum) {
        return stacks[stackNum][stacks[0].length-1]==0;
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
