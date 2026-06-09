```java
class Solution {

    /**
     * 最大出现次数
     */
    private int maxCount;
    /**
     * 维护当前众数
     */
    private List<Integer> list;
    /**
     * 维护中序遍历前一节点的值和出现次数
     */
    private int num = 0, count = 0;

    public int[] findMode(TreeNode root) {
        if (root == null) {
            return new int[0];
        }
        list = new ArrayList<>();
        inOrder(root);
        int[] ans = new int[list.size()];
        int i = 0;
        for (int num : list) {
            ans[i++] = num;
        }
        return ans;
    }

    /**
     * 中序遍历
     */
    private void inOrder(TreeNode root) {
        if (root == null) {
            return;
        }
        // 遍历左子树
        inOrder(root.left);

        // 更新num,count
        if (root.val == num) {
            count++;
        } else {
            num = root.val;
            count = 1;
        }

        // 更新maxCount和list
        if (maxCount < count) {
            maxCount = count;
            list.clear();
            list.add(root.val);
        } else if (maxCount == count) {
            list.add(root.val);
        }
        // 遍历右子树
        inOrder(root.right);
    }
    
}
```
