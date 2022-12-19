### 解题思路
之前一直看别人的代码，这是第一次使用队列，简单易懂，没有什么多解释的
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
    public int maxDepth(Node root) {
        if(root==null)
            return 0;
        int cnt = 0;
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        while(!queue.isEmpty())
        {
            int num = queue.size();
            for(int i = 0;i<num;i++)
            {
                Node child = queue.peek(); 
                for(Node n:child.children)
                    queue.add(n);
                queue.poll();
            }
            cnt++;
        }
        return cnt;
    }
}
```