### 解题思路
Deque作为栈的处理，就是标准的栈操作。核心在于TreeMap的使用，将时间降低到O(logN)。

我们把所有元素都存储在红黑树中，构成一个有序的集合，同时记录下元素出现的个数，元素个数为0的时候，移除出红黑树。

获取栈的最大元素时，只需要找到红黑树最大的元素X，然后将其个数-1，同样如果个数为0，则在红黑树中删除X。然后再在栈中移除X元素即可。

个人觉得还有一个好一点的方案，建立一个全局的index下标，TreeMap的value改为一个List，里面记录所有进入元素的下标，每次出栈的时候，把TreeMap中对应元素的List最后一个下标获取，再移除。

同时把栈转为一个ArrayList，然后直接通过下标去删除元素。

### 代码

```java
class MaxStack {

    private Deque<Integer> m_stack;
    // key:元素 value：元素个数
    private TreeMap<Integer,Integer> m_treeMap;

    /**
     * initialize your data structure here.
     */
    public MaxStack() {
        // 初始化
        m_stack = new LinkedList<>();
        m_treeMap = new TreeMap<>();
    }

    public void push(int x) {
        m_stack.push(x);
        m_treeMap.put(x,m_treeMap.getOrDefault(x,0) + 1);
    }

    public int pop() {
        int x = m_stack.pop();
        int count = m_treeMap.get(x);
        if (count == 1){
            m_treeMap.remove(x);// 只有一个了移除掉
        }else {
            m_treeMap.put(x,count-1);// 数量-1
        }
        return x;
    }

    public int top() {
        return m_stack.peek();
    }

    public int peekMax() {
        return m_treeMap.lastKey();
    }

    public int popMax() {
        Map.Entry<Integer,Integer> entry = m_treeMap.lastEntry();
        int x = entry.getKey();
        // 红黑树的数量维护
        if (entry.getValue() == 1){
            m_treeMap.remove(entry.getKey());
        }else {
            m_treeMap.put(entry.getKey(),entry.getValue() - 1);
        }
        m_stack.remove(x);
        return x;
    }
}

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
```