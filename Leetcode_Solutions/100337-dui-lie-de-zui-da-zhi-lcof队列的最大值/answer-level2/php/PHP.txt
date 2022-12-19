class MaxQueue {
    /**
     */
    public $queue;
    //辅助
    public $dequeue;
    function __construct() {
        $this->queue = [];
        $this->dequeue = [];
    }
    /**
     * @return Integer
     */
    function max_value() {
        if(empty($this->dequeue))
            return -1;
        return $this->dequeue[0];
        // return $this->dequeue[0]?:-1;
    }

    /**
     * @param Integer $value
     * @return NULL
     */
    function push_back($value) {
        array_push($this->queue, $value);
        // var_dump($this->queue, end($this->dequeue));exit;
        // $tmp = [];
        while(!empty($this->dequeue) && $value > end($this->dequeue)){
            array_pop($this->dequeue);
        }
        array_push($this->dequeue, $value);
        // $this->dequeue = array_merge($this->dequeue, $tmp);
        // var_dump($this->queue, $this->dequeue);
    }

    /**
     * @return Integer
     */
    function pop_front() {
        if(empty($this->queue))
            return -1;
        $val = array_shift($this->queue);
        if($val == $this->dequeue[0])
            array_shift($this->dequeue);
        return $val;
    }
}