```
    public IList<int> Preorder(Node root)
    {
        List<int> res = new List<int>();

        void PreOrderTraverse(Node root2)
        {
            if (root2 == null) return;
            res.Add(root2.val);
            foreach (var child in root2.children)
            {
                PreOrderTraverse(child);
            }
        }
        PreOrderTraverse(root);
        return res;
    }

```
