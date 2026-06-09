### DFS
```
class Solution {
    public TreeNode addOneRow(TreeNode root, int v, int d) {
        if(root == null){
            return null;
        }
        if(d == 1){
            TreeNode result = new TreeNode(v);
            result.left = root;
            return result;
        }
        addOneRowCore(root, v, d, 1);
        return root;
    }

    void addOneRowCore(TreeNode node, int v, int d, int cur){
        if(d - 1 == cur){
            TreeNode tempLeft = new TreeNode(v);
                tempLeft.left = node.left;
                node.left = tempLeft;
            TreeNode tempRight = new TreeNode(v);
                tempRight.right = node.right;
                node.right = tempRight;
        } else if(d -1 < cur){
            //注意此处，如果当前的层数已经比想要的层数高了，就截断。
            return;
        } else {
            if(node.left != null){
                addOneRowCore(node.left, v, d, cur+1);
            }
            if(node.right != null){
                addOneRowCore(node.right, v, d, cur+1);
            }
        }
    }
}
```

### BFS


```
class Solution {
    public TreeNode addOneRow(TreeNode root, int v, int d) {
        if(root == null){
            return null;
        }
        if(d == 1){
            TreeNode result = new TreeNode(v);
            result.left = root;
            return result;
        }
        LinkedList<TreeNode> curList = new LinkedList<>();
        curList.push(root);
        int cur = 1;
        int next = 0;
        int layer = 1;
        while(!curList.isEmpty()){
            
            TreeNode temp = curList.removeFirst();
            if(layer == d-1){
                TreeNode leftTemp = new TreeNode(v);
                TreeNode rightTemp = new TreeNode(v);
                leftTemp.left = temp.left;
                rightTemp.right = temp.right;
                temp.left = leftTemp;
                temp.right = rightTemp;
            }
            cur--;
            if(temp.left != null){
                curList.addLast(temp.left);
                next++;
            }
            if(temp.right != null){
                curList.addLast(temp.right);
                next++;
            }
            if(cur == 0){
                cur = next;
                next = 0;
                layer++;
                //注意此处，如果当前的层数已经比想要的层数高了，就截断。
                if(layer > d -1){
                    return root;
                }
            }
        }
        return root;
    }
}
```