### 解题思路
循环添加节点，并用计数器来标识每一层的节点总数（减去空节点），每遍历完一层就添加到结果集中去。

1. 创建一个TreeNode数组trees用来存放所有节点（包括null），初始添加根节点root。
2. 对trees进行循环，判断节点是否为空，若不为空，则将两个子节点添加到trees中，并在list中添加元素；
若为空，记录下层节点null个数值nc值加2。
3. 使用变量c对每一层子节点进行标记，每层总量为1,2,4,8....增加，但需要减去nc的值，同时每次循环都减一。
4. 若c为0，意味着同一层节点遍历结束，将list添加至结果集中。
5. 反转数组并返回结果。

### 代码

```java
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> allList = new ArrayList<>();
        if (root == null) return allList;
        List<TreeNode> trees = new ArrayList<>();
        trees.add(root);
        List<Integer> list = new ArrayList<>();
        int c = 1, old = 1, nc = 0;
        for (int i = 0; i < trees.size(); i++) {
            TreeNode node = trees.get(i);
            if (node != null) {
                list.add(node.val);
                trees.add(node.left);
                trees.add(node.right);
            } else {
                nc += 2;
            }
            if (--c == 0) {
                if (!list.isEmpty()) allList.add(list);
                list = new ArrayList<>();
                c = old * 2 - nc;
                old = c;
                nc = 0;
            }
        }
        Collections.reverse(allList);
        return allList;
    }
}
```