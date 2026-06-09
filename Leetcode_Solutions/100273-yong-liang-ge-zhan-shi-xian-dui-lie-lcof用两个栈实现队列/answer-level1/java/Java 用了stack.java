class CQueue {

    private Stack<Integer> stackT_1;
    private Stack<Integer> stackT_2;

    public CQueue() {
        stackT_1 = new Stack<>();
        stackT_2 = new Stack<>();
    }

    public void appendTail(int value) {
        stackT_1.add(value);
    }

    public int deleteHead() {
        try {
            while (!stackT_1.empty()) {
                stackT_2.add(stackT_1.pop());
            }
            int temp = stackT_2.pop();
            while (!stackT_2.empty()) {
                stackT_1.add(stackT_2.pop());
            }
            return temp;
        }
        catch (Exception e) {
            return -1;
        }
    }
}

我用的方法很莽，用一个栈作为主栈，每次delete的时候将主栈内的元素翻转到副栈，然后再转回主栈。