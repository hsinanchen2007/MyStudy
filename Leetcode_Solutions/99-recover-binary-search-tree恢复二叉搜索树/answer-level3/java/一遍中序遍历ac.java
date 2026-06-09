### 解题思路
事先知道有两个元素的位置需要对调，于是我们只需要在中序遍历中找出位置错误的两个节点，然后进行对调，为此需要有以下准备：
- `change1`为第一个位置错误的节点，`change2`为第二个位置错误的节点;
- `pre`为中序遍历中的上一个节点，方便比较。
1. 首先中序遍历，如果：
   - 有逆序的情况出现即：`pre.val>=root.val`，那么记录`change1`为`root`，若`change2`为空，记录为`pre`，这意味着如果后续再也没有逆序的情况出现的话，那么铁定是这两者交换了;若`change2`不为空，这意味着逆序的情况之前已经出现过了一次，两个位置都找到，可以退出遍历。
（解释说明：此时`change1`记录的是本次逆序中值较小的那个节点，而`change2`是第一次逆序中值较大的节点，所以`change1`的值小的自然要换到位序更靠前的`change2`上。）
2. 退出循环后，交换`change1`和`change2`的位置。
### 代码

```java
class Solution {
    private boolean preInit=false;//pre初始化标志
    private boolean flag=false;//遍历结束标志
    private TreeNode pre=null;//中序排列的上一个节点
    private TreeNode change1,change2=null;//两个交换的节点
    private void inOrder(TreeNode root)
    {
        if(flag||root==null)return;
        
        if(root.left!=null)inOrder(root.left);
        if(!preInit)//pre还未初始化先进行初始化。
        {
            pre=root;
            preInit=true;
        }
        else if(pre.val>=root.val)//比较上一个节点，如果错误则记录。
        {
            change1=root;
            if(change2==null)change2=pre;
            else{//change2也被记录，则两个节点都找到了，遍历结束。
                flag=true;//遍历结束标志
                return;
            }
        }
        pre=root;
        if(root.right!=null)inOrder(root.right);
    }
    public void recoverTree(TreeNode root) {
        inOrder(root);
        if(change1!=null&&change2!=null)
        {
            int temp=change1.val;
            change1.val=change2.val;
            change2.val=temp;
        }
    }
}
```