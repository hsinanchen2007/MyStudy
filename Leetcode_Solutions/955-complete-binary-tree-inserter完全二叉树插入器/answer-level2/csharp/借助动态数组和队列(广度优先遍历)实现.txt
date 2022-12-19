对于完全二叉树来说，其性质决定了底层的物理结构优先考虑顺序存储(数组)，由于其本质也是一颗二叉树,所以
通过当前节点位置索引能够很容易的查找到父节点和孩子节点，从而实现插入操作的O(1)复杂度
父节点   parent = (nodeIndex + 1) / 2;
左子树   leftChild = 2 * nodeIndex + 1;
右子树   rightChild = 2 * nodeIndex + 2;

由于要插入的新节点永远在树结构的  最后一层  ，所以只需判断插入位置索引的奇偶性，再通过父节点直接赋值给左或者右子树即可
```
        public class CBTInserter
        {
            private List<TreeNode> data = new List<TreeNode>();//存储元素的动态数组
            private TreeNode root;
            public CBTInserter(TreeNode root)
            {
                this.root = root;

                LevelOrder(root);//通过广度优先遍历将每个节点加入动态数组中
            }

            private void LevelOrder(TreeNode node)
            {
                Queue<TreeNode> queue = new Queue<TreeNode>();
                queue.Enqueue(node);
                while (queue.Count != 0)
                {
                    TreeNode cur = queue.Dequeue();
                    data.Add(cur);//加入节点

                    if (cur.left != null)
                        queue.Enqueue(cur.left);
                    if (cur.right != null)
                        queue.Enqueue(cur.right);
                }
            }

            private int Parent(int node) => (node - 1) / 2;//判断父节点索引

            public int Insert(int v)
            {
                TreeNode node = new TreeNode(v);

                int parent = Parent(data.Count);//找到需要插入位置的父节点

                if (data.Count % 2 == 0)             //如果需要插入位置的索引为偶数
                    data[parent].right = node;      //则将新节点赋值给右孩子
                else                                            
                    data[parent].left = node;        //否则赋值给左孩子

                data.Add(node);                        //将新节点加入数组中
                return data[parent].val;
            }

            public TreeNode Get_root()
            {
                return root;
            }

        }
```
**预处理时间复杂度O(N)， 插入时间复杂度o(1)， 返回根节点时间复杂度O(1)**
