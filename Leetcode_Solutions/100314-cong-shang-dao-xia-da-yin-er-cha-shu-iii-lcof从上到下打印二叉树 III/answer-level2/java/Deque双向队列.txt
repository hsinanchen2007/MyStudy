队列有前后两端，首先将root加入队列，第一层level = 1；
奇数层：level%2 == 1时，从队列的前面取值，pollFirst，然后在队列后端加入左右节点，即addLast(left) addLast(right)
偶数层：level%2 == 0时，从队列的后面取值，pollLast，然后在队列前端加入右左节点，即addFirst(right) addFirst(left)
```
public List<List<Integer>> levelOrder3(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if(root==null) return ans;
        Deque<TreeNode> deque = new ArrayDeque<>();
        deque.add(root);
        int level = 1;
        while(!deque.isEmpty()){
            List<Integer> list = new ArrayList<>();
            int size = deque.size();
            for(int i=0;i<size;i++){
                if(level%2==1){
                    TreeNode tmp = deque.pollFirst();
                    list.add(tmp.val);
                    if(tmp.left!=null) deque.addLast(tmp.left);
                    if(tmp.right!=null) deque.addLast(tmp.right);
                }
                else{
                    TreeNode tmp = deque.pollLast();
                    list.add((tmp.val));
                    if(tmp.right!=null) deque.addFirst(tmp.right);
                    if(tmp.left!=null) deque.addFirst(tmp.left);
                }
            }
            level++;
            ans.add(list);
        }
        return ans;
    }
```
