### 分析：
1. 由二叉搜索树的定义可知：中序遍历即为有序序列。则初步思路是采用递归的中序遍历
2. 本题的特殊之处就在于怎么修改前驱节点：**定义全局辅助节点 pre，让它来帮助记忆前驱节点即可**

### 算法思路：
##### 递归：
1. 遍历左子树
2. 当前节点的 letf指向前驱节点，前驱节点的 right指向当前节点；更新前驱节点为当前节点
3. 遍历右子树
* 结束条件：当前节点为 null

### 代码

```java []
class Solution {
    Node pre=null,head=null,tail=null;
    public Node treeToDoublyList(Node root) {
        if(root==null){return root;}
        //处理前驱节点
        inOrder(root);
        //处理头尾节点
        head.left=tail;
        tail.right=head;
        return head;
    }
    void inOrder(Node cur){
        if(cur==null){return;}
        inOrder(cur.left);
        //左子树已经遍历过，可以修改当前left指针
        if(pre!=null){
            pre.right=cur;
            cur.left=pre;
        }else{head=cur;} //只有头节点没有前驱
        pre=cur;
        tail=cur; //不断更新尾节点
        inOrder(cur.right);
    }
}
```