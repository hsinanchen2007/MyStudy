### 解题思路
通过数组模拟队列，每次入队后，把之前队列中的元素挨个出队再入队。

### 代码

```php
class MyStack {
    /**
     * Initialize your data structure here.
     */
    function __construct() {
        $this->list = [];
    }
  
    /**
     * Push element x onto stack.
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        array_push($this->list, $x);
        $len = count($this->list);
        while ($len > 1) {
            $top = $this->pop();
            array_push($this->list, $top);
            $len--;
        }
    }
  
    /**
     * Removes the element on top of the stack and returns that element.
     * @return Integer
     */
    function pop() {
        return array_shift($this->list);
    }
  
    /**
     * Get the top element.
     * @return Integer
     */
    function top() {
        return current($this->list);
    }
  
    /**
     * Returns whether the stack is empty.
     * @return Boolean
     */
    function empty() {
        return empty($this->list);
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * $obj = MyStack();
 * $obj->push($x);
 * $ret_2 = $obj->pop();
 * $ret_3 = $obj->top();
 * $ret_4 = $obj->empty();
 */
```

### 参考
https://leetcode-cn.com/problems/implement-stack-using-queues/solution/yong-dui-lie-shi-xian-zhan-by-leetcode/