### 解题思路
同样，使用广度优先遍历（BFS）思路大致相似。使用队列遍历树的每一层，将每一层节点的值val存储到一个临时List集合中。此List集合用于存储每层节点的值，在当前while循环再将此List集合整个作为最终目的集合的引用类型<List<Integer>。

### 算法步骤：
1. 创建队列和目的List集合
2. 将root添加到队列中
3. 利用while循环，当队列不为空时，创建一个临时集合List<Integer> tmp = new ArrayList<>();（此行代码必须放在while中）
4. 利用for循环把队头取出，头节点的值val添加到tmp中，检查是否有孩子节点，有则添加 （注意队列的size在动态变化）
5. 此时当前层遍历完毕，将tmp作为元素添加到目的集合
6. 重复3、4、5操作直至队列为空（即遍历完毕）

时间复杂度：O(N) N是树的节点数目
空间复杂度：O(N) 
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
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        List<List<Integer>> resList = new ArrayList<>(); 
        if(root == null) return resList;
        q.offer(root);
        
        while(!q.isEmpty()){
            List<Integer> tmp = new ArrayList<>();
            for(int i = q.size();i > 0;i--){
                TreeNode node = q.poll();
                tmp.add(node.val);
                if(node.left != null) q.offer(node.left);
                if(node.right != null) q.offer(node.right);
            } 
            resList.add(tmp);
        }  
        return resList;
    }
}
```