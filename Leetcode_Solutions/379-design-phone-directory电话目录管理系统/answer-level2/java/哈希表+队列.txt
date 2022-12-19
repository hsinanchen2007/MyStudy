### 解题思路
哈希表来存储已经分配的电话，队列来保存未分配的电话，未分配的电话，都从队头出队。

### 代码

```java
class PhoneDirectory {

    private Set<Integer> existPhone;// 存在的电话
    private Queue<Integer> queue;// 未分配的电话

    /** Initialize your data structure here
     @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    public PhoneDirectory(int maxNumbers) {
        this.existPhone = new HashSet<>(maxNumbers);
        // 初始化未分配的电话
        this.queue = new LinkedList<>();
        int i = 0;
        while(i<maxNumbers){
            queue.offer(i++);
        }
    }

    /** Provide a number which is not assigned to anyone.
     @return - Return an available number. Return -1 if none is available. */
    public int get() {
        if (queue.isEmpty()){
            return -1;
        }
        int phone = queue.poll();
        existPhone.add(phone);
        return phone;
    }

    /** Check if a number is available or not. */
    public boolean check(int number) {
        return !existPhone.contains(number);
    }

    /** Recycle or release a number. */
    public void release(int number) {
        if (existPhone.remove(number)){
            queue.offer(number);
        }
    }
}

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * boolean param_2 = obj.check(number);
 * obj.release(number);
 */
```