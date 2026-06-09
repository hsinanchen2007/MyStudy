### 解题思路
左右孩子路径 到达 
从父亲路径到达
以及仅包含自己
统计每个节点的 极大值

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

//  public class TreeNode
// {
//     public int val;
//     public TreeNode left;
//     public TreeNode right;
//     public TreeNode(int x) { val = x; }
// }

class MaxTreeSum{
    class CacheTree{
        public int val;
        public CacheTree left, right, parent;
        public int maxLeft = 0, maxRight = 0, maxParent = 0;
    }
    private void CopyTree(TreeNode rt, CacheTree ct){
        ct.val = rt.val;
        if(rt.left != null){
            ct.left = new CacheTree();
            ct.left.parent = ct;
            CopyTree(rt.left, ct.left);
        }
        if(rt.right != null) {
            ct.right = new CacheTree();
            ct.right.parent = ct;
            CopyTree(rt.right, ct.right);
        }
    }
    private bool IsLeft(CacheTree ct){
        if(ct.parent != null){
            return ct == ct.parent.left;
        }
        return false;
    }
    private bool IsRight(CacheTree ct){
        if(ct.parent != null) return ct == ct.parent.right;
        return false;
    }

    //从子节点移动过来最大 + 自身
    int CalcMaxFromChild(CacheTree ct){
        if(ct.left != null) ct.maxLeft = CalcMaxFromChild(ct.left);
        if(ct.right != null) ct.maxRight = CalcMaxFromChild(ct.right);
        return Math.Max(ct.maxLeft, ct.maxRight) + ct.val;
    }
    int CalcMaxFromParent(CacheTree ct){
        if(ct == null) return 0;
        var pa = ct.parent;
        if(IsLeft(ct)){
            var ri = pa.right;
            var pv = pa.maxParent;
            var rv = 0;
            if(ri != null) rv = Math.Max(ri.maxLeft, ri.maxRight) + ri.val;
            var mv = Math.Max(pv, rv)+pa.val;
            mv = Math.Max(mv, pa.val);
            ct.maxParent = mv;
        }else if (IsRight(ct)){
            var lf = pa.left;
            var pv = pa.maxParent;
            var lv = 0;
            if(lf != null) lv = Math.Max(lf.maxLeft, lf.maxRight) + lf.val;
            var mv = Math.Max(pv, lv)+pa.val;
            mv = Math.Max(mv, pa.val);
            ct.maxParent = mv;
        }
        CalcMaxFromParent(ct.left);
        CalcMaxFromParent(ct.right);
        //Parent到达该点的消耗 = maxP + 此点自身的值 
        return ct.maxParent + ct.val;
    }
    private int MaxAll(CacheTree nd){
        if(nd == null) return Int32.MinValue;//左右无效

        var mv = Math.Max(nd.maxLeft, nd.maxRight);
        mv = Math.Max(mv, nd.maxParent);
        mv += nd.val;//自身的值
        mv = Math.Max(mv, nd.val);

        var lMax = MaxAll(nd.left);
        var rMax = MaxAll(nd.right);

        mv = Math.Max(mv, lMax);
        mv = Math.Max(mv, rMax);
        return mv;
    }
    private void CollectList(CacheTree nd, List<CacheTree> lst){
        if(nd == null) return;
        lst.Add(nd);
        CollectList(nd.left, lst);
        CollectList(nd.right, lst);
    }
    private CacheTree rot;
    public int MaxPathSum(TreeNode root) {
        //Path 总量 n + C(n,2)
        //Path From A --> Max(A) = A > 0 Max(Child)+A else Max(Child)
        //A > 0 Max(Parent) + A else Max(Parent)
        rot = new CacheTree();
        CopyTree(root, rot);
        CalcMaxFromChild(rot);
        CalcMaxFromParent(rot);
        //Max To EachPoint 
        return MaxAll(rot);
    }
    // static void Main(string[] arg)
    // {
    //     var root = Construct();

    //     var mt = new MaxTreeSum();
    //     var n = mt.MaxPathSum(root);
    //     Console.WriteLine(n);
    //     var cl = new List<CacheTree>();
    //     mt.CollectList(mt.rot, cl);
    //     foreach(var l in cl){
    //         Console.WriteLine(l.val + ":" + l.maxLeft + ":" + l.maxRight + ":" + l.maxParent);
    //     }
    // }

    // private static TreeNode Construct(){
    //     var js = File.ReadAllLines("testMT.json");
    //     var td = JsonSerializer.Deserialize<int[]>(js[0]);
    //     var root = new TreeNode(td[0]);
    //     var curNode = root;
    //     var lNode = new List<TreeNode>();
    //     lNode.Add(root);

    //     // var stack = new List<(TreeNode, int)>();
    //     // stack.Add((root, 0));
    //     for (var i = 1; i < td.Length; i++){
    //         var p = (i-1) / 2;
    //         var lf = (i - 1) % 2;
    //         var pn = lNode[p];
    //         var tv = td[i];
    //         // var top = stack[stack.Count - 1];
    //         // if(top.Item2 == 0){
    //         if(lf == 0){
    //             if (tv == -9999)
    //             {
    //                 pn.left = null;
    //                 lNode.Add(null);
    //             }
    //             else
    //             {
    //                 var nn = new TreeNode(tv);
    //                 pn.left = nn;
    //                 lNode.Add(nn);
    //             }
    //             // stack[stack.Count - 1] = top;
    //         }else {
    //             if (tv == -9999)
    //             {
    //                 pn.right = null;
    //                 lNode.Add(null);
    //             }
    //             else
    //             {
    //                 var nn = new TreeNode(tv);
    //                 pn.right = nn;
    //                 lNode.Add(nn);
    //             }
    //             // stack.RemoveAt(stack.Count - 1);
    //         }
    //     }
    //     return root;
    // }
}
public class Solution {
    public int MaxPathSum(TreeNode root) {
        var mt = new MaxTreeSum();
        return mt.MaxPathSum(root);
    }
}
```