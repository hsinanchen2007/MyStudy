### 解题思路
1、二叉搜索树，左子树都小于根节点，右子树都大于根节点，我们主要通过这个性质来验证。
2、因为是后序遍历，所以最后一个值肯定是根节点。

结合这2点，如下代码。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $postorder
     * @return Boolean
     */
    function verifyPostorder($postorder) {
        return $this->helper($postorder,0,count($postorder)-1);
    }

    function helper($postorder,$start,$end){
        if($start >= $end) return true;

        //左子树（都小于根节点）
        for($i=$start;$i<$end;$i++){
            if($postorder[$i]>$postorder[$end]) break;
        }

        //右子树（都大于根节点）如果出现小于根节点的，肯定错误
        for($j=$i;$j<$end;$j++){
            if($postorder[$j]<$postorder[$end]) return false;
        }

        //左右子树验证
        return $this->helper($postorder,$start,$i-1) && $this->helper($postorder,$i,$end-1);
    }
}
```