参考了若干大神的答案，使用一个标志来减少遍历次数；
创新点在于使用了随机数来确定先遍历左树还是右树，这样运行效率可能比较稳定。
```
# @param {TreeNode} root
# @return {Boolean}
def is_balanced(root)
  @balanced = true
  depth = get_depth(root)
  return @balanced
end

def get_depth(r)
  return 0 if not @balanced
  return 0 if r == nil
  if rand() >= 0.5 then
    left_depth = get_depth(r.left)
    right_depth = get_depth(r.right)
  else
    right_depth = get_depth(r.right)
    left_depth = get_depth(r.left)
  end
  @balanced &= (left_depth - right_depth).abs <= 1 # 一个节点不平衡则整颗树不平衡
  return [left_depth, right_depth].max + 1
end
```
