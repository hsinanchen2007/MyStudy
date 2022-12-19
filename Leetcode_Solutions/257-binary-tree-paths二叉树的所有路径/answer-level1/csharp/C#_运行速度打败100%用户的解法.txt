用c#来写，主要思想是递归+引用传递。
引用传递把一个List<List<int>> 变量作为参数传进去（用队列可能会更快捷方便一点，不想再改了）
递归返回条件是该节点为一个叶子节点。
递归时，把需要递归的节点、该节点的父路径、引用传递变量三者传进去。
*注意：节点的父路径我使用了List<int>变量，这是一个引用变量，于是导致我的递归在返回上一层时，上一层的父路径受到了下一层对其修改产生的影响。
找了很久才发现这个bug，所以递归函数FindNextNode()里需要使用ToList()函数，复制一份副本。避免多次递归更改引用变量。

#region 题257：二叉树的所有路径

        //打印树的所有路径（从根节点到叶节点）
        //输入一个树的根节点
        public class TreeNode
        {
            public int val;
            public TreeNode left;
            public TreeNode right;
            public TreeNode(int x) { val = x; }
        }
        static public IList<string> BinaryTreePaths(TreeNode root)
        {
            IList<string> result = new List<string>();
            if (root == null)
            {
                return null;
            }
            List<List<int>> resultList = PrintAllPath(root);
            foreach (List<int> l in resultList)
            {
                StringBuilder sb = new StringBuilder();
                for (int j = 0; j < l.Count; j++)
                {
                    sb.Append(l[j] + "->");
                }
                result.Add(sb.Remove(sb.Length - 2, 2).ToString());
            }
            return result;
        }
        static private List<List<int>> PrintAllPath(TreeNode rootNode)
        {
            List<List<int>> returnList = new List<List<int>>();
            List<int> fatherData = new List<int>();

            FindNextNode(rootNode, ref returnList, fatherData);
            return returnList;

        }
        static private void FindNextNode(TreeNode fatherNode, ref List<List<int>> returnList, List<int> fatherData)
        {


            List<int> temp = new List<int>();
            temp = fatherData.ToList();
            temp.Add(fatherNode.val);
            List<int> leftFatherData = temp;
            List<int> rightFatherData = temp;
            //结束条件
            if (fatherNode.left == null && fatherNode.right == null)
            {
                returnList.Add(temp);
                return;
            }


            if (fatherNode.left != null)
            {

                FindNextNode(fatherNode.left, ref returnList, leftFatherData);
            }

            if (fatherNode.right != null)
            {
                FindNextNode(fatherNode.right, ref returnList, rightFatherData);
            }



        }
        #endregion