使用双端队列
从左向右遍历时，向双端队列尾部添加元素，
从右向左遍历时，向双端队列头部添加元素。
在队列中使用一个null元素做分割标记
使用`l2r`做方向标识
```
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        if(root == null) return list;
        Deque<TreeNode> deque = new LinkedList<TreeNode>();
        deque.offer(root);
        deque.offer(null);
        boolean l2r = true;  // left to right 缩写
        
        while(!deque.isEmpty()) {
            if(deque.getFirst() == deque.getLast()) break;
            List<Integer> subList = new ArrayList<Integer>();
            
            while(!deque.isEmpty()) {
                if(l2r){
                    TreeNode temp = deque.pollFirst();
                    if(temp == null) {
                        deque.offerFirst(null);
                        break;
                    }
                    subList.add(temp.val);
                    if(temp.left != null)
                        deque.offerLast(temp.left);
                    if(temp.right != null)
                        deque.offerLast(temp.right);
                }
                else {
                    TreeNode temp = deque.pollLast(); 
                    if(temp == null) {
                        deque.offerLast(null);
                        break;
                    }
                    subList.add(temp.val);
                    if(temp.right != null)
                        deque.offerFirst(temp.right);
                    if(temp.left != null)
                        deque.offerFirst(temp.left);
                }
            }
 
            list.add(subList);
            l2r = !l2r;
        }
        return list;
    }
}
```
