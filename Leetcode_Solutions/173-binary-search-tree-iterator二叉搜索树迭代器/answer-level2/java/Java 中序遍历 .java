中序遍历把树转换成ArrayList在用迭代器迭代

```java
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Stack;

class BSTIterator {

    private TreeNode root;

    private List<Integer> list = new ArrayList<>();

    private Stack<TreeNode> stack = new Stack<>();

    private Iterator itr;


    public BSTIterator(TreeNode root) {
        this.root = root;
        buildTree(this.root);
        itr = list.iterator();
    }

    /** @return the next smallest number */
    public int next() {
        return (int) itr.next();
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return itr.hasNext();
    }

    private void buildTree(TreeNode root){
        TreeNode cur = root;
        while(cur!=null||!stack.isEmpty()){
            if(cur!=null){
                stack.push(cur);
                cur = cur.left;
            } else {
                cur = stack.pop();
                list.add(cur.val);
                cur = cur.right;
            }
        }
    }
}

```

