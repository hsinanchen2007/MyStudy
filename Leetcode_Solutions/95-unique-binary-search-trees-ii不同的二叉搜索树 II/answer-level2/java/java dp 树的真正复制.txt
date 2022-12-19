### 解题思路
速度100 空间89
![TIM图片20191227095203.png](https://pic.leetcode-cn.com/a32dff4dcbb2eddecc101bd66982590b5bb8f376a020edca436b1afa69f0dd78-TIM%E5%9B%BE%E7%89%8720191227095203.png)

**dp解题思路**
1. 从前往后推。
2. 新增节点的值（n）是目前为止最大的，已知n-1时的所有的树的情况。
3. 对于n-1的任意一种情况，插入的方式都是一样，不同的是每种情况可插入的次数是不同的。
4. 插入方式：
    1. 因为要插入的节点是最大的，所以，n要么在根节点的右边，要么成为新的跟节点。
    2. 成为根节点，此处简单，直接node.left = root;即可
    3. 插在根的右边，插入方式如下：
        - 成为根的右儿子，根原来的右儿子成为新节点的左儿子。
        - 成为根的右儿子的右儿子，根的右儿子的原来的右儿子成为新节点的左儿子。
        - 直至新节点成为了叶子节点。
    图示：
![树.PNG](https://pic.leetcode-cn.com/c929b5e750267966d1e4bcfb166c9507d356b9e4c2d3c054d65f9035527b00ad-%E6%A0%91.PNG)

5. 对于n-1的所有情况，对要进行依次4的插入方式。遍历完即为n的所有情况。
6. 为了保存n所对应的树，使用map(n,list)保存，使用map原本是为了节省以后的查找。
6. 初始化1即可。
```
TreeNode root = new TreeNode(1); 
list.add(root);
map.put(1,list);
```


**树的复制**
刚开始直接写的时候，直接将引用赋给变量。
因为每种情况大部分都要遍历2遍以上，将引用赋给变量之后，一旦构成新树，原本的情况就改变了。造成的后果就是无法正确进行之后的遍历。
深克隆目前还不会，实现起来也比较麻烦。所以，直接采用遍历的方式来复制一棵树。

**新树的生成**
由于复制出来的树是用来生成新树的，所以遍历要在原来的树上进行，因为你不会也不能对原来的树有任何变动。
每次要进行树的调整时，将要调整的节点在复制树种找出来，在复制树上进行操作。
这意味着，最后每种情况都要用一棵复制树来生成。

以上，第一次写题解，意思不够明确，请见谅。

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
    Map<Integer,List<TreeNode>> map = new HashMap<>();

    public List<TreeNode> generateTrees(int n) {
        if (n == 0)
            return new ArrayList<TreeNode>();

        //初始化map
        TreeNode one = new TreeNode(1);
        List<TreeNode> list = new ArrayList<>();
        list.add(one);
        map.put(1, list);

        if (map.containsKey(n))
            return map.get(n);
        for (int i = 2;i<=n;i++){
            if (!map.containsKey(i))
                map.put(i,addTrees(map.get(i-1), i) );
        }
        return map.get(n);
    }


    //生成所有的新树
    public List<TreeNode> addTrees(List<TreeNode> trees,int n){
        List<TreeNode> curTrees = new ArrayList<>();
        TreeNode root,right,pre,cur,r,l;

        for (int i = 0;i<trees.size();i++){
            root = new TreeNode(n);
            pre = trees.get(i);
            root.left = pre;
            curTrees.add(root);
            for (right = trees.get(i).right;right!=null;right = right.right){
                cur = copyTree(trees.get(i));
                root = new TreeNode(n);
                /*root.left = right;
                pre.right = root;*/
                r = findNode(right.val, cur);
                l = findNode(pre.val,cur );
                root.left = r;
                l.right = root;
                curTrees.add(cur);
                pre = right;
            }
            cur = copyTree(trees.get(i));
            l = findNode(pre.val,cur );
            l.right = new TreeNode(n);
            curTrees.add(cur);

        }
        return curTrees;
    }

    //实现树的复制
    public TreeNode copyTree(TreeNode treeNode){
        TreeNode tree;
        tree = new TreeNode(treeNode.val);
        if (treeNode.right!=null)
            tree.right = copyTree(treeNode.right);
        if (treeNode.left!=null)
            tree.left = copyTree(treeNode.left);
        return tree;
    }

    //寻找复制树上的节点
    public TreeNode findNode(int val,TreeNode node){
        if (node.val == val)
            return node;
        if (node.val > val)
            return findNode(val,node.left );
        else
            return findNode(val,node.right );
    }

}


class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

```