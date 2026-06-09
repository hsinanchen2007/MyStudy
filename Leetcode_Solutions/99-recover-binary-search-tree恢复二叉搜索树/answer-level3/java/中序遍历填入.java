基本思想：
    1. 首先遍历二叉树，将书中非空节点的值都加入一个List中
    2. 然后将获取到的列表进行排序
    3. 按照中序遍历的顺序遍历树，将列表的元素按照索引号依次填入树中
```
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    int i = 0;   //遍历排序结果的指针

    /**
     * @param root
     */
    public void recoverTree(TreeNode root) {
        //首先通过中序遍历获得树的列表
        List<Integer> res = new ArrayList<>();
        infixOrder(root, res);
        res.sort(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                if(o1 < o2){
                    return -1;
                }else if(o1 > o2){
                    return 1;
                }else{
                    return 0;
                }
            }
        });
        changeTree(root, res);
    }

    /**
     * 根据排序的结果更新树
     * @param root
     * @param list
     * @param i
     */
    private void changeTree(TreeNode root, List<Integer> list) {
        if (root != null) {
            changeTree(root.left, list);
            root.val = list.get(i++);
            changeTree(root.right, list);
        }
    }

    /**
     * 中序遍历出数组
     * @param root
     * @param ans
     */
    private void infixOrder(TreeNode root, List<Integer> ans) {
        if (root != null) {
            infixOrder(root.left, ans);
            ans.add(root.val);
            infixOrder(root.right, ans);
        }
    }
}
```