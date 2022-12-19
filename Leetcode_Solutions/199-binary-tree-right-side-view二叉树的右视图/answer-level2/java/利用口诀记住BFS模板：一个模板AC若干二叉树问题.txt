
先说模板的口诀：

    判空建器根入列，容器非空取其长；
    其长非零根出列，左右非空添列中；

这个模板，其实就是二叉树的层序遍历模板，或说BFS模板，
如果你知道更多的算法模板，或是优质的算法书籍，欢迎在评论区告诉我。

下面逐句的解析口诀：
    
$1、$ 判空建器根入列：“判空”是指`if(root==null)`，“建器”是指创建容器，此处使用`queue`，若是换成`stack`稍作修改便是另一套模板了，“根入列”是指`queue.add(root)`，
    
$2、$ 容器非空取其长：“容器非空”是指`while(!queue.isEmpty())`，“取其长”是说获取容器实际存储元素的个数，`cnt=queue.size()`，我称其长度，
    
$3、$ 其长非零根出列：“其长非零”显然是指`while(cnt>0)`，“根出列”是指“node=queue.poll()”，
    
$4、$ 左右非空添列中：“左右非空”显然是对`node.left`与`node.right`判空，不为空则加入容器之中，


具体的代码如下，说是模板倒不如说是[母题](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)：
```java
public List<List<Integer>> levelOrder(TreeNode root) {
    int cnt;
    TreeNode node;
    List<List<Integer>> res= new LinkedList<>();
    if(root==null){
        return res;
    }
    Queue<TreeNode> queue = new LinkedList<>();
    queue.offer(root);
    while(!queue.isEmpty()){
        cnt=queue.size();
        List<Integer> tmp = new LinkedList<>();
        while(cnt>0){
            node=queue.poll();
            if(node.left!=null)queue.offer(node.left);
            if(node.right!=null)queue.offer(node.right);
            tmp.add(node.val);
            cnt--;
        }
        res.add(tmp);
    }
    return res;
}
```





我们要开始利用这个模板搞事情了！    
对于[本题](https://leetcode-cn.com/problems/binary-tree-right-side-view/)来说，
一个比较简单的思路就是使用层序遍历，并只保留每层最后一个节点的`val`，
模板里面，
我们tmp是一个列表，但是现在我们不需要全部保存，
我们只要留住最后一个元素即可，
因此,直接在开头声明`int tmp`即可。

```java
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        int cnt=0,tmp=0;
        TreeNode node;
        List<Integer> res = new LinkedList<>();
        if(root==null){
            return res; 
        }
        Queue<TreeNode> queue=new LinkedList<>();
        queue.add(root);
        while(!queue.isEmpty()){
            cnt=queue.size();
            while(cnt>0){
                node=queue.poll();
                if(node.left!=null)queue.offer(node.left);
                if(node.right!=null)queue.offer(node.right);
                cnt--;
                tmp=node.val;
            }
            res.add(tmp);
        }
        return res;
    }
}
```


再看一道母题改编，二叉树层序从下往上遍历，其实只需要修改`res`添加`tmp`那个步骤即可。
```java
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        int cnt=0;
        TreeNode node;
        List<List<Integer>> res = new LinkedList<>();
        if(root==null){
            return res;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while(!queue.isEmpty()){
            cnt=queue.size();
            LinkedList<Integer> tmp = new LinkedList<>();
            while(cnt>0){
                node=queue.poll();
                if(node.left!=null)queue.offer(node.left);
                if(node.right!=null)queue.offer(node.right);
                tmp.add(node.val);
                cnt--;
            }
            res.add(0,tmp);
        }
        return res;
    }
}
```



再看这一道，[N叉树遍历](https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/)，只需要对‘左右非空添列中’这个步骤稍作修改即可。
```java
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
```

```java
class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        int cnt=0;
        Node node;
        List<List<Integer>> res = new LinkedList<>();
        if(root==null){
            return res;
        }
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        while(!queue.isEmpty()){
            cnt=queue.size();
            LinkedList<Integer> tmp = new LinkedList<>();
            while(cnt>0){
                node=queue.poll();
                tmp.add(node.val);
                for(int i=0;i<node.children.size();i++){
                    queue.offer(node.children.get(i));
                }
                cnt--;
            }
            res.add(tmp);
        }
        return res;
    }
}
```




再看这一道[二叉树的锯齿形遍历](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/)，大同小异，套上模板，再对每一层`level`分类讨论即可，从零开始计数，奇数层需要反转，置于反转，至于反转，每次插入元素都在链表的头部插入元素即可实现反转的效果。
```
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        int cnt=0;
        int level=0;
        TreeNode node;
        List<List<Integer>> res = new LinkedList<>();
        if(root==null)
            return res;
        Queue<TreeNode> queue=new LinkedList<>();
        queue.add(root);
        while(!queue.isEmpty()){
            cnt=queue.size();
            List<Integer> tmp = new LinkedList<>();
            while(cnt>0){
                node=queue.poll();
                if(node.left!=null)queue.offer(node.left);
                if(node.right!=null)queue.offer(node.right);
                if((level&1)==1) 
                    tmp.add(0,node.val);
                else 
                    tmp.add(node.val);
                cnt--;
            }
            level++;
            res.add(tmp);
        }
        return res;
    }
}
```






以上内容都是我自己一个人总结的，且当抛转引玉。

刷题的过程看过一些题解，隐隐之间似乎发现有一些相似的地方，便将其整合、总结，鄙人是一位普通学生，信息渠道不宽。当然，我建议先自己画图理解一下再来阅读下面的内容，不然仅仅是记住了模板而不真正理解，会有很多意向不到的麻烦。

如果哪天有空，再补一个图吧！

最后，如果发现有错漏或是不足之处还请指出。