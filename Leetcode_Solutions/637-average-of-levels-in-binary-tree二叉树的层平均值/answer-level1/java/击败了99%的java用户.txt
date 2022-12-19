## [更多leetcode分类题解](https://github.com/reedfan/leetcode/tree/master/src/main/java/leetcode)

```
public List<Double> averageOfLevels(TreeNode root) {

        List<Double> list = new ArrayList<>();
        if (root == null) {
            return list;
        }

        LinkedList<TreeNode> nodeList = new LinkedList<>();
        nodeList.add(root);
        int cnt = 1;
        double sum = 0;
        int flag = 0;

        while (nodeList.size() > 0) {
            flag = cnt;
            while (cnt > 0) {
                cnt--;
                TreeNode tmp = nodeList.removeFirst();
                sum += tmp.val;
                if (tmp.left != null) {
                    nodeList.add(tmp.left);
                }
                if (tmp.right != null) {
                    nodeList.add(tmp.right);
                }
            }
            list.add(sum/flag);
            sum = 0;
            cnt = nodeList.size();
        }

        return list;
    }
```
