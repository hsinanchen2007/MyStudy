```
class MinStack {
    /**
     * initialize your data structure here.
     */
    public $data, $min;
    function __construct() {
        $this->data = new SplStack();
        $this->min = new SplStack();
    }

    /**
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        $this->data->push($x);
        if($this->min->isEmpty() || $x <= $this->min->top()){
            $this->min->push($x);
        }
    }

    /**
     * @return NULL
     */
    function pop() {
        if($this->data->isEmpty()) return null;

        if($this->data->pop() == $this->min->top()){
            $this->min->pop();
        }
    }

    /**
     * @return Integer
     */
    function top() {
        return $this->data->isEmpty() ? null : $this->data->top();
    }

    /**
     * @return Integer
     */
    function getMin() {
        return $this->min->isEmpty() ? null : $this->min->top();
    }
}
```
