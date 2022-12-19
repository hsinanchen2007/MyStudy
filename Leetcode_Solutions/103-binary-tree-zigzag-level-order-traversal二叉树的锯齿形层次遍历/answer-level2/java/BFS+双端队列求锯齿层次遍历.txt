### 解题思路
层次遍历->显然是BFS
**BFS模板**
1. 申请队列
2. 队列初始化
3. 队列不为空{取出元素，一顿操作，满足条件加入队列}
**锯齿型遍历**
- 需要layer指示是奇数层还是偶数层
- 需要用到双端队列deque
**- *先入队列，再出队列*
- *奇数层 offerFirst pollFirst 先右子树，再左子树；*
- *偶数层 offerLast pollLast 先左子树，再右子树；***

### 代码

```java
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new LinkedList<List<Integer>>();
        Deque<TreeNode> deque = new LinkedList<TreeNode>();
        if(root != null){
            deque.offerFirst(root);
        }
        int layer = 1;//奇数层，offerFirst pollFirst 先右子树，再左子树；偶数层相反
        while(deque.size() > 0){
            System.out.println(layer);
            int size = deque.size();
            List<TreeNode> list = new LinkedList<TreeNode>();
            while(size-- > 0){
                if(layer == 1){
                    list.add(deque.pollFirst());
                }else{
                    list.add(deque.pollLast());
                }
            }
            //取出元素后马上改变奇偶层数指示，保证队列是先放再取的！！！
            layer = layer == 1 ? 0 : 1;
            List<Integer> outList = new LinkedList<Integer>();
            for(TreeNode node : list){
                outList.add(node.val);
                System.out.println(node.val);
                if(layer == 1){
                    if(node.right != null){
                        deque.offerFirst(node.right);
                    }
                    if(node.left != null){
                        deque.offerFirst(node.left);
                    }
                }else{
                    if(node.left != null){
                        deque.offerLast(node.left);
                    }
                    if(node.right != null){
                        deque.offerLast(node.right);
                    }
                }
            }
            ans.add(outList);
        }
        return ans;
    }
}
```