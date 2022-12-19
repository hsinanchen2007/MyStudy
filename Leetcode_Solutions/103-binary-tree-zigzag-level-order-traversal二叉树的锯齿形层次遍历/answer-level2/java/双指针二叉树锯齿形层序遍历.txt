![捕获.PNG](https://pic.leetcode-cn.com/8bea5996187de69475e743687b049f7ffe87f063abf04429a19c900130aa6362-%E6%8D%95%E8%8E%B7.PNG)

### 解题思路   
    解决该问题在最初层序便利的基础上需要注意两点：
        1.遍历到层末的时候的处理
        2.奇数层需要反转的情况
    大体思路：
        对于基础的借助队列进行层序遍历就不多加赘述了。
        1.为了处理层末情况，引入两个指针，currentLast，nextLast顾名思义第一个指针维持着指向当前层的末尾结点，nextLast维持下一层的      末尾结点。
        currentLast的更新：当前结点等于currentLast结点时，currentLast = newxtLast，已知此时到达层末，需要temp插入总的list。
        nextLast的更新：nextLast时刻指向新入队的结点。
        2.对于反转情况：
        引入一个奇数标志位oddFlag（表示当前层是否为奇数层，如是奇数层需要反转）
        在1中到达层么时则需要将此时的temp反转，并在更新新oddFlag ^= true;

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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> list = new ArrayList<>();
        if (root == null) {
           return list; 
        }
        boolean oddFlag = false;//当前层为奇数时需要反转
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        TreeNode currentLast = root;
        TreeNode nextLast = null;
        TreeNode current = null;
        List<Integer> temp = new ArrayList<>();
        while (!queue.isEmpty()) {
            current = queue.remove();
            if(current.left != null) {
                queue.add(current.left);
                nextLast = current.left;
            }
            if(current.right != null) {
                queue.add(current.right);
                nextLast = current.right;
            }
            temp.add(current.val);
            if(current == currentLast) {
                currentLast = nextLast;
                if(oddFlag) {
                    Collections.reverse(temp);
                }
                list.add(temp);
                temp = new ArrayList<>();
                oddFlag ^= true;//与true异或相当于取反
            }
        }
        return list;
    }
}
```