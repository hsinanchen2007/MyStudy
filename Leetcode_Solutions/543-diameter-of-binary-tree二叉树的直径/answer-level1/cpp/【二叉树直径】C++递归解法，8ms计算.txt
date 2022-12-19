### 解题思路
先把题里我遇到的坑说出来吧。。。
坑1."diameter of the tree"。第一次做题想看看大佬们的解题流程，在查看一些思路之后已经知晓了第一个坑，直径长度的关键是任意两个节点之间的距离，并不局限于路径必须经过根节点。所以看了大佬们的解析之后这个坑也是成功的避免。
坑2. "val" and "depth"。好吧我承认这真的是很弱智的错误，原因取决于以前遇到树结构问题的时候总是偷懒把val直接设定为树的高度，所以计算时很容易就读取到子树的高度数据进行计算。(偷懒总是要换的-_-||)，这个坑属于概念不明确，还是得把基础打牢啊。

把坑都踩完了，解题的思路也就明确了。
题目本身是很简单的，确实也对应了简单的难度标签，最简单偷懒的办法就是写一个递归(使用循环可以优化内存占用的情况)，不断算出每个节点的高度，最终将最大的直径值进行返回。

添加了一个私有成员变量"diameterMAX"，用于存储目前最大的diameter值，并且在遍历过程中不断比较替换，当递归结束的时候自然存储的就是整棵树的最大diameter值。

"RecursiveBody"作为整个递归的主体，采用一个后序遍历，向上一层返回本层的树高，因为在我的解题逻辑中需要先拿到左右子树的高度才能进行本层树高的计算。递归过程也就是最基础的后序遍历结构，当没有遍历到叶子节点时不断深入。(为了看起来简洁美观一点其实可以把leftDepth和rightDepth之后的计算过程抽象出来，使用一个私有函数进行处理)

计算的逻辑采用分支进行(if else一多真的看起来一头包，以后多多加强代码结构的优化)，每一个return作为一个分支逻辑的结束，虽然有5个return，但是其实严格来说只有4个逻辑分支。

每次需要处理的数据是depth和diameter，所以下面给出两个数据变量的计算方式。
![image.png](https://pic.leetcode-cn.com/fcc6bb15d4e331fa08bb79c10f1ba355356930be21849d5395d92e99b05b3a71-image.png)
定义中叶子节点的高度为0，以一个3节点组成的完全二叉树为例，从"2"到"3"的diameter值为以"2"节点作为根的树高+以"3"节点作为根的树高。
![image.png](https://pic.leetcode-cn.com/5c0ab6794f30c7b969d00d6dab7e370650390b3efd433669ec4434e67967e5b6-image.png)
抽象出来就是左右子树的高度，加上到左子树的树枝和到右子树的树枝，可以在5节点的完全二叉树中对照公式进行验证。
![image.png](https://pic.leetcode-cn.com/36b3ddf2d3a70c3bc4a2e0c5ae54a74fc8e64001ebb2f84844f37a56d2ca3f82-image.png)
搞清楚计算逻辑之后可以根据公式写分支了。

分支1.有两个子节点。其中由于需要返回本层树高，所以又进行了一次分支，选出左右子树最高的树高+1作为自己的高度。
分支2.只有左子节点。
分支3.只有右子节点。
分支4.没有子节点。
每层分支返回本层的高度，同时当"tempDiameter">"diameterMAX"时对"diameterMAX"值进行更新。

总结一下。
本题中的坑都是定义的理解问题，其实代码层面和公式层面都是很简单的，一个递归遍历代码，一个穷举公式就解决了。多多刷题提升吧。

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter(root);
        return this->diameterMAX;
    }
private:
    int diameterMAX = 0;//finall result, initial value=0

    int RecursiveBody(TreeNode* node){
        if( node == NULL )
            return 0;
                
        //get hight of child tree
        int leftDepth =  RecursiveBody(node->left);
        int rightDepth = RecursiveBody(node->right);

        if( node->left != NULL ){
            //have left child
            if( node->right != NULL ){
                //have two child//
                int tempDiameter = leftDepth + rightDepth + 2;
                if( tempDiameter > this->diameterMAX )
                    this->diameterMAX = tempDiameter;//change max fianll result
                //get hight
                if( leftDepth > rightDepth )
                    return leftDepth+1;
                else
                    return rightDepth+1;
                
            } else {
                //only have left child//
                if( leftDepth+1 > this->diameterMAX )
                    this->diameterMAX = leftDepth+1;
                return leftDepth+1;
            }
        } else if( node->right != NULL ){
            //only have right child//
            if( rightHight+1 > this->diameterMAX )
                    this->diameterMAX = rightHight+1;
                return rightDepth+1;
        } else {
            //no child//
            return 0;
    }
    
    }
};

```