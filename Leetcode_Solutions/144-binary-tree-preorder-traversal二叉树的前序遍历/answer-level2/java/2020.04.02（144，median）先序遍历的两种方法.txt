### 解题思路
本题给出两种思路解决先序遍历

第一种是用到非递归，即**迭代**的方法遍历二叉树
- 使用迭代遍历的巧妙之处是定义一个**结构体**，利用结构体创建**两个结构体变量**分别记录结点的行为和结点的位置

- 首先做好**准备工作** 1.创建 `ArrayList` 数组用来接收遍历后的元素 2.判空，3. 创建结构体栈，并将根节点入栈

- 接下来对栈内元素进行**分类判断**，这里定义 `c` 来接收栈顶元素，并判断该结点的行为是要打印还是遍历下一个

- 如果是**打印**即 `print`，就将该结点放入数组中

- 如果是要**遍历下一个结点**即 `move`，则经过判空后将该结点的右孩子，左孩子和自己依次放入数组完成先序遍历

PS:此方法的便利之处就在于无论是先序，中序或后序遍历的时候只要改动一下遍历结点的顺序即可完成操作。


第二种是用到**递归**遍历，过程简单清晰
- 首先创建 `ArrayList` 数组用来接收遍历后的元素

- 然后**定义先序遍历的方法**依次将结点本身，左孩子，右孩子放入数组完成遍历即可。

### 代码

```java []
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
    
    // 定义结点结构体，包括该结点此时的行为，结点的位置
    private class Command{
        // 定义 s 代表结点的行为包括“print”和“move”
        String s;
        // 定义 node 代表结点的位置包括当前结点和结点的孩子
        TreeNode node;
        Command(String s, TreeNode node) {
            this.s = s;
            this.node = node;
        }
    };   
    
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }
        // 定义栈存放结构体元素
        Stack<Command> stack = new Stack<>();
        // 先将根节点入栈
        stack.push( new Command("move", root) );  
        
        while ( !stack.empty() ) {
            // 定义 c 来接收栈顶元素
            Command c = stack.pop();  
            // 如果 c 的行为是 print 则将该结点值放入 List 集合中
            if ( c.s.equals("print") ) {
                ans.add(c.node.val);
            } else {
                // 如果是 move 行为，则依次遍历右孩子，左孩子，自己
                if (c.node.right != null) {
                    stack.push( new Command("move", c.node.right) );
                }
                if (c.node.left != null) {
                    stack.push( new Command("move", c.node.left) );
                }
                stack.push( new Command("print", c.node) );
            }
        }
        return ans;
    }
}
```
```java []
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

    public List<Integer> preorderTraversal(TreeNode root) {
        // 创建数组接收遍历后的元素
        List<Integer> ans = new ArrayList<>();
        // 递归遍历
        preorderTraversal(root, ans);
        return ans;
    }
    // 先序遍历顺序：自己，左孩子，右孩子
    private void preorderTraversal(TreeNode node, List<Integer> list){
        if(node != null){
            list.add(node.val);
            preorderTraversal(node.left, list);
            preorderTraversal(node.right, list);
        }
    }
}
```
```java []
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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        
        // 定义 p 指向当前遍历结点（从根节点开始）
        TreeNode p = root;    
        
        while ( p != null || !stack.isEmpty() ) {
            // 若当前遍历结点不为 null，就放入数组，并访问其左孩子
            while (p != null) {
                ans.add(p.val);
                stack.push(p);
                p = p.left;
            }
            // 把左孩子为空的结点弹出栈，并访问其右孩子
            p = stack.pop().right;
        }
        return ans;
    }
}
```