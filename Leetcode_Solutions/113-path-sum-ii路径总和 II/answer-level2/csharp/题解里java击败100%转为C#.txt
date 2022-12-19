看没有C#题解，加个进来

执行用时296ms，击败C#90.48%，内存消耗31.7MB，击败53。85%
看没有c#的答案，用题解里java的代码转了过来

```
执行用时296ms，击败C#90.48%，内存消耗31.7MB，击败53。85%
看没有c#的答案，用题解里java的代码转了过来

List<IList<int>> res = new List<IList<int>>();
        List<int> list = new List<int>();
        public IList<IList<int>> PathSum(TreeNode root, int sum)
        {
            if(root==null)
            {
                return res;
            }
            sum -= root.val;
            list.Add(root.val);

            if(root.left==null&&root.right==null)
            {
                if(sum==0)
                {
                    res.Add(new List<int>(list));
                }
               
            }
            if(root.left!=null)
            {
                PathSum(root.left, sum);
            }
            if(root.right!=null)
            {
                PathSum(root.right, sum);
            }
            list.RemoveAt(list.Count-1);
            return res;

        }
```


       