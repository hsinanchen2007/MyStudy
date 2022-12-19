## [更多leetcode分类题解](https://github.com/reedfan/leetcode/tree/master/src/main/java/leetcode)

```
public List<Integer> largestValues(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        if (root == null) {
            return list;
        }

        LinkedList<TreeNode> nodeList = new LinkedList<>();
        nodeList.add(root);
        int cnt = 1;
        int maxValue = Integer.MIN_VALUE;

        while (nodeList.size() > 0) {
            while (cnt > 0) {
                cnt--;
                TreeNode tmp = nodeList.removeFirst();
                maxValue = maxValue > tmp.val ? maxValue : tmp.val;
                if (tmp.left != null) {
                    nodeList.add(tmp.left);
                }
                if (tmp.right != null) {
                    nodeList.add(tmp.right);
                }
            }
            list.add(maxValue);
            maxValue = Integer.MIN_VALUE;
            cnt = nodeList.size();
        }

        return list;


    }
```
