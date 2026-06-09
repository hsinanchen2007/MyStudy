### 解题思路

本题使用树的**中序遍历**，利用**Morris遍历**方法，实现常数空间复杂度

#### 中序遍历 + 双指针找逆序对
二叉搜索树的中序遍历结果可以等效于一个升序数组
因此先用数组举例，如果原始的二叉搜索树为  
`1, 2, 3, 4, 5`  
如果将其中`2,4`两个元素进行交换，变成
`1, 4, 3, 2, 5`
那么我们可以使用双指针的方法，检查这个数组里的逆序对，将逆序对找出来就可以解决问题
观察数组
- 第一对逆序对`4, 3`，是索引小的那个是被交换元素
- 第二对逆序对`3, 2`，是索引大的那个是被交换元素
所以我们在遇到逆序对的时候，如果是第一次遇见，则存储索引小的那个，如果不是，则存储索引大的那个
```c++
if(pre != NULL && cur->val < pre->val){
    if(s1 == NULL) s1 = pre;  // 索引小的已经找到，就不再改变
    s2 = cur;
}
```
为什么这里`s2`用的不是`else`？
因为存在两个相邻元素交换的情况，所以我们在第一次遇见的把索引大的那个也存下来
- 如果后面没有逆序对了，那就是这一对
- 如果后面还有逆序对，会覆盖`s2`(因为有`if`判断，所以`s1`不会被覆盖)

#### Morris遍历
通过前面的分析，使用递归的方法可以很容易地完成本题。  

首先明确：在二叉搜索树中，如果一个结点有前驱结点，那么前驱结点的右指针只有两种情况（可以自己找两个二叉搜索树验证一下，此处不再证明）
- 是空的
- 是这个结点本身（即前驱是它的父结点）

所以我们可以把**前驱结点的右指针**这一特性利用起来，从而降低空间复杂度

Morris遍历算法的步骤如下：

检查当前结点的左孩子:
- 如果当前结点的左孩子为空，说明要不没有前驱，要不前驱是它的父结点，所以进行检查，然后进入右孩子。
- 如果当前结点的左孩子不为空，说明左子树里肯定有它的前驱，那就找到这个前驱
    - 如果前驱结点的右孩子是空，说明还没检查过左子树，那么把前驱结点的右孩子指向当前结点，然后进入当前结点的左孩子。
    - 如果当前结点的前驱结点其右孩子指向了它本身，说明左子树已被检查过，就直接进行检查，然后把前驱结点的右孩子设置为空，恢复原树，再进入右孩子。

Morris代码框架
```c++
while(cur){
    if(cur->left == NULL){// 左子树为空时，直接比较，然后进入右子树
        /*************
        /*  进行你的操作
        *************/
        pre = cur;
        cur = cur->right;
    }else{// 进入左子树
        /*************
        /* 找cur的前驱结点，找到后分两种情况
        /*   1、cur的左子结点没有右子结点，那cur的左子结点就是前驱
        /*   2、cur的左子结点有右子结点，就一路向右下，走到底就是cur的前驱
        *************/
        TreeNode* preceesor = cur->left;
        while(preceesor->right && preceesor->right != cur){
            preceesor = preceesor->right;
        }

        // 前驱已经指向自己了，直接比较，然后进入右子树
        if(preceesor->right == cur){
            /*************
            /*  进行你的操作
            *************/
            preceesor->right = NULL; // 断开连接，恢复原树
            pre = cur;
            cur = cur->right;
        }else{ // 前驱还没有指向自己，说明左边还没有遍历，将前驱的右指针指向自己，后进入前驱
            preceesor->right = cur;
            cur = cur->left;
        }
    }
}
```
对Morris遍历算法，末尾有我的参考文献，写得很好，大家可以看一下，有助于理解

#### 复杂度分析
时间复杂度：每个结点访问了2次，因此时间复杂度为$O(n)$
空间复杂度：只使用了常数空间，因此空间复杂度为$O(1)$

### 代码

```cpp
class Solution {
public:
    // s1 存小索引那个结点，s2存大索引那个结点，pre存前驱结点
    TreeNode *s1 = NULL, *s2 = NULL, *pre = NULL;
    void recoverTree(TreeNode* root) {
        TreeNode* cur = root;  // 游标
        while(cur != NULL){           
            if(cur->left != NULL){  // 进入左子树
                // 找到cur的前驱结点，分两种情况
                // 1、cur的左子结点没有右子结点，那cur的左子结点就是前驱
                // 2、cur的左子结点有右子结点，就一路向右下，走到底就是cur的前驱
                TreeNode* predecessor = cur->left;
                while(predecessor->right != NULL && predecessor->right != cur){
                    predecessor = predecessor->right;
                }

                // 前驱还没有指向自己，说明左边还没有遍历，将前驱的右指针指向自己，后进入前驱
                if(predecessor->right == NULL){
                    predecessor->right = cur;
                    cur = cur->left;
                }else{
                    // 前驱已经指向自己了，直接比较是否有逆序对，然后进入右子树
                    if(pre != NULL && cur->val < pre->val){
                        if(s1 == NULL) s1 = pre;
                        s2 = cur;
                    }
                    pre = cur;
                    predecessor->right = NULL;
                    cur = cur->right;
                }
            }else{  // 左子树为空时，检查是否有逆序对，然后进入右子树
                if(pre != NULL && cur->val < pre->val){
                    if(s1 == NULL) s1 = pre;
                    s2 = cur;
                }
                pre = cur;
                cur = cur->right;
            }
        }
        // 进行交换
        int t = s1->val;
        s1->val = s2->val;
        s2->val = t;
        return;
    }
};
```
参考资料：
[望月从良 《面试算法：二叉树的Morris遍历算法》](https://www.jianshu.com/p/484f587c967c)