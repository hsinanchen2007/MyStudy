### 解题思路
PHP里的内置函数即可实现这个操作，主要是理解队列和堆栈的区别，即 队列是先进先出 堆栈是先进后出，PHP的数组元素顺序其实可以看做是队列操作，取出堆栈的栈顶元素，按照先进后出的原则，应该是取出最后插入的元素，所以堆栈的栈顶元素其实是PHP数组的最后一个元素。

### 代码

```php
class MyStack {
    /**
     * Initialize your data structure here.
     */
    public $data;
    function __construct() {
        $this->data = [];
    }

    /**
     * Push element x onto stack.
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        return array_push($this->data,$x);
    }

    /**
     * Removes the element on top of the stack and returns that element.
     * @return Integer
     */
    function pop() {
        return array_pop($this->data);
    }

    /**
     * Get the top element.
     * @return Integer
     */
    function top() {
        return end($this->data);
    }

    /**
     * Returns whether the stack is empty.
     * @return Boolean
     */
    function empty() {
        if(empty($this->data)){
            return 1;
        }else{
            return 0;
        }
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