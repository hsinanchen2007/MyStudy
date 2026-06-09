本来只是试试的，结果竟然通过了，运行时间超过100%，太不可思议了，哈哈哈
题解思路：
    1、按树的层次遍历将每一层的node存入List<List<Node>> list.get(level)中
    2、取每一层的List<Node>,将node节点的next指向下一个node，做后一个node.next = null
代码如下：
```
class Solution {
    List<List<Node>> list = new ArrayList<>();  
    public Node connect(Node root) {
        if (root == null) return null;
        helper(root, 0);
        //Iterator iterator = list.Iterator();
        for (List<Node> tmp : list) {
            for(int i=0; i<tmp.size()-1; i++) {
                Node node = tmp.get(i);
                node.next = tmp.get(i+1);
            }
            Node tail = tmp.get(tmp.size()-1);
            tail.next = null;
        }
        return root;
    }

    public void helper(Node node, int level) {
        if (list.size() == level) {
            list.add(new ArrayList<>());
        }
        list.get(level).add(node);
        if (node.left != null)
            helper(node.left, level + 1);
        if (node.right != null)
            helper(node.right, level + 1);
    }

}
```

