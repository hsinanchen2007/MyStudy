### 解题思路
首先通过中序遍历可以将二叉搜索树可以转化为有序表这一点你必须知道，否则建议回炉重学二叉搜索树。

然后就是怎样漂亮的完成**就地**转换的问题。

比较巧妙的做法是用一个虚拟头结点+一个全局量：
1. 首先中序遍历的思路是极其清晰的，只要按照中序遍历的顺序访问必然就能得到正确的结果。那么使用一个全局量currNode是最方便的方法。
2. 对于边界问题，一个虚拟的头结点会给你极大地帮助，可以避免代码中出现难看的边界条件判断。
3. 记得处理空树的情况。
4. 代码采用了递归的中序遍历的方式，这样可以清晰地看清解题思路。如果想改成迭代模式，将访问节点的三行代码套入非递归中序遍历的模板即可。

##### 
##### 执行用时 : 4 ms  , 在所有 C++ 提交中击败了98.46%的用户
##### 内存消耗 : 8.9 MB, 在所有 C++ 提交中击败了100.00%的用户


### 代码

```cpp
class Solution {
    Node *currNode;
public:
    Node* treeToDoublyList(Node* root) {
        Node dummyHead(0, 0, root);
        currNode = &dummyHead;
        if(root)
        {
            inOrdTra(root);
            currNode->right = dummyHead.right;
            dummyHead.right->left = currNode;
        }
        return dummyHead.right;
    }
    void inOrdTra(Node *t)
    {
        if(t)
        {
            inOrdTra(t->left);
            
            currNode->right = t;
            t->left = currNode;
            currNode = t;
            
            inOrdTra(t->right);
        }
    }
};
```