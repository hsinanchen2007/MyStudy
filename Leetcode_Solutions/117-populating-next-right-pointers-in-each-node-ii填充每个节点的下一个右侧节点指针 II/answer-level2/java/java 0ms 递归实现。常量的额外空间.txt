额，这个题首先我觉得主要是不使用额外空间，然后官方题解我个人觉得不太好理解，所以自己写了下。
首先这个题和上个题，除了不完美就没别的了，但是感觉不能沿用上面的代码了，因为判断上一个节点的下一个节点可能就轮空了，所以大体思路是一样的，不过要多加很多判断和细节。
首先不能单纯的取根节点的下一个节点来判断是否有下一个指向next了。我贴张草图（我随手画，你对付看）：
![image.png](https://pic.leetcode-cn.com/f904e63d1e1556a051dfe6569fa977112a48596c3de74e059408e457540bafe6-image.png)

所以这个关于下一个节点我是专门做了个方法。
其次就是遍历顺序，一定要先右后左，原因我再贴个图：
![草图](https://pic.leetcode-cn.com/8dc9c18de3e7ff2348ef2bb9a409ea94ec73c8f00e9a294694ccc1bf2ce3f7fc-file_1583597918430)

- 如图所示，第一个递归，把标1的指向指向好了。
- 第二次递归，根节点变成了紫色节点，然后把两个红色节点的指向做好了，也就是标做2的线。
- 第三次递归，先左后右的话，左边红色节点作为根节点，吧两个蓝色节点指向做好了。
- 重点来了，第四次递归，因为左边遍历完了，该右节点，所以根节点是右边红色节点（叶子节点直接pass了），这个时候两个黄节点之间的线可以连，但是第二黄色节点从父节点找到的那个节点没有子节点，再往下找线没连呢。。。所以就自动以为没节点了。所以错误就来了。
- 
额，说这么多是为了解释为什么必须先递归右节点而不是常规的左节点。
感觉注意点就这两个，最后贴完整代码：
```
class Solution {
    public Node connect(Node root) {
        if(root==null) return root;
        if(root.right!=null){
            if(root.left!=null) root.left.next = root.right;
            if( root.next!= null){//右节点连下一个节点
                root.right.next = nextNode(root.next);
            }
        }else if(root.left!=null){
            if( root.next!= null){//没有右节点则直接左节点连下一个节点
                root.left.next = nextNode(root.next);
            }
        }
        connect(root.right);
        connect(root.left);        
        return root;
    }
    //获取下一个节点
    private Node nextNode(Node node) {
        while (node != null) {
            if (node.left != null) {
                return node.left;
            }
            if (node.right != null) {
                return node.right;
            }
            node = node.next;
        }
        return null;
    }
}
```
