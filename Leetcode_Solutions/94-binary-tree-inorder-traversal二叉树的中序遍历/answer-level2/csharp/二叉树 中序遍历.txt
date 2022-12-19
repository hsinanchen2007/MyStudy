```
public class Solution {
    public IList<int> InorderTraversal(TreeNode root) {
        IList<int> result = new List<int>();
        if (root != null)
        {
            var Results = InorderTraversal(root.left);
            foreach (var left in Results)//这里因为是IList 所以没有AddRange
            {
                result.Add(left);
            }
            result.Add(root.val);
            Results = InorderTraversal(root.right);
            foreach (var right in Results) //这里因为是IList 所以没有AddRange
            {
                result.Add(right);
            }
        }
        return result;  
    }

}
```
