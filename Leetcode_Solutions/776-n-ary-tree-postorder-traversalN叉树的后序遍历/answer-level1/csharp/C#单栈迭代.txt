执行用时 :
504 ms, 在所有 C# 提交中击败了100.00%的用户
内存消耗 :
39.5 MB, 在所有 C# 提交中击败了11.11%的用户

```c# []
 public IList<int> Postorder(Node root) {
        var stack=new Stack<Node>();
        var list=new List<int>();
        stack.Push(root);
        while(stack.Count>0){
            var node=stack.Pop();
            if(node!=null){
                if(node.children!=null){
                    foreach(var item in node.children){
                        stack.Push(item);
                    }
                }
                list.Insert(0,node.val);    
            }
        }
        return list;
    }
```

