```
class MinStack {

    static int DEFAULT_CAPACITY = 16;
	int[] element;
	int min = Integer.MAX_VALUE;
	int size;// 栈中元素个数

	public MinStack() {
		this.element = new int[DEFAULT_CAPACITY];
		this.size = 0;
	}

	/**
	 * 将元素 x 推入栈中
	 * 
	 * @param x
	 */
	public void push(int x) {
		if (this.element.length == size + 1) {
			resize();
		} 
		this.element[size] = x;
		size++;
		if (min > x) {
			min = x;
		}
	}

	private void resize() {
		int[] n_element = new int[size<<1];
		System.arraycopy(this.element, 0, n_element, 0, size);
        this.element = n_element;
	}

	/**
	 * pop() -- 删除栈顶的元素
	 */
	public void pop() {
		if (this.element.length != 0) {
			int element = this.top();
			size--;
			if (element == this.min) {
				this.min = Integer.MAX_VALUE;
				for (int i = 0; i < size; i++) {
					if (this.min > this.element[i]) {
						this.min = this.element[i];
					}
				}
			}
		}
	}

	/**
	 * top() -- 获取栈顶元素
	 * 
	 * @return
	 */
	public int top() {
		if (this.element.length != 0) {
			return this.element[size - 1];
		}
		return 0;
	}

	/**
	 * getMin() -- 检索栈中的最小元素
	 * 
	 * @return
	 */
	public int getMin() {
		return this.min;
	}
}
```
