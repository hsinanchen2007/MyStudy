### 解题思路
php中array_push, array_pop可以模拟栈操作。

### 代码

```php
class MyStack {
    /**
     * Initialize your data structure here.
     */
    function __construct() {
        $this->list_que = [];
    }

    /**
     * Push element x onto stack.
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        array_push($this->list_que, $x);
    }

    /**
     * Removes the element on top of the stack and returns that element.
     * @return Integer
     */
    function pop() {
        return array_pop($this->list_que);
    }

    /**
     * Get the top element.
     * @return Integer
     */
    function top() {
        $key = count($this->list_que);
        return $this->list_que[$key-1];
    }

    /**
     * Returns whether the stack is empty.
     * @return Boolean
     */
    function empty() {
        return empty($this->list_que) ? true : false;
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