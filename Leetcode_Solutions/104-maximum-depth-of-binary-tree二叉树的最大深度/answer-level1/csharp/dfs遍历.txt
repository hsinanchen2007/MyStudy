```
 public int MaxDepth(TreeNode root)
        {
            TreeNode T = root;
            int depth = 0;
            int max = 0;
            Stack<KeyValuePair<TreeNode,int>> stack = new Stack<KeyValuePair<TreeNode, int>>();
            while (T != null || stack.Count != 0)
            {
                while (T != null)
                {
      
                    stack.Push(new KeyValuePair<TreeNode, int>(T, ++depth));
                    T = T.left;
                }
               
                if (stack.Count != 0)
                {
                    T = stack.Peek().Key;
                    depth = stack.Pop().Value;

                    max = Math.Max(depth, max);
                    T = T.right;
                   
                }
               
            }


            return max;
        }
```
