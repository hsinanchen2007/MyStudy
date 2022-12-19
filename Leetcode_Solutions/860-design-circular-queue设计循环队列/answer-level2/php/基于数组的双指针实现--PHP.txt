### 解题思路
用数组来模拟队列，约定数组的左边出队，右边入队。定义两个指针front, rear分别指向队首和队尾。

规则：(没有为什么)
-- 为了方便，多一个空余的位置。所以队列长度为$k + 1
-- front指向队首元素，rear指向队尾元素的下一个位置。如此约定，为了方便队空和队满的检查。
-- 队空 front == rear
-- 队满 (rear + 1 + cap) % cap == front(通过取余来实现循环)

**注意：入队的时候要检查队满，出队要检查队空。取队首和队尾元素都需要检查队空。**

### 代码

```php
class MyCircularQueue {

    private $front = 0;
    private $rear = 0;
    private $cap = 0;
    private $data = [];
    /**
     * Initialize your data structure here. Set the size of the queue to be k.
     * @param Integer $k
     */
    function __construct($k) {
        $this->cap = $k + 1;
    }
  
    /**
     * Insert an element into the circular queue. Return true if the operation is successful.
     * @param Integer $value
     * @return Boolean
     */
    function enQueue($value) {
        if ($this->isFull()) return false;

        // rear指向队尾下一个位置，所以要先赋值。
        // $this->data[] = $value; // 开始误写成了这样，大部分case竟然可以通过
        $this->data[$this->rear] = $value;
        $this->rear = ($this->rear + 1) % $this->cap;

        return true; 
    }
  
    /**
     * Delete an element from the circular queue. Return true if the operation is successful.
     * @return Boolean
     */
    function deQueue() {
        if ($this->isEmpty()) return false;

        $this->front = ($this->front + 1) % $this->cap;

        return true;
    }
  
    /**
     * Get the front item from the queue.
     * @return Integer
     */
    function Front() {
        if ($this->isEmpty()) return -1;

        return $this->data[$this->front];
    }
  
    /**
     * Get the last item from the queue.
     * @return Integer
     */
    function Rear() {
        if ($this->isEmpty()) return -1;

        return $this->data[($this->rear - 1 + $this->cap) % $this->cap];
    }
  
    /**
     * Checks whether the circular queue is empty or not.
     * @return Boolean
     */
    function isEmpty() {
        return $this->front == $this->rear;
    }
  
    /**
     * Checks whether the circular queue is full or not.
     * @return Boolean
     */
    function isFull() {
        return ($this->rear + 1 ) % $this->cap == $this->front;
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * $obj = MyCircularQueue($k);
 * $ret_1 = $obj->enQueue($value);
 * $ret_2 = $obj->deQueue();
 * $ret_3 = $obj->Front();
 * $ret_4 = $obj->Rear();
 * $ret_5 = $obj->isEmpty();
 * $ret_6 = $obj->isFull();
 */
```

### 性能
执行用时 :40 ms, 在所有 PHP 提交中击败了53.57%的用户
内存消耗 :15.8 MB, 在所有 PHP 提交中击败了12.50%的用户

### 时间复杂度
-- 时间复杂度 O(1)
-- 空间复杂度 O(N)

### 参考
这个解释的太清楚了，赞赞赞👍。
[https://leetcode-cn.com/problems/design-circular-queue/solution/shu-zu-shi-xian-de-xun-huan-dui-lie-by-liweiwei141/](https://leetcode-cn.com/problems/design-circular-queue/solution/shu-zu-shi-xian-de-xun-huan-dui-lie-by-liweiwei141/)