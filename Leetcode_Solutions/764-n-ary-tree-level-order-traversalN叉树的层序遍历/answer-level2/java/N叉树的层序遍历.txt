### 解题思路
与二叉树的层序遍历一样，利用队列做辅助数据结构。

### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> res=new ArrayList<>();
        if(root==null)
            return res;
        Queue <Node> queue=new LinkedList<>();
        queue.add(root);
        while(!queue.isEmpty())
        {
            int size=queue.size();
            List<Integer> list=new ArrayList<>();
            while(size>0)
            {
                Node node=queue.remove();
                list.add(node.val);
                for(Node child:node.children)
                    queue.add(child);
                size--;
            }
            res.add(list);
        }    
        return res;
    }
}
```