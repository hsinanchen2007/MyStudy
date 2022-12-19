![image.png](https://pic.leetcode-cn.com/4336ded9568bebcf81aa34f89848e73c930ed27d64a521d4df67ec92073b0bfd-image.png)

```
    List<Integer> list = new ArrayList<Integer>();
    public boolean findTarget(TreeNode root, int k) {
        inOrder(root);
        int head = 0;
        int tail = list.size() - 1;
        while(head < tail) {
            if(list.get(head) + list.get(tail) == k) {
                return true;
            }
            if(list.get(head) + list.get(tail) < k) {
                head++;
            }
            if(list.get(head) + list.get(tail) > k) {
                tail--;
            }
        }
        return false;
    }
    public void inOrder(TreeNode root) {
        if(root == null) {
            return;
        }
        inOrder(root.left);
        list.add(root.val);
        inOrder(root.right);
    }
```
