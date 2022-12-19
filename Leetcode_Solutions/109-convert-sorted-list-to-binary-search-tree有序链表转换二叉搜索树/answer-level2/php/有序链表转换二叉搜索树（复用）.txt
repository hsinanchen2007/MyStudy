# 复用有序数组转换为二叉搜索树
    上一道题是 将有序数组转换为二叉搜索树
    所以我们可以借用上一道题的解法
    先将二叉树转成有序数组
    然后直接用之前的包装好的函数
    就是速度不快，因为遍历了2次链表
    时间复杂度是 O(2n)

```
function sortedListToBST($head) {
    $nums = [];
    while($head){
        $nums[] = $head->val;
        $head = $head->next;
    }
    $res = $this->buildTree($nums, 0, count($nums) - 1);
    return $res;
}

function buildTree($nums, $left, $right){
    if($left > $right) return null;
    $mid = intval(($left + $right) / 2);
    $root = new TreeNode($nums[$mid]);
    $root->left = $this->buildTree($nums, $left, ($mid - 1));
    $root->right = $this->buildTree($nums, ($mid + 1), $right);
    return $root;
}
```
