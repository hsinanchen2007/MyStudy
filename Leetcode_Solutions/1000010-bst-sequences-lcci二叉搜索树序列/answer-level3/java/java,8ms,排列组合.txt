原数组第一位一定是根节点。其**左子树，右子树插入顺序交换不会影响二叉搜索树形态**。保证左子树的相对顺序不变、右子树的相对顺序不变，罗列所有可能的组合

```
class Solution {
     public List<List<Integer>> BSTSequences(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) {                                         //空结点
            res.add(new ArrayList<>());
            return res;
        }
        List<List<Integer>> left = BSTSequences(root.left);
        List<List<Integer>> right = BSTSequences(root.right);
        if (left.get(0).size() == 0 && right.get(0).size() == 0) {  //左右子树均为空
            List<Integer> list = new ArrayList<>();
            list.add(root.val);
            res.add(list);
            return res;
        }
        if (left.get(0).size() == 0 || right.get(0).size() == 0) {  //左右子树之一为空
            List<List<Integer>> last = left.get(0).size() == 0 ? right : left;
            for (List<Integer> integers : last) {
                List<Integer> list = new ArrayList<>();
                list.add(root.val);
                list.addAll(integers);
                res.add(list);
            }
            return res;
        }
        for (List<Integer> l1 : left) {                             //左右子树均不为空
            for (List<Integer> l2 : right) {
                List<Integer> temp = new ArrayList<>();
                temp.add(root.val);
                combine(l1, l2, res, 0, 0, temp);                   //重新排列
            }
        }
        return res;
    }

    private void combine(List<Integer> l1, List<Integer> l2, List<List<Integer>> res, int start1, int start2, List<Integer> temp) {
        if (start1 == l1.size() && start2 == l2.size()) {       //左右全部添加完毕
            res.add(new ArrayList<>(temp));
            return;
        }
        if (start1 == l1.size() || start2 == l2.size()) {       //左右其中一个添加完，剩下的全部加入
            int len = temp.size();
            List<Integer> rest = start1 == l1.size() ? l2 : l1;
            int start = rest == l1 ? start1 : start2;
            for (int i = start; i < rest.size(); i++) {
                temp.add(rest.get(i));
            }
            res.add(new ArrayList<>(temp));
            if (temp.size() > len) {
                temp.subList(len, temp.size()).clear();
            }
            return;
        }
        temp.add(l1.get(start1));                               //添加左子树节点
        combine(l1, l2, res, start1 + 1, start2, temp);
        temp.remove(temp.size() - 1);
        temp.add(l2.get(start2));                               //添加右子树节点
        combine(l1, l2, res, start1, start2 + 1, temp);
        temp.remove(temp.size() - 1);
    }
}
```
