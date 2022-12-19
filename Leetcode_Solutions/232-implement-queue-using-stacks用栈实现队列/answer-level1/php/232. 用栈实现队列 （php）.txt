```
class MyQueue {
    public $left=[];
    public $right=[];
    /**
     * Initialize your data structure here.
     */
    function __construct() {
  
    }
  
    /**
     * Push element x to the back of queue.
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        while($this->right) {
            array_push($this->left, array_pop($this->right));
        }
        array_push($this->left,$x);
    }
  
    /**
     * Removes the element from in front of queue and returns that element.
     * @return Integer
     */
    function pop() {
        while($this->left){
            array_push($this->right, array_pop($this->left));
        }
        if ($this->right) {
            return array_pop($this->right);
        }
        return null;
    }
  
    /**
     * Get the front element.
     * @return Integer
     */
    function peek() {
        while($this->left){
            array_push($this->right, array_pop($this->left));
        }

        if ($this->right) {
            $pop = array_pop($this->right);
            array_push($this->right, $pop);
            return $pop;
        }
        return null;
    }
  
    /**
     * Returns whether the queue is empty.
     * @return Boolean
     */
    function empty() {
        return !$this->left && !$this->right; 
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
$obj = new MyQueue();
$obj->push(1);
$obj->push(2);
$ret_3 = $obj->peek();
$ret_2 = $obj->pop();
$ret_4 = $obj->empty();
```
先吐槽一下： 
 php版本给的示例有很多错误，obj定义的时候少了一个new，并且push少了一个还没有给出具体的值 1  2 ，peek和pop的顺序还颠倒了。

看到了一些php的解法，但是很多是不对的，有的用了返回的是$this->left[0];
如果是用栈的话，看题目是没有这个方法的。
上面的代码中的  array_pop  array_push count 直接用来判断真假   相当于 栈操作的  pop  push size is empty 
还看到有的代码写的过于臃肿。