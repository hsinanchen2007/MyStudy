```
class BSTIterator {
    private $stack = [];
    /**
     * @param TreeNode $root
     */
    function __construct($root) {
        while($root!=null){
            $this->stack[] = $root;
            $root = $root->left;
        }
    }
  
    /**
     * @return the next smallest number
     * @return Integer
     */
    function next() {
        $root = array_pop($this->stack);
        $val = $root->val;
        $root = $root->right;
        while($root!=null){
            $this->stack[] = $root;
            $root = $root->left;
        }
        return $val;
    }
  
    /**
     * @return whether we have a next smallest number
     * @return Boolean
     */
    function hasNext() {
        return !empty($this->stack);
    }
}
```
