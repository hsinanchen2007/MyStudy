### 解题思路
利用bfs的思路解析，用队列存储每一层的数据，访问的时候查询左右节点是否为空，不为空加入队列。 
注意记录层数据的时候，先计算队列的大小，然后循环把这个数据取出，因为后面会插入子树的节点，所以单纯的判断队列是否为空是不正确的。

### 代码

```php
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     public $val = null;
 *     public $left = null;
 *     public $right = null;
 *     function __construct($value) { $this->val = $value; }
 * }
 */
class Solution {

    /**
     * @param TreeNode $root
     * @return Integer[][]
     */
    function levelOrder($root) {
        if(empty($root)){
            return [];
        }
        $q = new SplQueue();
        $q->enqueue($root);
        $totalLevel = [];
        while(!$q->isEmpty()){
            $currentLevel = [];
            $currentLevelSize = $q->count();
            for($i=0; $i<$currentLevelSize; $i++){
                $currentNode = $q->dequeue();
                $currentLevel[] = $currentNode->val;
                if($currentNode->left != null){
                    $q->enqueue($currentNode->left);
                }
                if($currentNode->right != null){
                    $q->enqueue($currentNode->right);
                }
            }
            array_push($totalLevel, $currentLevel);
        }
        return $totalLevel;
    }
}
```