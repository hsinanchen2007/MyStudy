### 解题思路
有个小坑 不设置first标志位，当树为[-int.MinValue]会因为nodeVal和pre的初值返回false，这时不应进行大小比较，单个数直接返回true。

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
    public bool IsValidBST(TreeNode root) {
        Stack stack=new Stack();
            int nodeVal=int.MinValue;
            int pre=int.MinValue;
            bool first=true;
        TreeNode temp=root;
        while(temp!=null||stack.Count!=0){ 
           while(temp!=null){
             stack.Push(temp);
             temp=temp.left;
           }
           temp=(TreeNode)stack.Pop();
           nodeVal=  temp.val;
                if(!first) {
           if(nodeVal<=pre)  return false;}
           pre=nodeVal;
                first=false;
           temp=temp.right;
        }
        return true;
    }
}
```