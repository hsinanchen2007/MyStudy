
### 解题思路
执行用时 :59 ms, 在所有 Java 提交中击败了16.67%的用户
内存消耗 :47.7 MB, 在所有 Java 提交中击败了100.00%的用户

用两个数组，一个存顺序，一个存最大值。

### 代码

```java
class MaxQueue {
    private List<Integer> myQ;
    private List<Integer> seqQ;
    public MaxQueue() {
        myQ = new ArrayList<>();
        seqQ = new ArrayList<>();
    }
    
    public int max_value() {
        if (myQ.size() == 0){
            return -1;
        }
        return seqQ.get(seqQ.size() - 1);
    }
    
    public void push_back(int value) {
        myQ.add(value);
        seqQ.add(value);
        Collections.sort(seqQ);
    }
    
    public int pop_front() {
        if (myQ.size() == 0){
            return -1;
        }
        Integer ans = myQ.get(0);
        myQ.remove(0);
        seqQ.remove(ans);
        return ans;
    }
}

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue obj = new MaxQueue();
 * int param_1 = obj.max_value();
 * obj.push_back(value);
 * int param_3 = obj.pop_front();
 */
```