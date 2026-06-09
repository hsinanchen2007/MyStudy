### 解题思路
**广度优先**：
    通过队列来存储所有的节点，然后通过while循环进行层序遍历，每一个while循环都会让属于同一层的节点出队，然后再把下一层的节点压入队列中（通过一个变量来积累每一层的节点数）。
**深度优先**：
    简单粗暴，通过递归，遍历每一个节点，根据每个节点所处的层数，来取出该层的list集合，将值放入集合中，等递归完成，直接返回结果即可。

### 代码
解法一，广度优先：
```java
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new LinkedList<>(  );
        Queue<TreeNode> queue = new LinkedList<>(  );
        queue.offer( root );
        int count = 1;
        while(!queue.isEmpty()){
            int js = 0;
            List<Integer> floor = new LinkedList<>(  );
            for(int i=0;i<count;i++){
                TreeNode node = queue.poll();
                if(null!=node){
                    floor.add( node.val );
                    if(null!=node.left){
                        queue.offer( node.left );
                        js++;
                    }
                    if(null!=node.right){
                        queue.offer( node.right );
                        js++;
                    }
                }

            }
            if(!floor.isEmpty()){
                result.add( floor );
            }
            count = js;
        }
        return result;
    }
}
```
解法二，深度优先：
```java
class Solution {
    public List<List<Integer>> levelOrder( TreeNode root) {
            List<List<Integer>> result = new LinkedList<>(  );
            int floor = 0;
            dfs(root,floor,result);
            return result;
    }

    private void dfs( TreeNode root, int floor, List<List<Integer>> result ) {
            if(null==root){
                return;
            }
            if(result.size()==floor){
                result.add( new LinkedList<Integer>(  ) );
            }
            List<Integer> list = result.get( floor );
            list.add( root.val );
            floor++;
            dfs(root.left,floor,result);
            dfs(root.right,floor,result);
    }
}
```
