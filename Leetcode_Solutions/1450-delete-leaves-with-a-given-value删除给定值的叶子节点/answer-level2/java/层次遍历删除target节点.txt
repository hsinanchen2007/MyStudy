因为`一旦删除值为 target 的叶子节点，它的父节点就可能变成叶子节点；如果新叶子节点的值恰好也是 target ，那么这个节点也应该被删除。`

一种比较容易想的思路是从最下面一层开始找，符合值为target的叶子节点给它设为null(删除)，这一层找完后依次往上。使用Queue进行BFS可以做到层次遍历，遍历的同时记录下每个节点和每一层的节点数，用于后面的删除操作。节点数用一个数组队列就可以；考虑到从后往前删，用Stack存放节点可以达到目的，因为LIFO。

代码和解释：
```
class Solution {
    public TreeNode removeLeafNodes(TreeNode root, int target) {
        Queue<TreeNode> queue = new LinkedList<>(); //queue用来遍历二叉树
        Stack<TreeNode> stack = new Stack<>();  //stack用来存放节点
        List<Integer> levelCount = new ArrayList<>();   //记录每一层有多少个非空节点
        if(root == null)    return root;
        queue.offer(root);
        stack.push(root);
        levelCount.add(1);  //第一层只有一个(根)节点
        
        while(!queue.isEmpty()){
            int count = 0;
            //开始遍历当前最后一层的节点，即第levelCount.size()-1层
            for(int i=0; i<levelCount.get(levelCount.size()-1); i++){
                TreeNode node = queue.remove();
                if(node.left != null){
                    count ++;
                    queue.offer(node.left);
                    stack.push(node.left);
                }
                if(node.right != null){
                    count++;
                    queue.offer(node.right);
                    stack.push(node.right);
                }
            }
            levelCount.add(count);  //新一层的节点数
        }
        int num = levelCount.size()-1;  //从最下面一层开始
        while(!stack.isEmpty()){
            for(int i=0; i<levelCount.get(num); i++){   //遍历当前层的节点
                TreeNode node = stack.pop();    //如果是叶子节点且val等于target，删除
                if(node.left!=null && node.left.left==null && node.left.right==null && node.left.val==target)
                    node.left = null;
                if(node.right!=null && node.right.left==null && node.right.right==null && node.right.val==target)
                    node.right = null;
            }
            num--;  //上面一层
        }

        //这里最后要处理一下根节点
        if(root.left==null && root.right==null && root.val == target) root = null;
        return root;
    }
}
```

这里有两个需要注意的地方。
**一**是迭代处理完这棵树之后，根节点可能也变成了叶子节点，迭代过程中因为用的node.left/right来表示当前节点，这就跳过了最后的root，所以单独处理一下root能不能删的情况；
**二**是写删除节点的时候，即第二个while循环里，我一开始是从stack里得到一个节点后，就立即对他进行判断，如果它满足条件就直接给设为null:
```
while(!stack.isEmpty()){
    for(int i=0; i<levelCount.get(num); i++){   //遍历当前层的节点
        TreeNode node = stack.pop();
        if(node.left==null && node.right==null && node.val == target)   node = null;       
    }
    num--;  //上面一层
}
```
发现这些写出来的结果一个节点也没有删掉。原因是新建的node节点虽然指向了stack里取出的节点A，但是把node设为null，原本树的这个节点A并不发生改变，改变的只是node的指向；而对于node.left/right，如果给它设为null，此时node指向的还是树里的节点A，现在就是A.left = null了。

