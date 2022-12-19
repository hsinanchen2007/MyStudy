### 解题思路
递归函数nextLevel()遍历下一层，传入的参数应为下一层的所有非空节点List<TreeNode> list
遍历list:一个一个其左右节点成为新的下一个list，同时记录当前层的所有值。

### 代码

```java

class Solution {

    private List<List<Integer>> anslist=new ArrayList<>();

    private void nextLevel(List<TreeNode> list)
    {
        if(list.size()==0)return;
        
        List<Integer> intlist=new ArrayList<>();
        List<TreeNode> newlist=new ArrayList<>();

        for(TreeNode t:list)
        {
            if(t!=null)
            {
                intlist.add(t.val);
                if(t.left!=null)newlist.add(t.left);
                if(t.right!=null)newlist.add(t.right);
            }
        }

        anslist.add(intlist);
        nextLevel(newlist);
    }
    public List<List<Integer>> levelOrder(TreeNode root) {
        if(root==null)return anslist;
        List<TreeNode> list=new ArrayList<>();
        list.add(root);
        nextLevel(list);
        return anslist;
    }
}
```