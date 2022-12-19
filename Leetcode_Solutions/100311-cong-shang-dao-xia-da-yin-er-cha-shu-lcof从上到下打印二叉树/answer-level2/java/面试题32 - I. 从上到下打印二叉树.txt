### 解题思路
此题为剑指offer 第23题
每次打印一个节点时，如果该节点有子节点，则把该节点的子节点放到一个队列的末尾。
从队列中取出最早进入队列的节点，重复上一步操作
直到队列为空。

考察知识点：java中队列的操作
双端队列接口Deque  实现类ArrayDeque,  LinkedList
此接口扩展了 Queue 接口。在将双端队列用作队列时，将得到 FIFO（先进先出）行为。将元素添加到双端队列的末尾，从双端队列的开头移除元素。从 Queue 接口继承的方法完全等效于 Deque 方法，如下表所示：
![image.png](https://pic.leetcode-cn.com/bcac6ecb83be8e00d21cfdb603ab63173a76d8ed6675a8643ed778ee352cc610-image.png)

双端队列也可用作 LIFO（后进先出）堆栈。应优先使用此接口而不是遗留 Stack 类。在将双端队列用作堆栈时，元素被推入双端队列的开头并从双端队列开头弹出。堆栈方法完全等效于 Deque 方法，如下表所示：
![image.png](https://pic.leetcode-cn.com/8e9ca5eab9cb88be7ef37c8f0948ff8ccff8801070887c88d8d16c441bb78f44-image.png)



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
    public int[] levelOrder(TreeNode root) {
        if(root==null){
            return new int[0];
        }
        List<Integer> list=new ArrayList<Integer>();
        Deque<TreeNode> deque=new ArrayDeque();
        deque.push(root);
        TreeNode node=null;
        while(!deque.isEmpty()){
            node=deque.poll();
            list.add(node.val);
            if(node.left!=null){
                deque.add(node.left);
            }
            if(node.right!=null){
                deque.add(node.right);
            }
        }
        int len=list.size();
        int[] res=new int[len];
        for(int i=0;i<len;i++){
            res[i]=list.get(i);
        }
        return res;
    }
}
```