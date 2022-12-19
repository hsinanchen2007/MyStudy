先说结果，执行用时**0ms**,我也不知道为什么。。。
- 定义两个栈**stack1**和 **stack2**, 以及一个**count**用来统计队列元素个数
- 插入操作：直接压入**stack1** 中
- 弹出操作：分成两种情况，
- 1：如果**stack2**中为空，则表明数据均存在**stack1**中，且最先存入元素在**stack1**的栈底，因此**stack1**依此出栈存入**stack2**中，然后弹出**2**栈顶元素即可；
- 2：如果**stack2**不为空，则说明在此之前已经执行过类似1中的**stack1**出栈操作，因此此时直接弹出**stack2**的栈顶元素即可。
```
class MyQueue {
    public $stack1;
    public $stack2;
    public $count;
    /**
     * Initialize your data structure here.
     */
    function __construct() {
        $this -> stack1 = [];
        $this -> stack2 = [];
        $this -> count = 0; //栈中元素个数
    }
  
    /**
     * Push element x to the back of queue.
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        $this -> stack1[] = $x;  
        $this -> count++;
    }
  
    /**
     * Removes the element from in front of queue and returns that element.
     * @return Integer
     */
    function pop() {
        if (sizeof($this -> stack2) == 0) //stack2 为空
            while(sizeof($this -> stack1)>0) //stack1出栈，并压入stack2
                $this -> stack2[] = array_pop($this -> stack1);
        $this -> count--;
        return array_pop($this -> stack2);//弹出stack2的栈顶元素，即数组的最后一个元素
    }
  
    /**
     * Get the front element.
     * @return Integer
     */
    function peek() {
        //跟弹出操作基本一致，只是不弹出元素，而是返回元素
        if (sizeof($this -> stack2) == 0)
            while(sizeof($this -> stack1)>0)
                $this -> stack2[] = array_pop($this -> stack1);
        return $this -> stack2[sizeof($this -> stack2) -1];
    }
  
    /**
     * Returns whether the queue is empty.
     * @return Boolean
     */
    function empty() {
        return $this -> count == 0 ? true : false;
    }
}

```

