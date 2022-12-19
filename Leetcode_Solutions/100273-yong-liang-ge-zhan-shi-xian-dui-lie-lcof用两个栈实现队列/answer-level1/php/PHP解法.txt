### 解题思路
其实就是把A栈的数据倒腾到B栈，倒腾的时候就变成队列了，A栈的老数据就会跑到B栈的栈顶，负负得正一个道理。

### 代码

```php
class CQueue {
    private $stack_push;
    private $stack_pop;
    /**
     */
    function __construct() {
        $this->stack_push = new SplStack();
        $this->stack_pop = new SplStack();
    }

    /**
     * @param Integer $value
     * @return NULL
     */
    function appendTail($value) {
        $this->stack_push->push($value);
    }

    /**
     * @return Integer
     */
    function deleteHead() {
        //只有pop的栈空了，才进行数据重新push，这个很重要
        if($this->stack_pop->isEmpty()){
            $this->shift();
        }
        if($this->stack_pop->isEmpty()) return -1;
        return $this->stack_pop->pop();
    }

    function shift(){
        //从1个栈把数据倒腾到另1个栈
        while(!$this->stack_push->isEmpty()){
            $this->stack_pop->push($this->stack_push->pop());
        }
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * $obj = CQueue();
 * $obj->appendTail($value);
 * $ret_2 = $obj->deleteHead();
 */
```