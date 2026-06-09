### 解题思路
使用两个栈s1和s2, 两次压栈和两次出栈，效率问题严重。

### 代码

```php
class MyQueue {
    /**
     * Initialize your data structure here.
     */
    function __construct() {
        $this->s1 = [];
        $this->s2 = [];
    }
  
    /**
     * Push element x to the back of queue.
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        while (!empty($this->s1)) {
            array_push($this->s2, array_pop($this->s1));
        }
        array_push($this->s2, $x);
        while (!empty($this->s2)) {
            array_push($this->s1, array_pop($this->s2));
        }
    }
  
    /**
     * Removes the element from in front of queue and returns that element.
     * @return Integer
     */
    function pop() {
        return array_pop($this->s1);
    }
  
    /**
     * Get the front element.
     * @return Integer
     */
    function peek() {
        return end($this->s1);
    }
  
    /**
     * Returns whether the queue is empty.
     * @return Boolean
     */
    function empty() {
        return empty($this->s1);
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * $obj = MyQueue();
 * $obj->push($x);
 * $ret_2 = $obj->pop();
 * $ret_3 = $obj->peek();
 * $ret_4 = $obj->empty();
 */
```

### 参考
https://leetcode-cn.com/problems/implement-queue-using-stacks/solution/yong-zhan-shi-xian-dui-lie-by-leetcode/