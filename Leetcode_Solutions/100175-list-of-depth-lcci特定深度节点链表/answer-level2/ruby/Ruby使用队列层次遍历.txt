```
# @param {TreeNode} tree
# @return {ListNode[]}
def list_of_depth(tree)
  return [] if tree == nil
  tree_queue = [tree]
  result = []
  while tree_queue.size > 0 do
    next_tree_queue = []
    list = nil # 从尾到头构建链表
    tree_queue.each do |n|
      l = ListNode.new(n.val)
      l.next = list
      list = l
      next_tree_queue.push(n.right) if n.right != nil # 从尾到头所以从右到左遍历
      next_tree_queue.push(n.left) if n.left != nil
    end
    result.push(list)
    tree_queue = next_tree_queue
  end
  return result
end
```
