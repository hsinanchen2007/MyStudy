```
public class Solution {
    public IList<IList<int>> LevelOrderBottom(TreeNode root) {
        //bfs
        if(root == null)
        {
            return new List<IList<int>>();
        }

        var nodeQueue = new Queue<TreeNode>();
        var resultList = new List<List<int>>();
        nodeQueue.Enqueue(root);

        while(nodeQueue.Count > 0)
        {
            int size = nodeQueue.Count;
            var midList = new List<int>();
            for(int i = 0; i < size; i++)
            {
                var popUp = nodeQueue.Dequeue();
                midList.Add(popUp.val);

                if(popUp.left != null)
                {
                    nodeQueue.Enqueue(popUp.left);
                }
                if(popUp.right != null)
                {
                    nodeQueue.Enqueue(popUp.right);
                }
            }
            resultList.Add(midList);
        }

        var reverseList = new List<IList<int>>();
        for(int j = resultList.Count - 1; j >= 0; j--)
        {
            reverseList.Add(resultList[j]);
        }

        return reverseList;
    }
}
```
利用队列，存储每层的所有nodes，在顺序输出，并继续入队下一层，直到最后结束。
出队的nodes，存入list，最后把list reverse一下就完成了。

附加reverse的做法，c#的List<List<int>>的新插入恶心了一把。。思想没毛病，需要带入depth去递归：
```
public IList<IList<int>> LevelOrderBottom(TreeNode root)
        {
            var resultList = new List<IList<int>>() { new List<int>() };
            if (root == null)
            {
                return new List<IList<int>>();
            }

            int depth = 0;
            SetIntoList(resultList, 0, root);

            //Reverse
            var result = new List<IList<int>>();
            int count = 0;
            for (int i = resultList.Count - 1; i >= 0; i--)
            {
                result.Add(resultList[i]);
            }

            return result;
        }

        private void SetIntoList(IList<IList<int>> resultList, int depth, TreeNode root)
        {
            if (resultList.Count - 1 < depth)
            {
                resultList.Add(new List<int>());
            }

            resultList[depth].Add(root.val);
            if (root.left != null)
            {
                SetIntoList(resultList, depth + 1, root.left);
            }
            if (root.right != null)
            {
                SetIntoList(resultList, depth + 1, root.right);
            }
        }
```
