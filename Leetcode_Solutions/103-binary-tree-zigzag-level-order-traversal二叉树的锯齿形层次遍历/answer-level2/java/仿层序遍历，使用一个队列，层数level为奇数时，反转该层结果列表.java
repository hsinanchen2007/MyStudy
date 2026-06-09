![image.png](https://pic.leetcode-cn.com/5db9c55b9611a8365930ee2797eec58e21468cb08dd885979cd70ccaf1ce3b69-image.png)


```

// 仿层序遍历，使用队列，层数level为奇数时，该层结果列表反转。
public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
    List<List<Integer>> res = new ArrayList<>();
    if (root == null)return res;

    Queue<TreeNode> queue = new LinkedList<>();
    TreeNode node = root;
    queue.add(node);

    // 在此处直接完成root节点这层的遍历
    List<Integer> tmp = new ArrayList<>();
    tmp.add(node.val);
    res.add(tmp);

    int level = 0;
    // 此处基本和层序遍历逻辑一样，区别是加入了反转策略
    while (!queue.isEmpty()) {
        // 相当于根据上一层的结果，提前获得了本层的节点数量size。
        int size = queue.size(); 
        // 每进入依次while循环，代表开始了新的一层，所以需要新创建一个临时列表。
        tmp = new ArrayList<>(); 
        level++;
        for (int i = 0; i < size; i++) {
            node = queue.remove();
            if (node.left != null) {
                queue.add(node.left);
                tmp.add(node.left.val);
            }
            if (node.right != null) {
                queue.add(node.right);
                tmp.add(node.right.val);
            }    
        }
        // 到了最后一层时，会创建一个空tmp，并且不会加入任何元素，所以最后不能把这个tmp加入到res中
        if (tmp.size() != 0) { 
            if ((level & 1) == 1) Collections.reverse(tmp);
            res.add(tmp);
        }
    }
    return res;
}
```
