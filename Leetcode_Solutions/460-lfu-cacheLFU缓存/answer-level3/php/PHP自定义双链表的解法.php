参考了甜姨的自定义双链表的解法

```
class LFUCache
{

    public $capacity = 0;
    public $min; // 存储当前最小频次
    public $size = 0;
    public $cache = [];  // 存储缓存的内容
    public $doublyLinkedList = [];  // 存储每个频次对应的双向链表

    /**
     * @param Integer $capacity
     */
    function __construct($capacity)
    {
        $this->capacity = $capacity;
    }

    /**
     * @param Integer $key
     * @return Integer
     */
    function get($key)
    {
        $node = ($this -> cache)[$key];
        if(!isset($node))
            return -1;
        $this -> freqInc($node);
        return $node -> value;
    }

    /**
     * @param Integer $key
     * @param Integer $value
     * @return NULL
     */
    function put($key, $value)
    {
        if($this -> capacity == 0)
            return;
       $node = ($this -> cache)[$key];
       if(isset($node)){
           $node -> value = $value;
           $this -> freqInc($node);
       }else{
           if($this -> size == $this -> capacity){
               $minFreqLinkedList = ($this -> doublyLinkedList)[$this -> min];
               unset($this -> cache[$minFreqLinkedList ->tail->pre->key]);
               $minFreqLinkedList ->remove($minFreqLinkedList->tail->pre);
               $this -> size =  $this -> size - 1;
           }
           $node = new node($key,$value);
           $this -> cache[$key] = $node;
           $linkedList = ($this -> doublyLinkedList)[1];
           if(!isset($linkedList)){
               $linkedList = new doublylinkedlist();
               $this -> doublyLinkedList[1] = $linkedList;
           }
           $linkedList -> add($node);
           $this -> min = 1;
           $this -> size =  $this -> size + 1;
       }

    }

    public function freqInc(node $node){
        // 从原freq对应的链表里移除, 并更新min
        $freq = $node -> freq;
        $linkedList = ($this -> doublyLinkedList)[$freq];
        $linkedList -> remove($node);
        if($freq == $this -> min & $linkedList -> head -> post == $linkedList -> tail){
            $this -> min = $freq + 1;
        }
        $node -> freq = $node -> freq + 1;
        $linkedList = ($this -> doublyLinkedList)[$freq+1];
        if(!isset($linkedList)){
            $linkedList = new doublylinkedlist();
            ($this -> doublyLinkedList)[$freq+1] = $linkedList;
        }
        $linkedList -> add($node);
    }
}

/**
 * Class node
 * @property int $key
 * @property int $value
 * @property int $freq
 * @property node $post
 * @property  node $pre
 */
class node
{
    public $key;
    public $value;
    public $freq = 1;
    public $pre;
    public $post;

    public function __construct(int $key, int $value)
    {
        $this->value = $value;
        $this->key = $key;
    }
}

/**
 * Class doublylinkedlist
 * @property node $head
 * @property node $tail
 */
class doublylinkedlist
{
    public $head;
    public $tail;

    public function __construct()
    {
        $this->head = new node(-1, -1);
        $this->tail = new node(-1, -1);
        $this->head->post = $this->tail;
        $this->tail->pre = $this->head;
    }

    public function remove(node $node)
    {
        $node->pre->post = $node->post;
        $node->post->pre = $node->pre;

    }

    public function add(node $node)
    {
        $node->post = $this->head->post;
        $this->head->post = $node;
        $node->post->pre = $node;
        $node->pre = $this->head;
    }
}
```
