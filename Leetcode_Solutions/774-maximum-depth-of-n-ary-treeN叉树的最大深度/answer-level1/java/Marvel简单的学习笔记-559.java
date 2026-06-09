N叉树的最大深度和二叉树的最大深度本质上都是一样的。无非就是通过DFS、BFS遍历。
可参考以下二叉树最大深度解法，N叉树最大深度自然不成问题。
[二叉树的最大深度题解](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/solution/marveljian-dan-de-xue-xi-bi-ji-104-by-marvel_ty/)

### 解法一：DFS
一棵树的最大深度就是子树最大深度的最大值加一。

代码：
```java
class Solution {
    public int maxDepth(Node root) {
        if(root == null)    return 0;
        int subMax = 0;
        for(var subNode : root.children)
        {
            int temp = maxDepth(subNode);
            subMax = Math.max(subMax, temp);
        }
        return subMax + 1;
    }
}
```

### 解法二：BFS
层序遍历。一次处理一层，统计层数。

代码：
```java
class Solution {
    public int maxDepth(Node root) {
        if(root == null)    return 0;
        int layer = 0;
        Queue<Node> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty())
        {
            layer++;
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                Node cur = q.poll();
                for(var subNode : cur.children)
                    if(subNode != null) 
                        q.offer(subNode);
            }
        }
        return layer;
    }
}
```