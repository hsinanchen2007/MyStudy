```
class FreqStack {
    private Map<Integer,Integer> keyCountMap;
    private Map<Integer,Stack<Integer>> countKeyStackMap;
    private int maxCount;

    public FreqStack() {
        keyCountMap = new HashMap<>();
        countKeyStackMap = new HashMap<>();
        maxCount = 0;
    }

    public void push(int x) {
        Integer count = keyCountMap.get(x);
        if(count == null){
            count = 0;
        }
        ++count;
        keyCountMap.put(x,count);

        Stack<Integer> stack = countKeyStackMap.get(count);
        if(stack == null){
            stack = new Stack<Integer>();
        }
        stack.push(x);
        countKeyStackMap.put(count,stack);

        maxCount = Math.max(maxCount,count);
    }

    public int pop() {
        Stack<Integer> stack = countKeyStackMap.get(maxCount);
        Integer key = stack.pop();

        if(stack.size() == 0){
            --maxCount;
        }

        Integer count = keyCountMap.get(key);
        keyCountMap.put(key,--count);

        return key;
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
```
