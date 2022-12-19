```
public class Solution {
    public int MaxDepth(TreeNode root) {
        //bfs
        if(root == null)
        {
            return 0;
        }

        int depth = 0;
        var queue = new Queue<TreeNode>();
        queue.Enqueue(root);

        while(queue.Count > 0)
        {
            depth++;
            int size = queue.Count;
            for(int i = 0; i < size; i++)
            {
                var node = queue.Dequeue();
                if(node.left != null)
                {
                    queue.Enqueue(node.left);
                }
                if(node.right != null)
                {
                    queue.Enqueue(node.right);
                }
            }
        }

        return depth;
    }
}
```
```
public int MaxDepth(TreeNode root) {
        //dfs
        //using two stacks.

        if(root == null)
        {
            return 0;
        }

        var rootStack = new Stack<TreeNode>();
        var depthStack = new Stack<int>();

        int depth = 1;

        rootStack.Push(root);
        depthStack.Push(depth);
        while(rootStack.Count > 0)
        {
            var node = rootStack.Pop();
            var temp = depthStack.Pop();
            depth = Math.Max(temp, depth);

            if(node.left != null)
            {
                rootStack.Push(node.left);
                depthStack.Push(temp + 1);
            }
            if(node.right != null)
            {
                rootStack.Push(node.right);
                depthStack.Push(temp + 1);
            }
        }

        return depth;
    }
```
