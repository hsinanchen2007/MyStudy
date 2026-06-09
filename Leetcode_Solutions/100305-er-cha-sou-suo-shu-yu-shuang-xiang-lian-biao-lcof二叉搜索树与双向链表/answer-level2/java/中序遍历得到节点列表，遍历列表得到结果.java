### 解题思路
看的大多数解题都是中序遍历过程中变换指针，这里提供一个自己的思路。
执行用时1ms，好处是思路直接，欢迎大佬提供优化意见。
1. 中序遍历，并将节点存储。目的是得到有序节点
2. 遍历一次List中的节点，并调整指针。目的是满足前后节点的指针关系

### 代码

```java
class Solution {
    public Node treeToDoublyList(Node root) {
        if(root == null)
            return null;
        // 使用递归按照中序遍历将节点存储到列表中
        List<Node> data = new ArrayList<>();
        midOrder(data, root);
        // 取出头尾节点
        root = data.get(0);
        Node last = data.get(data.size() - 1);
        // 初始化头尾节点
        root.left = last;
        root.right = data.get(data.size() > 1 ? 1 : 0);
        last.right = root;
        last.left = data.get(data.size() > 1 ? data.size() - 2 : 0);
        // 遍历有序节点，并调整指针
        for(int i = 1; i < data.size() - 1; i ++){
            Node node = data.get(i);
            node.left = data.get(i - 1);
            node.right = data.get(i + 1);
        }
        return root;
    }

    public void midOrder(List data, Node root){
        if(root == null)
            return;
        midOrder(data, root.left);
        data.add(root);
        midOrder(data,root.right);
    }

}
```