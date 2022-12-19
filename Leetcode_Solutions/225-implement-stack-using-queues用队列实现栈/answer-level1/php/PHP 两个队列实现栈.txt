- 思路：定义**queue1**和**queue2**两个数组用来模拟队列，队列的弹出操作用函数`array_shift()`实现，**count**用来表示栈的元素个数
- 插入操作：如果栈为空，则可将新元素任意插入queue1或queue2，此处选择queue1；如果栈不为空就插入同样不为空的那个queue，即如果queue1不为空就插入queue1，如果queue2不为空就插入queue2。（后面会解释为什么可以保证必有1个队列为空）。
- 弹出操作：如果栈为空，直接返回；如果栈不为空则，将不为空的那个队列使用`array_shift`函数弹出并压入另一个队列，直到最后一个元素，将其输出。这样可以保证，弹出操作完成之后，必定有一个队列为空，以方便下次插入操作。

```
class MyStack {
    public $queue1;
    public $queue2;
    public $count;//用来存栈中元素个数
    /**
     * Initialize your data structure here.
     */
    function __construct() {
        $this -> queue1 = [];
        $this -> queue2 = [];
        $this -> count = 0;
    }
  
    /**
     * Push element x onto stack.
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        if($count == 0 || sizeof($this -> queue1) > 0)
            $this -> queue1[] = $x;
        else
            $this -> queue2[] = $x;
        $this -> count++;
    }
  
    /**
     * Removes the element on top of the stack and returns that element.
     * @return Integer
     */
    function pop() {
        if($this -> count == 0)
            return;
        if(sizeof($this -> queue1) > 0){
            while(sizeof($this -> queue1) > 1)
                $this -> queue2[] = array_shift($this -> queue1);
            $this -> count--;
            return array_shift($this -> queue1);
        }else{
            while(sizeof($this -> queue2) > 1)
                $this -> queue1[] = array_shift($this -> queue2);
            $this -> count--;
            return array_shift($this -> queue2);
        }  
    }
  
    /**
     * Get the top element.
     * @return Integer
     */
    function top() {
        if($this -> count == 0)
            return;
        return sizeof($this -> queue1) > 0 ? $this -> queue1[$this -> count - 1] : $this -> queue2[$this -> count - 1];
    }
  
    /**
     * Returns whether the stack is empty.
     * @return Boolean
     */
    function empty() {
        return $this -> count ? false : true;
    }
}
```
