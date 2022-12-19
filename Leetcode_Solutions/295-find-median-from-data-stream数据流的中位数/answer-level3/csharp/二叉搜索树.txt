![Leetcode.png](https://pic.leetcode-cn.com/ebf1cdbbf656adb5e925409075f0d8b46e1c8976f560e16ce1ee294c30be18d7-Leetcode.png)

```
public class MedianFinder
    {
        private Node root;

        public int Count { get; set; }
        /** initialize your data structure here. */
        public MedianFinder()
        {
            root = new Node(null);
        }

        public void AddNum(int num)
        {
            //二叉树查找一个节点
            Node node = Search(num);
            //如果为叶节点则将其设为转为非叶节点
            if (node.IsLeaf == true)
            {
                node.ToNoNull(num);
            }
            //如果不为叶节点说明二叉树中存在该num，所以Size++（当前节点中num的个数）
            else
            {
                node.Size++;
            }
            //从该节点向上递归到根
            while (node != null)
            {
                //更新该节点左右子树的个数以及当前Size
                node.Update();
                node = node.P;
            }
            Count++;
        }

        public double FindMedian()
        {
            //按Count查找中位数在树中的索引
            return Count % 2 == 0 ? (ElementAt(Count / 2 - 1) + ElementAt(Count / 2)) / 2.0 : ElementAt(Count / 2);
        }

        private int ElementAt(int index)
        {
            return ElementAt(root, index);
        }
        //根据索引在树中递归查找相应索引的num值
        private int ElementAt(Node node,int index)
        {
            //判断index位于当前节点，还是左子树或者右子树
            if (index >= node.L && index < node.L + node.Size)
                return node.num;
            else if (node.L > index)
                return ElementAt(node.LL, index);
            else
                return ElementAt(node.RR, index - node.L - node.Size);
        }
        //在树中查找num相应的节点
        private Node Search(int num)
        {
            Node p = root;
            while (p.IsLeaf == false)
            {
                if (num < p.num)
                    p = p.LL;
                else if (num > p.num)
                    p = p.RR;
                else
                    return p;
            }
            return p;
        }

        public class Node
        {
            public int num;     //值
            public int Size;    //num出现的个数
            public int L;       //左子树节点个数
            public int R;       //右子树节点个数
            public bool IsLeaf; //是否为叶子节点（空节点）
            public Node LL;     //左子节点
            public Node RR;     //右子节点
            public Node P;      //父节点
            //创建一个叶子节点（空节点）
            public Node(Node node)
            {
                IsLeaf = true;
                P = node;
            }
            //创建一个节点
            public Node(int num)
            {
                this.num = num;
                Size = 1;
                LL = new Node(this);
                RR = new Node(this);
            }
            //更新节点数据
            public void Update()
            {
                L = LL.L + LL.R + LL.Size;
                R = RR.L + RR.R + RR.Size;
            }
            //将该叶子节点（空节点）转为非空节点
            public void ToNoNull(int num)
            {
                this.num = num;
                Size = 1;
                IsLeaf = false;
                LL = new Node(this);
                RR = new Node(this);
            }
        }
    }

```
