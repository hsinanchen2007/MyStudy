### 解题思路
[@mantgh](/u/mantgh/) 参考了大神的代码，加上递归版本
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

    public Node(int _val, IList<Node> _children) {
        val = _val;
        children = _children;
    }
}
*/
public class Solution{
    public IList<int> Postorder(Node root){
        var res = new List<int>();
        var t = new Stack<Node>();
        if(root!=null) {
            t.Push(root);
        }
        else return res;
        while(t.Count>0){
            var node = t.Pop();
            if(node.children!=null){
                    foreach(var i in node.children){
                            t.Push(i);
                    }
                    res.Insert(0,node.val);
            }
        }
        return res;
    }
}




// 递归版本
// public class Solution {
//     public List<int> res = new List<int>();
//     public IList<int> Postorder(Node root) {
//         if(root == null){
//             if(res.Count==0) return res;
//             return null;
//         } 
//         var c = root.children;
//         for(int i = 0;i<c.Count;i++){
//             Postorder(c[i]);
//         }
//         res.Add(root.val);
//         return res;
//     }
// }
```