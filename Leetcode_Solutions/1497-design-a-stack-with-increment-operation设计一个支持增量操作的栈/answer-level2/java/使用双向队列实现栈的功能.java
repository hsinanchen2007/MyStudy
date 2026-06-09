### 解题思路
使用双向队列实现栈的功能

### 代码

```java
class CustomStack {

        private Integer maxSize;
        private LinkedList<Integer> list;
        public CustomStack(int maxSize) {
            this.maxSize = maxSize;
            this.list = new LinkedList<>();
        }

        public void push(int x) {
            if(list.size() < maxSize){
                this.list.offer(x);
            }
        }

        public int pop() {
            if(list.isEmpty()) return -1;
            return list.pollLast();
        }

        public void increment(int k, int val) {
            if(k > list.size()) k = list.size();
            for (int i =0; i < k; i++){
                list.set(i, list.get(i) +val);
            }
        }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */
```