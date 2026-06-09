### 解题思路
既然提到了层次遍历，那么总体思路还是按照标准的层次遍历。

在此基础上，只要将每层遍历的节点放到子列表（类型为IList<int>)中，并将每层的子列表放到作为结果的列表中（类型为IList<IList<int>>)。然后，再通过一个bool变量来控制每层的顺序即可。

总结，熟练掌握层次遍历是解题关键。

### 代码

```csharp
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public IList<IList<int>> ZigzagLevelOrder(TreeNode root) {
        IList<IList<int>> result = new List<IList<int>>();

        if(root !=null)
        {
            LevelOrder(root,result);
        }
        
        return result;
    }

    private  void LevelOrder(TreeNode node, IList<IList<int>> list)
    {
        if(node ==null) return;

        Queue<TreeNode> q = new Queue<TreeNode>();
        q.Enqueue(node);

        List<int> items =new List<int>();        
        int rowSize= 1; // 每层元素的个数       
        bool isLeftToRight=true; // 用来区别是左到右还是右到左
        while(q.Count>0)
        {            
            var tmpNode = q.Dequeue();
            rowSize--;

            // 向子列表中添加遍历到的节点的值
            items.Add(tmpNode.val);

            if(tmpNode.left!=null) q.Enqueue(tmpNode.left);
            if(tmpNode.right!=null) q.Enqueue(tmpNode.right);

            if(rowSize == 0)  // 条件符合时，开始新的一层
            {
                if(!isLeftToRight)
                {
                    // 如果是从右到左，则反转列表
                    items.Reverse();
                }
                
                // 向结果列表中添加子列表
                list.Add(items);

                // 再次初始化列表为下一层准备，并修改 rowSize 为下一层的长度（即队列的长度）
                items =new List<int>();
                rowSize= q.Count;

                isLeftToRight=!isLeftToRight;  // 改变方向
            }
        }        
    }
}
```