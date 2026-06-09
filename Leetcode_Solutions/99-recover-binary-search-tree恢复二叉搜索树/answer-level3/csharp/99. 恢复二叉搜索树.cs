```
/**
    如果是二叉搜索树，那么树的中序遍历就是一组递增序列
    1、获取中序遍历
    2、中序列表排序 获取变更的索引及其值
    3、再进行一次中序遍历，修正
*/
/**
public class Solution {
    public void RecoverTree(TreeNode root) {
        if (root == null) {
            return;
        }
        List<int> list = new List<int>();
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode node = root;
        // 中序遍历
        while (stack.Count != 0 || node != null) {
            while (node != null) {
                stack.Push(node);
                node = node.left;
            }
            node = stack.Pop();
            list.Add(node.val);
            node = node.right;
        }
        int index1 = -1, index2 = -1, value1 = -1, value2 = -1;
        int preValue = list[0], value = -1;
        // 查找出替换的索引即值
        for (int i = 1; i < list.Count; i++) {
            value = list[i];
            if (preValue > value) {
                if (index1 == -1) {
                    index1 = i - 1;
                    value1 = preValue;
                    // 替换的位置相邻
                    index2 = i;
                    value2 = value;
                } else {
                    index2 = i;
                    value2 = value;
                    break;
                }
            }
            preValue = value;
        }

        // 中序遍历修正
        node = root;
        int index = 0;
        while (stack.Count != 0 || node != null) {
            while (node != null) {
                stack.Push(node);
                node = node.left;
            }
            node = stack.Pop();
            if (index == index1) {
                node.val = value2;
            } else if (index == index2) {
                node.val = value1;
                break;
            }
            node = node.right;
            index++;
        }
    }
}
*/
// Accepted
//     1917/1917 cases passed (156 ms)
//     Your runtime beats 12.5 % of csharp submissions
//     Your memory usage beats 25 % of csharp submissions (26.9 MB)

/**
    如果是二叉搜索树，那么树的中序遍历就是一组递增序列
    1、获取中序遍历
    2、中序列表排序 获取变更的索引及其值
    3、再进行一次中序遍历，修正

    优化：一个中序遍历中完成替换
*/
public class Solution {
    public void RecoverTree(TreeNode root) {
        if (root == null) {
            return;
        }
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode node = root;

        TreeNode changeNode1 = null, changeNode2 = null;
        TreeNode preNode = null;
        // 中序排列
        while (stack.Count != 0 || node != null) {
            while (node != null) {
                stack.Push(node);
                node = node.left;
            }
            node = stack.Pop();

            // 从第二个节点进行比较
            if (preNode != null && preNode.val > node.val) {
                if (changeNode1 == null) {
                    changeNode1 = preNode;
                    // 替换的位置相邻，下一个就要替换
                    changeNode2 = node;
                } else {
                    changeNode2 = node;
                    break;
                }
            }
            preNode = node;
            node = node.right;
        }
        // 替换值
        int value = changeNode1.val;
        changeNode1.val = changeNode2.val;
        changeNode2.val = value;
    }
}
// Accepted
//     1917/1917 cases passed (124 ms)
//     Your runtime beats 93.75 % of csharp submissions
//     Your memory usage beats 25 % of csharp submissions (26.9 MB)
```
