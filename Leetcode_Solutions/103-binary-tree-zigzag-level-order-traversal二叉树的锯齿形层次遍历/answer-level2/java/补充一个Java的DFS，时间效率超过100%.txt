![image.png](https://pic.leetcode-cn.com/d3a414f3cf7d9051d2e16b182ee4bddc991a590dbf83592d38c6107ed8b011c8-image.png)


```
    /**
     * 和102题目类似 使用DFS
     * 根据层级做判断 是加在头部 还是尾部
     */
    class Solution {

        List<List<Integer>> list = new ArrayList<>();

        public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
            pre(root, 0);
            return list;
        }

        private void pre(TreeNode root, int depth){
            if (root == null) return;
            if (depth >= list.size() || list.get(depth) == null){
                list.add(new LinkedList<>());        //  我觉得此地方还是有问题  可能出现溢出
            }
            LinkedList<Integer> linkedList = (LinkedList<Integer>) list.get(depth);
            if(depth % 2 == 0) linkedList.addLast(root.val);
            else linkedList.addFirst(root.val);
            pre(root.left, depth+ 1 );
            pre(root.right, depth + 1);
        }
    }
```


![startmoon.png](https://pic.leetcode-cn.com/f4f1ca5d0cad052c79570a7f1b9c2868debf4ff8d0660a86b9f71fbfb438b19a-startmoon.png)
