用时1ms
有点像求组合
首先可以明确一个问题，那就是如果N为偶数，那么一定无法构成满二叉树，所以排除掉这种情况
递归的时候建立一个List<TreeNode>对象，对于k个节点数而言，那么我们可以构成的结果可能有x种，于是我们将所有的结果放入一个list中
对于某个节点而言，我们可以按照以下原则划分:
(1)i个节点构成的所有可能的树，j个节点所有可能的树，i + j = N - 1  (使用N - 1的原因是，当前的root节点占用了其中的1个位置)；
(2)循环tree1,tree2， 将每种可能都放入一个新的root之后,然后加入到list中；
(3)需要注意的，当i == j时，此时left和right是相同的，因此只能有一类结果。

```
    public List<TreeNode> allPossibleFBT(int N) {
        if((N & 1) == 0) return new ArrayList<>();

        return buildTree(N);
    }

    

    private List<TreeNode> buildTree(int N){
        if(N == 1){
            TreeNode root = new TreeNode(0);
            List<TreeNode> list = new ArrayList<>();
            list.add(root);
            return list;
        } 
        N--;
        List<TreeNode> list = new ArrayList<>();
        for(int i = 1; i <= N / 2; i = i + 2){
            List<TreeNode> tree1 = buildTree(i);
            List<TreeNode> tree2 = buildTree(N - i);
            
            for(TreeNode left : tree1){
                for(TreeNode right : tree2){
                    TreeNode root = new TreeNode(0);
                    root.left = left;
                    root.right = right;

                    list.add(root);

                    if(i == N - i) continue;
                    root = new TreeNode(0);
                    root.left = right;
                    root.right = left;
                    list.add(root);
                }
            }
        }

        return list;
    }
```


