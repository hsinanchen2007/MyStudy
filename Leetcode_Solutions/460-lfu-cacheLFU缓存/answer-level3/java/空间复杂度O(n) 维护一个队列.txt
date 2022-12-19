维护一个队列
按照访问次数递增，访问次数相同时，最新的在队首，每次淘汰时淘汰队尾元素

```
代码块
public class LFUCache {

    static class Node {

        int key;
        int value;
        int count;
        Node next;

        public Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    Node header = new Node(0, 0);
    int capacity = 0;
    int currCount = 0;

    /**
     * 最近最少使用
     * 维护一个队列，每个元素按照访问计数递增，计数相同的元素，按访问时间排序，最新的在队首，每次淘汰时淘汰队尾元素
     * 空间复杂度：O(1) capacity
     * 时间复杂度：
     *  查找：O(n) 遍历，移位
     *  添加：O(n) 遍历，移位
     * @param capacity
     */
    public LFUCache(int capacity) {
        this.capacity = capacity;
    }

    public int get(int key) {
        // 判断是否存在
        // 存在时，计数加一，移动元素
        Node pre = header;
        Node pointer = header.next;
        while (pointer != null) {
            if (pointer.key == key) {
                pointer.count++;
                // 将当前节点向后移动至相同访问次数队尾
                Node preInternal = pre;
                Node currInternal = pointer;
                while (currInternal != null && currInternal.next != null && currInternal.count > currInternal.next.count) {
                    Node temp = currInternal.next;

                    preInternal.next = currInternal.next;
                    currInternal.next = currInternal.next.next;
                    temp.next = currInternal;

                    preInternal = preInternal.next;
                }
                return pointer.value;
            }
            pre = pointer;
            pointer = pointer.next;
        }
        return -1;
    }

    public void put(int key, int value) {
        // 先判断是否超出容量
        if (get(key) != -1) {
            // key存在，不涉及删除元素
            // 此时key计数已经加一
            // 更新key对应的value
            Node pointer = header.next;
            while (pointer != null) {
                if (pointer.key == key) {
                    pointer.value = value;
                    break;
                }
                pointer = pointer.next;
            }
        } else {
            // 元素之前不存在
            if (currCount + 1 > capacity) {
                // 超出容量
                // 删除首元素相同value的首元素
                Node pointer = header.next;
                Node pre = header;
                // corner case：capacity=0
                if (capacity == 0) {
                    return;
                }
                int targetCount = header.next.count;
                while (pointer != null) {
                    if (pointer.next != null && pointer.next.count == targetCount) {
                        // 下一元素计数值和目标值一样，指针后移
                        pre = pointer;
                        pointer = pointer.next;
                    } else {
                        // 当前元素即为最小计数值最后一个元素
                        // 删除当前元素
                        pre.next = pointer.next;
                        break;
                    }
                }
                // 当前数量不变
            } else {
                // 未超出容量
                // 计数加一
                currCount++;
            }
            // 将当前元素插入队首，计数为1
            Node newNode = new Node(key, value);
            newNode.count = 1;
            newNode.next = header.next;
            header.next = newNode;
        }
    }

}
```
