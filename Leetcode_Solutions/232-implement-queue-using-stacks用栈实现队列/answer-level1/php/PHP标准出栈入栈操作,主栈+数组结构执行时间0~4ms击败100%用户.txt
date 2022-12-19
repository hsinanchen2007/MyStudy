栈的标准操作只有出栈和入栈,时间复杂度O(1),实现队列操作只需全部出栈后再入栈即可
```
class MyQueue {
    private $arr = null;
    private $count = 0;
    /**
     * Initialize your data structure here.
     */
    function __construct() {
        $this->arr = [];
    }

    /**
     * Push element x to the back of queue.
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        $this->arr[] = $x;
        $this->count++;
    }

    /**
     * Removes the element from in front of queue and returns that element.
     * @return Integer
     */
    function pop() {
        # 记录当前栈元素个数
        $count = $this->count;
        # 将栈元素个数清零
        $this->count = 0;
        # 辅助数组
        $tmp = [];
        for ($i=0;$i<$count;$i++) {
            # 全部出栈操作
            $tmp[] = array_pop($this->arr);
        }
        # 排除最后一个元素,遍历数组入栈
        for ($i=$count-2;$i>=0;$i--) {
            $this->push($tmp[$i]);
        }
        # 返回最后一个元素
        return $tmp[$count-1];
    }

    /**
     * Get the front element.
     * @return Integer
     */
    function peek() {
        return $this->arr[0];
    }

    /**
     * Returns whether the queue is empty.
     * @return Boolean
     */
    function empty() {
        return $this->count == 0 ? true : false;
    }
}
```
