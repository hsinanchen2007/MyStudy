解法一：
使用三个指针
pre指针指向slow指针上一个元素
fast指针遍历时两倍速于slow指针从而找到mid值
```
class Solution {

    /**
     * @param ListNode $head
     * @return TreeNode
     */
    function sortedListToBST($head) {
        if($head==null) return null;
        $mid = $this->getMidNode($head);
        $node = new TreeNode($mid->val);
        if($mid==$head){
            return $node;
        }
        $node->left = $this->sortedListToBST($head);
        $node->right = $this->sortedListToBST($mid->next);
        return $node;
    }
    
    function getMidNode(&$head){
        $prePtr = null;
        $slowPtr = $head;
        $fastPtr = $head;
        while($fastPtr!=null && $fastPtr->next!=null){
            $prePtr = $slowPtr;
            $slowPtr = $slowPtr->next;
            $fastPtr = $fastPtr->next->next;
        }
        if($prePtr!=null){
            $prePtr->next = null;
        }
        return $slowPtr;
    }
}
```


解法二：
将有序链接转成有序数组，然后参考[108题解法](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/solution/php-jie-fa-by-andfly-14/)
```
class Solution {

    /**
     * @param ListNode $head
     * @return TreeNode
     */
    function sortedListToBST($head) {
        $nums = [];
        while($head!=null){
            $nums[] = $head->val;
            $head = $head->next;
        }
        return $this->helper($nums,0,count($nums)-1);
    }
    
    function helper($nums,$left,$right){
        if($left>$right) return null;
        $mid = $left + floor(($right - $left)/2);
        $node = new TreeNode($nums[$mid]);
        $node->left = $this->helper($nums,$left,$mid-1);
        $node->right = $this->helper($nums,$mid+1,$right);
        return $node;
    }
}
```
