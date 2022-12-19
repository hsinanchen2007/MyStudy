数组大小为3 * stackSize
维护一个size数组，记录三个栈的大小
维护一个栈顶指针数组，记录三个栈的栈顶位置

初始化时，另栈顶都指向数组中该栈所占区域的最右端
push时，先入栈，栈顶指针左移一位，size加一个
pop时，由于栈顶指针指向栈顶元素左边一位，所以出站时要取topIndex+1位置的元素
push和pop都要注意先检查size。
peek和isEmpty很简单，就不说了
```
class TripleInOne {
	private int[] stack;
	private int[] size;
	private int[] topIndex;
	int stackSize;

	public TripleInOne(int stackSize) {
		stack = new int[3 * stackSize];
		size = new int[3];
		topIndex = new int[3];
		this.stackSize = stackSize;
		topIndex[0] = 1 * stackSize - 1;
		topIndex[1] = 2 * stackSize - 1;
		topIndex[2] = 3 * stackSize - 1;
	}

	public void push(int stackNum, int value) {
		if (size[stackNum] == stackSize) return;
		/*入栈*/
		stack[topIndex[stackNum]] = value;
		/*更新栈顶序号和size*/
		size[stackNum] += 1;
		topIndex[stackNum] -= 1;
	}

	public int pop(int stackNum) {
		if (size[stackNum] == 0) return -1;
		/*出栈*/
		int pop = stack[topIndex[stackNum] + 1];
		/*更新栈顶和size*/
		topIndex[stackNum] += 1;
		size[stackNum] -= 1;
		/*返回pop*/
		return pop;
	}

	public int peek(int stackNum) {
		if (size[stackNum] == 0) return -1;
		return stack[topIndex[stackNum] + 1];
	}

	public boolean isEmpty(int stackNum) {
		return size[stackNum] == 0;
	}
}
```
