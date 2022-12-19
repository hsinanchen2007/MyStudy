### 解题思路
由题意可知，相当于将二叉树放在一个坐标系中，根节点为于坐标（0，0）处，最后想要的结果是横坐标相同的结点为一组，如果两个结点的横坐标相同，那么按照结点值大小进行从小到大排序。
二叉树的层次遍历本身就自带“纵坐标”，那么，只需要再增加一个记录结点横坐标的List即可得到二叉树结点的横纵坐标。
**本方法使用队列进行二叉树的层次遍历**。得到横坐标也很简单，只需再增加一个队列和一个List即可，根节点的横坐标值为0，队列中每增加一个左子树结点，表示该结点横坐标的队列就增加一个0 - 1，每增加一个右子树结点，表示该结点横坐标的队列就增加一个
0 + 1，这样，最后就得到一个记录二叉树每个结点横坐标的List，以题目中的示例1为例说明：
![image.png](https://pic.leetcode-cn.com/a33903cc5847380711b8d122974a2fb908072b131aed22fbfcbdb5e92ba0fe42-image.png)
层次遍历后的结果是：
3
9，20
15，7
得到结点横坐标的List的结果是：
0
-1，1
0，2
记录横坐标的最小和最大值min = -1，max = 2,
然后遍历记录二叉树横坐标的List，从min开始，和min值相同的结点加入一个List，相同层的按值从小到大排序。
### 代码

```java
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
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        List<List<Integer>> level = new ArrayList<>();
        List<List<Integer>> levelFlag = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        List<Integer> tempFlag = new ArrayList<>();
        if (root == null) {
            return res;
        }
        TreeNode t = root;
        TreeNode last = root;
        TreeNode nlast = null;
        Queue<TreeNode> q = new LinkedList<>();
        Queue<Integer> qFlag = new LinkedList<>();
        q.offer(t);
        int flag = 0;
        qFlag.offer(flag);
        while (!q.isEmpty()) {
            t = q.peek();
            q.poll();
            flag = qFlag.peek();
            qFlag.poll();
            temp.add(t.val);
            tempFlag.add(flag);
            if (t.left != null) {
                q.offer(t.left);
                qFlag.offer(flag - 1);
                nlast = t.left;
            }
            if (t.right != null) {
                q.offer(t.right);
                qFlag.offer(flag + 1);
                nlast = t.right;
            }
            if (t == last) {
                last = nlast;
                level.add(new ArrayList<>(temp));
                levelFlag.add(new ArrayList<>(tempFlag));
                temp.clear();
                tempFlag.clear();
            }
        }
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < levelFlag.size(); i++) {
            for (int j = 0; j < levelFlag.get(i).size(); j++) {
                min = levelFlag.get(i).get(j) < min ? levelFlag.get(i).get(j) : min;
                max = levelFlag.get(i).get(j) > max ? levelFlag.get(i).get(j) : max;
            }
        }
        // System.out.println(min + ", " + max);
        temp.clear();
        tempFlag.clear();
        while (min <= max) {
            for (int i = 0; i < level.size(); i++) {
                for (int j = 0; j < level.get(i).size(); j++) {
                    if (levelFlag.get(i).get(j) == min) {
                        tempFlag.add(level.get(i).get(j));
                    }
                }
                Collections.sort(tempFlag);
                for (int k = 0; k < tempFlag.size(); k++) {
                    temp.add(tempFlag.get(k));
                }
                tempFlag.clear();
            }
            res.add(new ArrayList<>(temp));
            temp.clear();
            min++;
        }
        return res;
    }
}
```