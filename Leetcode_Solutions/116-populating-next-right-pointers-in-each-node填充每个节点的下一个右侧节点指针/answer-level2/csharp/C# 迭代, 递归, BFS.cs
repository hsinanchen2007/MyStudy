```csharp
        // 迭代
        public Node Connect(Node root)
        {
            Node pre = root;
            while (pre!=null)
            {
                Node curr = pre;
                while (curr!=null)
                {
                    if (curr.left !=null)
                    {
                        curr.left.next = curr.right;
                    }

                    if (curr.right!=null && curr.next!=null)
                    {
                        curr.right.next = curr.next.left;
                    }

                    curr = curr.next;
                }
                // 迭代到下一层的第一个节点left
                pre = pre.left;
            }

            return root;
        }

        // 递归
        public Node Connect1(Node root)
        {
            if (root == null)
            {
                return null;
            }

            if (root.left != null)
            {
                root.left.next = root.right;
                if (root.next != null)
                {
                    root.right.next = root.next.left;
                }
            }

            root.left = Connect(root.left);
            root.right = Connect(root.right);

            return root;
        }


        // BFS (解法不符合题意)
        // 你只能使用常量级额外空间。
        // 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
        public Node Connect2(Node root)
        {
            if (root == null)
            {
                return root;
            }

            Queue<Node> queue = new Queue<Node>();
            queue.Enqueue(root);

            while (queue.Count != 0)
            {
                int size = queue.Count;
                // 第一个节点
                Node pre = queue.Peek();

                for (int i = 0; i < size; i++)
                {
                    Node curr = queue.Dequeue();
                    // 连接同层级的右侧节点, 最后一个节点不用连
                    if (i > 0)
                    {
                        pre.next = curr;
                        pre      = pre.next;
                    }

                    if (curr.left != null)
                    {
                        queue.Enqueue(curr.left);
                    }

                    if (curr.right != null)
                    {
                        queue.Enqueue(curr.right);
                    }
                }
            }

            return root;
        }
```
