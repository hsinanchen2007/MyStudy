- 采用修改全局变量的方式，没有采取利用返回值的方式

```
class Solution {
    int result = 0;
    
    public int rangeSumBST(TreeNode root, int L, int R) {
        if(root!=null)
        {
            if(root.val>=L && root.val<=R)
            {
                result += root.val;
                rangeSumBST(root.left,L,R);
                rangeSumBST(root.right,L,R);
            }
            else if(root.val>=R)
            {
                rangeSumBST(root.left,L,R);
            }
            else
            {
                rangeSumBST(root.right,L,R);
            }
            return result;
        }
        else
        {return result;}
        
    }
}
```
