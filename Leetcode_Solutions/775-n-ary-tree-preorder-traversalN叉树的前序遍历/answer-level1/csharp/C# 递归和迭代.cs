### 解题思路
此处撰写解题思路

### 代码

```csharp
/*
// Definition for a Node.
public class Node {
    public int val;
    public IList<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val,IList<Node> _children) {
        val = _val;
        children = _children;
    }
}
*/
public class Solution {
    public List<int> res = new List<int>();
    public IList<int> Preorder(Node root) {
        if(root==null) return res;
        res.Add(root.val);
        foreach(var i in root.children){
                Preorder(i);
        }
        return res;
    }
}
// public class Solution {
//     public IList<int> Preorder(Node root) {
//         var t = new Stack<Node>();
//         var res = new List<int>();
//         if(root!=null){
//                 t.Push(root);
//         }else return res;
//         while(t.Count>0){
//                 var node = t.Pop();
//                 if(node.children!=null){
//                         var c = node.children;
//                         for(int i = c.Count-1;i>-1;i--){
//                                 t.Push(c[i]);
//                         }
//                         res.Add(node.val);
//                 }
//         }
//         return res;
//     }
// }
```