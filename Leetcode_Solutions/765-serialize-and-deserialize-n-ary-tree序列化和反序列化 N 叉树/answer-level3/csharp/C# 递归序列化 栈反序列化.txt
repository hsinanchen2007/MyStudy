```csharp
    public String serialize(Node root)
    {
        StringBuilder sb = new StringBuilder();
        if (root == null)
            return sb.ToString();

        Encode(root, sb);
        return sb.ToString();
    }

    private void Encode(Node node, StringBuilder sb)
    {
        if (node == null)
            return;

        sb.Append(node.val);
        sb.Append(" ");

        if (node.children == null)
            node.children = new List<Node>();

        bool hasChildren = node.children.Count > 0;

        if (hasChildren)
        {
            sb.Append("[ ");
        }

        for (int i = 0; i < node.children.Count; i++)
        {
            Node children = node.children[i];
            Encode(children, sb);
            if (i == node.children.Count - 1)
            {
                sb.Remove(sb.Length - 1,1);
            }
        }

        if (hasChildren)
        {
            sb.Append(" ] ");
        }
    }

    // Decodes your encoded data to tree.
    public Node deserialize(String data)
    {
        if (String.IsNullOrEmpty(data))
        {
            return null;
        }
    
        String[]    strings = data.Split(" ",StringSplitOptions.RemoveEmptyEntries);
        Stack<Node> stack   = new Stack<Node>();
        Node        root    = null;
        Node        cur     = null;
    
        foreach (String s in strings) 
        {
            if (s.Equals("["))
            {
                stack.Push(cur);
            }
            else if (s.Equals("]"))
            {
                stack.Pop();
            }
            else
            {
                Node node = new Node(int.Parse(s), new List<Node>());
                
                if (root == null)
                {
                    root = node;
                }
                else
                {
                    Node parent = stack.Peek();
                    parent.children.Add(node);
                }
    
                cur = node;
            }
        }
    
        return root;
    }
```
