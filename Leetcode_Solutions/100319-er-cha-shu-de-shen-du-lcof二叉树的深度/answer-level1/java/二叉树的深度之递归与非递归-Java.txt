### 解题思路
方法1：递归法
递归法直接就利用Java的Math包返回最大值即可；

### 代码
```
return root==null ? 0:Math.max(maxDepth(root.left),maxDepth(root.right))+1;
```

方法2：栈
本质上是后序遍历
非递归可以利用栈（有点复杂，主要在于对已访问节点的判断）
把根节点root先压入栈，创建两个TreeNode节点，一个用于返回实时的栈顶元素，一个用于返回先前已访问过节点
对栈判空+循环，开始遍历，【若当前访问的节点为叶子 即无子树，则弹出当前节点并返回至上一个节点并访问其另外的子树检查是否访问过，若没有则遍历一直到叶子为止】，重复这个操作，即可遍历整棵树得到深度

###代码：
```

if(root == null) return 0;
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        TreeNode top;
        TreeNode lastVisit = root;
        int cnt = 0;
        while(! stack.isEmpty()){
            cnt = Math.max(cnt,stack.size());
            top = stack.peek();
            if(top.left != null && lastVisit != top.left && lastVisit != top.right){
                stack.push(top.left);
            }
            else if(top.right != null && lastVisit != top.right){
                stack.push(top.right);
            }
            else{
                lastVisit = stack.pop();
            }
            
        }

        return cnt;

```


方法3：双向队列Deque
本质上是层次遍历，也可视为root数组的从左到右的遍历
非递归还能利用双向队列
把根节点放入队列后再取出接着对其左右子树判空，有则加入分别加入队尾，再依次对剩余节点子树进行判空操作，若为叶子节点则使得当前节点指向队尾（下一次循环则下一层），此时当前层次遍历完毕，深度+1。

### 代码

```java

class Solution {
    public int maxDepth(TreeNode root) {
        if(root == null) return 0;
        
        Deque<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        TreeNode queueLast = root;
        TreeNode nowVisit;
        int depth = 0;
        
        while(!queue.isEmpty()){
            nowVisit = queue.poll();
            if(nowVisit.left != null) queue.offer(nowVisit.left);
            if(nowVisit.right != null) queue.offer(nowVisit.right);
            if(nowVisit == queueLast){
                queueLast = queue.peekLast();
                depth++;
            }
        }
        return depth;

    }
}
```