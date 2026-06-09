本题比较投机取巧，使用了优先队列，所以代码较短，时间复杂度应该也不高。贴代码
```
package lc169;


import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;

class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
 }
public class p5296 {
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();
        getOneRoot(root1,priorityQueue);
        getOneRoot(root2,priorityQueue);
        List<Integer> list = new LinkedList<>();
        while (!priorityQueue.isEmpty()){
            list.add(priorityQueue.poll());
        }
        return list;
    }
    public void getOneRoot(TreeNode root,PriorityQueue<Integer> priorityQueue){
        if(root!=null) {
            priorityQueue.offer(root.val);
            getOneRoot(root.left,priorityQueue);
            getOneRoot(root.right,priorityQueue);
        }
    }
}
```
