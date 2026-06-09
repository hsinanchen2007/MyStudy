最后一个case，使用中序遍历无法判断出不同。
强行加戏了left null 和 right null的string类型val，与其他正常val一起压栈。
最后两个栈的内容同步比较。

总觉得实现特别挫。。还没看其他解法，只是自己尝试实现：
```
/*
 * @lc app=leetcode.cn id=100 lang=csharp
 *
 * [100] 相同的树
 */
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
    private Stack<string> pVal = new Stack<string>();
    private Stack<string> qVal =  new Stack<string>();

    public bool IsSameTree(TreeNode p, TreeNode q) {
        if(p == null && q == null) return true;
        if(p == null && q != null) return false;
        if(p != null && q == null) return false;

        Traverse(p, pVal, "");
        Traverse(q, qVal, "");

        while (pVal.Count > 0 && qVal.Count > 0)
        {
            var pOut = pVal.Pop();
            var qOut = qVal.Pop();
            if(pOut != qOut)
            {
                return false;
            }
        }

        if(pVal.Count > 0 || qVal.Count > 0) return false;

        return true;
    }

    private void Traverse(TreeNode tr, Stack<string> stack, string part)
    {
        if(tr != null)
        {
            Traverse(tr.left, stack, "left");
            stack.Push(tr.val.ToString());
            Traverse(tr.right, stack, "right");
        }
        else
        {
            stack.Push(part + "null");
        }
    }
}


```
