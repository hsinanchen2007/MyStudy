N树的层次遍历可以看作是图的广度优先搜索
可以使用队列实现

本题难点在于要分割出每一层的节点，而BFS中访问节点和加入新节点是同时进行的，
解决方法就是用一个counter记录数量

```java
class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> result = new ArrayList<>();
        Queue<Node> queue = new LinkedList<Node>();
        
        if (root != null) {
            // first node
            queue.offer(root);
            
            while(!queue.isEmpty()) {
                List<Integer> list = new ArrayList<>();
                
                // fixed size of last level node
                int count = queue.size();
                for(int i = 0; i < count; i++) {
                    // enqueue next level node
                    Node cur = queue.poll();
                    for(Node node : cur.children) {
                        queue.add(node);
                    }
                    // add current node value
                    list.add(cur.val);
                }
                // add this level value
                result.add(list);
            }
        }
        return result;
    }
}
```
