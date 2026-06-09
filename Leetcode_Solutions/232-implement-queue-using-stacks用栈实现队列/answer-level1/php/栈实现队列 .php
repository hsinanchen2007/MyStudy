采用官方题解第二种方法
入栈时不变，
出栈时
先判断s2是否为空，
如果不为空则直接取栈顶元素
如果为空则把s1的元素倒置过来


function pop() {
       if(sizeof($this->stack2)==0){
           while(sizeof($this->stack1) > 0) {
               array_push($this->stack2, array_pop($this->stack1));
           }
       }
       return array_pop($this->stack2);
    }