### 解题思路
首先要实现队列的数据形式，然后添加栈的操作。

### 代码

```php
class MyStack {

    public $quote;
    public $data;
    /**
     * Initialize your data structure here.
     */
    function __construct() {
        $this->quote = array('topKey' => false,'endKey'=> false);
        $this->data = array();

    }

    /**
     * Push element x onto stack.
     * @param Integer $x
     * @return NULL12
     */
    function push($x) {
        if($this->quote['endKey'] === false){
            $this->quote['topKey'] = 0;
            $this->quote['endKey'] = 1;
            $this->data[0] = array('value' => $x, 'next' => 1 ,'before'=> false);
        }else{
            $endKey = $this->quote['endKey'];
            $nextKey = $endKey +1 ;
            $this->data[$endKey] = array('value' => $x, 'next' => $nextKey ,'before'=> $endKey -1);
            $this->quote['endKey'] = $nextKey;
        }

    }

    /**
     * Removes the element on top of the stack and returns that element.
     * @return Integer
     */
    function pop() {
    
        $endKey = $this->quote['endKey'] - 1 ;
         if(isset($this->data[$endKey])){
             $backData =  $this->data[$endKey]['value'];
             if($this->data[$endKey]['before'] === false){
                $this->quote = array('topKey' => false,'endKey'=> false);
               $this->data = array();
             }else{
                 $beforeData = $this->data[$this->data[$endKey]['before']];
                 $this->quote['endKey'] = $beforeData['next'];
                 unset($this->data[$endKey]);

             }
         }
         return $backData;
    }

    /**
     * Get the top element.
     * @return Integer
     */
    function top() {

         $endKey = $this->quote['endKey'] - 1 ;
         if(isset($this->data[$endKey])){
             return $this->data[$endKey]['value'];
         }

    }

    /**
     * Returns whether the stack is empty.
     * @return Boolean
     */
    function empty() {
        if($this->quote['topKey'] === false){
            return true;
        }else{
            return false;
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