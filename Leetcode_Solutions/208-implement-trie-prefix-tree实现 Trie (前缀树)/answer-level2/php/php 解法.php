```
class TrieNode{
    public $isEnd = false;
    public $next = [];
}
class Trie {
    /**
     * Initialize your data structure here.
     */
    function __construct() {
        $this->root = new TrieNode();
    }
  
    /**
     * Inserts a word into the trie.
     * @param String $word
     * @return NULL
     */
    function insert($word) {
        $len = strlen($word);
        $curNode = $this->root;
        for($i=0;$i<$len;$i++){
            $index = ord($word[$i])-ord('a');
            if(!isset($curNode->next[$index])) 
                $curNode->next[$index] = new TrieNode();
            $curNode = $curNode->next[$index];
        }
        if(!$curNode->$isEnd) $curNode->$isEnd = true;
    }
  
    /**
     * Returns if the word is in the trie.
     * @param String $word
     * @return Boolean
     */
    function search($word) {
        $len = strlen($word);
        $curNode = $this->root;
        for($i=0;$i<$len;$i++){
            $index = ord($word[$i])-ord('a');
            if(!isset($curNode->next[$index])) return false;
            $curNode = $curNode->next[$index];
        }
        return $curNode->$isEnd;
    }
  
    /**
     * Returns if there is any word in the trie that starts with the given prefix.
     * @param String $prefix
     * @return Boolean
     */
    function startsWith($prefix) {
        $len = strlen($prefix);
        $curNode = $this->root;
        for($i=0;$i<$len;$i++){
            $index = ord($prefix[$i])-ord('a');
            if(!isset($curNode->next[$index])) return false;
            $curNode = $curNode->next[$index];
        }
        return true;
    }
}
```
