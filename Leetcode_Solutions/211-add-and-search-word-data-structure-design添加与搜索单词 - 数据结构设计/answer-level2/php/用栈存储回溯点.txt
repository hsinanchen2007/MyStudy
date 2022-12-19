### 解题思路
此题的关键是对于“.”的回溯处理，通过一个栈存储回溯点。
每次出栈一个回溯点，向下试探，如果成功，则返回true。
直到栈为空，表示所有的尝试都已经完成，且仍未找到字符串，返回false。

### 代码

```php
class WordDictionary {
    private $root = null;
    /**
     * Initialize your data structure here.
     */
    function __construct() {
        $this->root = new Node();
    }
  
    /**
     * Adds a word into the data structure.
     * @param String $word
     * @return NULL
     */
    function addWord($word) {
        $curr = $this->root;
        for($i=0;$i<strlen($word);$i++){
            if(!isset($curr->children[$word[$i]])){
                $curr->children[$word[$i]] = new Node();
            }
            $curr = $curr->children[$word[$i]];
        }
        $curr->setEnd();
    }
  
    /**
     * Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
     * @param String $word
     * @return Boolean
     */
    function search($word) {
        $stack = array();
        $stack[] = array(0, $this->root);

        while(!empty($stack)){
            $item = array_pop($stack);
            $curr = $item[1];
            $index = $item[0];

            if($index == strlen($word)-1){
                if($word[$index] != '.'){
                    if(isset($curr->children[$word[$index]]) && $curr->children[$word[$index]]->isEnd()){
                        return true;
                    }
                }else{
                    foreach($curr->children as $v){
                        if($v->isEnd()){
                            return true;
                        }
                    }
                }
            }else{
                if($word[$index] != '.'){
                    if(isset($curr->children[$word[$index]])){
                        $stack[] = array($index+1, $curr->children[$word[$index]]);
                    }
                }else{
                    foreach($curr->children as $v){
                        $stack[] = array($index+1, $v);
                    }
                }
            }
        }

        return false;
    }
}
class Node{
    private $isEnd = false;
    public $children = array();

    public function setEnd(){
        $this->isEnd = true;
    }
    public function isEnd(){
        return $this->isEnd;
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * $obj = WordDictionary();
 * $obj->addWord($word);
 * $ret_2 = $obj->search($word);
 */
```