```
class Solution {

    /**
     * @param Node $root
     * @return Node
     */
    function connect($root) {
        if($root === null) return null;
        if($root->left !== null){
            $root->left->next = ($root->right!==null)?$root->right:$this->findNextChild($root);
        }
        if($root->right !== null){
            $root->right->next = $this->findNextChild($root);
        }
        $this->connect($root->right); // 这里注意一定要先构建右子树!!!
        $this->connect($root->left);
        return $root;
    }
    
    function findNextChild($root){
        if($root->next ===null) return null;
        while($root->next != null){
            if($root->next->left !== null) return $root->next->left;
            if($root->next->right !== null) return $root->next->right;
            $root = $root->next;
        }
        return null;
    }
}
```
