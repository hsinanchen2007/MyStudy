```
public class Solution {
    public IList<int> InorderTraversal(TreeNode root) {
        IList<int> result = new List<int>();
        Stack Steps = new Stack(); //栈
        
        while (root != null || Steps.Count!= 0)
        {
            while (root!= null)
            {
                Steps.Push(root);
                root = root.left;
            }
            root = (TreeNode)Steps.Pop();
            result.Add(root.val);
            root = root.right;
        }
        return result;
    }
}
```
