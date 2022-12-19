```
class DinnerPlates {
    
    private int capacity;
    private int size = 0;
    private List<Stack<Integer>> list = new ArrayList();
    private PriorityQueue<Integer> queue = new PriorityQueue();

    public DinnerPlates(int capacity) {
        this.capacity = capacity;
    }
    
    public void push(int val) {
        size++;
        int len = list.size();
        
        if (queue.size() > 0) {
            int index = queue.poll();
            if (index < len - 1) {
                list.get(index).push(val);
                return;
            } else {
                queue.clear();
            }
        }
        
        if (len == 0) {
            list.add(new Stack<Integer>());
        }
        
        Stack<Integer> last = list.get(list.size() - 1);
        if (last.size() == capacity) {
            last = new Stack<Integer>();
            list.add(last);
            
        }
        last.push(val);
    }
    
    public int pop() {
        if (size == 0) {
            return -1;
        }
        int len = list.size();
        size--;
        Stack<Integer> stack = list.get(len - 1);
        int res = stack.pop();
        if (stack.isEmpty()) {
            trim();
        }
        
        return res;
    }
    
    private void trim() {
        int len = list.size();
        for(int i = len - 1; i >= 0; i--) {
            if (list.get(i).isEmpty()) {
                list.remove(i);
            } else {
                break;
            }
        }
    }
    
    public int popAtStack(int index) {
        int len = list.size();
        if (index >= len) {
            return -1;
        }
        Stack<Integer> stack = list.get(index);
        if (stack.isEmpty()) {
            return -1;
        }
        
        int res = stack.pop();
        size--;
        if (size == 0) {
            list.clear();
            queue.clear();
        } else {
            if (index < len - 1) {
                queue.offer(index);
            } else {
                if (stack.isEmpty()) {
                    trim();
                }
            }
        }
        return res;
    }
}
```
