入栈时不用管
出栈时需要判断

如果s2本身为0 ，则是第一次只需要倒位然后取第一个元素

但是如果s2本身存在，则再添加元素需要把元素加到数组前  


/**
     * Push element x onto stack.
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        $this->front = $x;
        $this->que1[] = $x;
    }

    /**
     * Removes the element on top of the stack and returns that element.
     * @return Integer
     */
    function pop() {

        if(sizeof($this->que2) == 0){
            while(sizeof($this->que1) > 0) {
                array_push($this->que2, array_pop($this->que1));
            }
        } else {
            while(sizeof($this->que1) > 0) {
                array_unshift($this->que2, array_shift($this->que1));
            }
        }
        return array_shift($this->que2);
    }

    /**
     * Get the top element.
     * @return Integer
     */
    function top() {
        if(sizeof($this->que1) == 0){
            return $this->front;
        } else {
            return reset($this->que2);
        }
    }

    /**
     * Returns whether the stack is empty.
     * @return Boolean
     */
    function empty() {
        return sizeof($this->que1) == 0 && sizeof($this->que2) == 0;
    }