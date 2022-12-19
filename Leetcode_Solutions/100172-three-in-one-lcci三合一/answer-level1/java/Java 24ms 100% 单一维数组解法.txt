![图片.png](https://pic.leetcode-cn.com/b3d14fde298c985ec2d34fdc60e3d3140b73955e2e633114807cf00833cbd5d1-%E5%9B%BE%E7%89%87.png)
题目思路：
题目要求使用一个数组，那我们就不使用其他成员变量，在数组中顺便存下每个栈已经使用的空间即可。
```
class TripleInOne {
    private int[] stack;

    public TripleInOne(int stackSize) {
        stack = new int[3 + stackSize * 3];
    }
    
    public void push(int stackNum, int value) {
        if (stack[stackNum] == stack.length / 3 - 1) {
            return;
        }
        stack[arrayIndex(stackNum, stack[stackNum]++)] = value;
    }
    
    public int pop(int stackNum) {
        if (isEmpty(stackNum)) {
            return -1;
        }
        return stack[arrayIndex(stackNum, --stack[stackNum])];
    }
    
    public int peek(int stackNum) {
        if (isEmpty(stackNum)) {
            return -1;
        }
        return stack[arrayIndex(stackNum, stack[stackNum] - 1)];
    }
    
    public boolean isEmpty(int stackNum) {
        return stack[stackNum] == 0;
    }

    private int arrayIndex(int stackNum, int index) {
        int stackSize = stack.length / 3 - 1;
        return 3 + stackNum * stackSize + index;
    }
}
```
