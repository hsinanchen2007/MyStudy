### 解题思路
思路就是用两个栈，当调用pop、peek时将原来压入栈的元素在弹出压入，这样就实现翻转了。

### 代码

```php
class MyQueue {
    /**
     * Initialize your data structure here.
     */
    public $q;
    public $q2;

    function __construct() {
        $this->q = new SplStack();
        $this->q2 = new SplStack();
    }

    /**
     * Push element x to the back of queue.
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        $this->q->push($x);
    }

    /**
     * Removes the element from in front of queue and returns that element.
     * @return Integer
     */
    function pop() {
        if($this->q2->isEmpty()){
            while(!($this->q->isEmpty())){
               $this->q2->push($this->q->pop());
            }
            return $this->q2->pop();
        }else{
            return $this->q2->pop();
        }
    }

    /**
     * Get the front element.
     * @return Integer
     */
    function peek() {

         if($this->q2->isEmpty()){
            while($this->q->count()!=0){
               $this->q2->push($this->q->pop());
            }
            return $this->q2->top();
        }else{
            return $this->q2->top();
        }
    }

    /**
     * Returns whether the queue is empty.
     * @return Boolean
     */
    function empty() {
        return $this->q2->isEmpty() && $this->q->isEmpty();
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