#### 一.广度优先遍历, 循环版, 借助队列实现; 自定义数据结构Record, 记录节点和其对所在的层数
```java
import java.util.LinkedList;

class Solution {
    //递归函数逻辑: 以root为根的二叉树的深度
    public int maxDepth(TreeNode root) {
        if(root==null)
            return 0;
        LinkedList<Record> queue = new LinkedList<>();
        queue.add(new Record(root, 1));
        int depth = 0;
        Record curr;
        while(!queue.isEmpty()){
            curr = queue.poll();
            depth = Math.max(depth, curr.level);
            if(curr.node.left!=null)
                queue.add(new Record(curr.node.left, curr.level+1));
            if(curr.node.right!=null)
                queue.add(new Record(curr.node.right, curr.level+1));
        }
        return depth;
    }
    public class Record{
        TreeNode node;
        int level;
        Record(TreeNode node, int level){
            this.node = node;
            this.level = level;
        }
    }
}
```

#### 二.深度优先遍历, 循环版, 借助栈实现; 自定义数据结构Record, 记录节点和其对所在的层数
```java
/*
深度优先遍历, 借助栈实现; 自定义数据结构: 记录节点和其对应的层数
*/
import java.util.Stack;
import java.util.HashSet;

class Solution {
    //递归函数逻辑: 以root为根的二叉树的深度
    public int maxDepth(TreeNode root) {
        if(root==null)
            return 0;
        Stack<Record> s = new Stack<>();
        //记录访问过的节点
        HashSet<TreeNode> set = new HashSet<>();
        int depth = 0;
        //initialize
        s.add(new Record(root, 1));
        set.add(root);
        Record curr;
        while(!s.isEmpty()){
            curr = s.pop();
            depth = Math.max(depth, curr.level);
            //处理孩子节点
            if(curr.node.left!=null && !set.contains(curr.node.left)){
                s.push(curr);
                s.push(new Record(curr.node.left, curr.level+1));
                set.add(curr.node.left);
                continue;
            }
            if(curr.node.right!=null && !set.contains(curr.node.right)){
                s.push(curr);
                s.push(new Record(curr.node.right, curr.level+1));
                set.add(curr.node.right);
                continue;
            }
        }
        return depth;
    }
    public class Record{
        TreeNode node;
        int level;
        Record(TreeNode node, int level){
            this.node = node;
            this.level = level;
        }
    }
}
```
#### 三.深度优先遍历, 递归版
```java
class Solution {
    //递归函数逻辑: 以root为根的二叉树的深度
    public int maxDepth(TreeNode root) {
        if(root==null)
            return 0;
        return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;        
    }
}
```