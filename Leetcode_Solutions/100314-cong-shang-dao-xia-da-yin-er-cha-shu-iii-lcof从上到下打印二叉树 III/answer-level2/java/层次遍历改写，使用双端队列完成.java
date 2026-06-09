### 解题思路
第一次发题解，有欠缺的地方，请多多指导
利用层次遍历的方法，使用双端队列完成蛇形遍历；

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
       
      List<List<Integer>> re=new LinkedList<>();
        List<Integer> re_hang=new LinkedList<>();
        if(root==null) return re;
        boolean x=true;
     TreeNode last=root;//记录正在遍历的行的最后一个元素
     TreeNode last_Next=null;//记录下一行遍历的最后一个元素
     Deque<TreeNode> dp=new LinkedList<TreeNode>();
        dp.offerFirst(root);
     while(!dp.isEmpty())
     { 
        if(x)//奇数行
        {
           root=dp.pollFirst();//奇数行从队列头端取元素
            if(root.left!=null) //其孩子节点从队尾入队
            {
                last_Next=last_Next==null?root.left:last_Next;
                dp.offerLast(root.left);
            }
            if(root.right!=null)
            {
                last_Next=last_Next==null?root.right:last_Next;
                dp.offerLast(root.right);
            }
        }
        else//偶数行
        {
          root=dp.pollLast();//偶数行从队列后端取元素
            if(root.right!=null)//其孩子节点从对头入队
            {
                last_Next=last_Next==null?root.right:last_Next;
                dp.offerFirst(root.right);
            }
            if(root.left!=null)
            {
                last_Next=last_Next==null?root.left:last_Next;
                dp.offerFirst(root.left);
            }
        }
         re_hang.add(root.val);//本行遍历结果存入
         if(root==last)//到达了本行的最后一个遍历元素
         {
             x=!x;
             last=last_Next;
             last_Next=null;
             re.add(re_hang);
             re_hang=new LinkedList<>();
         }    
     }
      return re;
        }
}
```