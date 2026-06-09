class MyQueue {

    /** Initialize your data structure here. */
    public MyQueue() {
        
    }
    
  	Stack<Integer> stack=new Stack<>();
	Stack<Integer> subsidiary=new Stack<>();

	/**
	 * 入队
	 *
	 * 如果
	 * 主栈为空 则直接push主存储
	 * 否则
	 * 主栈出栈 保存到副栈 再在副栈push
	 * 交换主辅栈
	 *
	 * @param x
	 */
    public void push(int x) {
		while (!stack.empty()){
			subsidiary.push(stack.pop());
		}
		stack.push(x);
		while (!subsidiary.empty()){
			stack.push(subsidiary.pop());
		}

	}

	/**
	 * 获取top元素并删除
	 *
	 * @return
	 */
	public int pop() {
		return stack.pop();
	}


	/**
	 * 获取top元素
	 *
	 * @return
	 */
	public int peek() {
		return stack.peek();
	}

	/**
	 * 查看栈是否为空
	 * 
	 * @return
	 */
	public boolean empty() {
		return stack.empty();
	}
}
