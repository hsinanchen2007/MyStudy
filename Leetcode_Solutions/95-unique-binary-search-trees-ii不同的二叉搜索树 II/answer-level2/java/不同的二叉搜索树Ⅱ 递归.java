充分利用二叉搜索树的特性：左子树所有节点都要比根节点小，右子树则要大。

```
class Solution {
    
    //拆分成子问题：
    //由1到n的子树，总体分为n种，分别为以1到n为根的树;
    public List<TreeNode> generateTrees(int n) {
        
        
        if (n <= 0)
            return new ArrayList<TreeNode>();

        List<TreeNode> list = generateTrees(1, n);

        return list;

    }
    
    /*
    * 生成下标start到end之间所有的树
    */
    private List<TreeNode> generateTrees(int start, int end) { 
        
        List<TreeNode> result = new ArrayList<TreeNode>();
        if (start == end) {
            result.add(new TreeNode(start));
            return result;
        }
        
        for (int i = start; i <= end; i++) {
            int leftEnd = i - 1;
            int rightStart = i + 1;

            //这里并不是返回一个空的list，而是返回包含一个空元素的list
            List<TreeNode> nullList = new ArrayList<>();
            nullList.add(null);

            List<TreeNode> left = leftEnd >= start ? generateTrees(start, leftEnd) : nullList;
            List<TreeNode> right = rightStart <= end ? generateTrees(rightStart, end) : nullList;
            
            //遍历所有的左子树和所有的右子树，m*n个树的树
            for (TreeNode leftNode : left) {
                for (TreeNode rightNode : right) {
                    TreeNode root = new TreeNode(i);
                    root.left = leftNode;
                    root.right = rightNode; 
                    result.add(root);
                }
            }
        }
        return result;
        
    }

```
