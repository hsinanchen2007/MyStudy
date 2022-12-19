前
return [root.val] + self.preorderTraversal(root.left) + self.preorderTraversal(root.right) if bool(root) else []

中
return self.midorderTraversal(root.left) + [root.val] + self.midorderTraversal(root.right) if bool(root) else []


后

return self.postorderTraversal(root.left) + self.postorderTraversal(root.right) + [root.val]  if bool(root) else []
