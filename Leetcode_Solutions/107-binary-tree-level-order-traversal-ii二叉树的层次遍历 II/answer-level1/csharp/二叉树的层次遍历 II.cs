**思路1：** 利用队列对二叉树进行逐层遍历，即添加一层节点至队列-->获取一层节点值-->添加下一层节点至队列。
```
public IList<IList<int>> LevelOrderBottom(TreeNode root)
        {
            IList<IList<int>> result = new List<IList<int>>();
            //队列用来放每一层不为null的节点
            Queue<TreeNode> queue = new Queue<TreeNode>();
            //用来临时存放每次更新queue前的上一层所有节点
            Queue<TreeNode> tempQueue = new Queue<TreeNode>();

            if (root != null)
            {
                queue.Enqueue(root);
            }
            while (queue.Count > 0)
            {
                var list = new List<int>();
                while (queue.Count > 0)
                {
                    var element = queue.Dequeue();
                    //逐个添加该层节点
                    list.Add(element.val);
                    tempQueue.Enqueue(element);
                }
                result.Add(list);
                while (tempQueue.Count > 0)
                {
                    //放入下一层不为空的节点
                    var element = tempQueue.Dequeue();
                    if (element.left != null)
                    {
                        queue.Enqueue(element.left);
                    }
                    if (element.right != null)
                    {
                        queue.Enqueue(element.right);
                    }
                }
            }

            return result.Reverse().ToList();
        }
```
