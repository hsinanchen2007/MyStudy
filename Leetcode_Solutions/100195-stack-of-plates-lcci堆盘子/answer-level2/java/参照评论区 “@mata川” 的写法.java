更正了  “@mata川” 的错误

**需要注意的几点:**
    1. 输入的"StackOfPlates"可以为 0 ;
    2. 不存在 size == 0 的栈 ;


```
class StackOfPlates {
    private int cap;
    private List<Deque<Integer>> stackList;

    public StackOfPlates(int cap) {
        this.cap = cap;
        stackList = new ArrayList<>();
    }
    
    public void push(int val) {
        if(stackList.size() == 0 || stackList.get(stackList.size() - 1).size() == cap) {
            addNewStack(val);
        }else {
            Deque<Integer> lastStack = stackList.get(stackList.size() - 1);
            lastStack.push(val);
        }
    }
    
    public int pop() {
        if(stackList.size() == 0){
            return -1;
        }else{
            int res = stackList.get(stackList.size() -1).pop();
            if(stackList.get(stackList.size ()- 1).size() == 0){
                stackList.remove(stackList.size ()- 1);
            }
            return res;
        }
    }
    
    public int popAt(int index) {
        if(index >= stackList.size()){
            return -1;
        }
        int res = stackList.get(index).pop();
        if(stackList.get(index).size() == 0){
            stackList.remove(index);
        }
        return res;
    }

    private void addNewStack(int val) {
        if(cap>0){
            Deque<Integer> stack = new ArrayDeque<>();
            stack.push(val);
            stackList.add(stack);
        }
    } 
}
```
