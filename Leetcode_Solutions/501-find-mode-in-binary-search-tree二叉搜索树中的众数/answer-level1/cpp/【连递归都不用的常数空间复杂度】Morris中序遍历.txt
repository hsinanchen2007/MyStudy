### 解题思路
#### 核心思路
本题中二叉搜索树的中序遍历结果是一个非递减的序列，所以进行中序遍历，通过比较前一个元素`pre`和当前元素`cur`的值确定是否执行操作，具体如下
- 如果`pre`不存在，说明目前是在第一个元素的位置，所以将计数置为1，并添加当前元素进入结果数组
- 如果`pre`存在，先分两种情况计数
    - 如果`pre->val == cur->val`：说明当前值和前一个相同，计数加1,`count++`
    - 如果`pre->val ！= cur->val`：说明当前值和前一个不同，计数置为1,`count = 1`
    

在得到计数`count`后，与当前最大计数`maxnum`比较：
- 如果`count > maxnum `: 更新`maxnum`，清空结果数组`res`，添加`cur->val`
- 如果`count == maxnum` ：只需添加`cur->val`

以上是具体的比较过程，代码片段如下：
```c++
if(pre && pre->val == cur->val) count++;
else count = 1;

if(count > maxnum){
    maxnum = count;
    res.clear();
    res.push_back(cur->val);
}else if(count == maxnum){
    res.push_back(cur->val);
}
```

#### 进阶->Morris中序遍历

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
    vector<int> findMode(TreeNode* root) {
        TreeNode *cur, *pre;
        cur = root;
        pre = NULL;
        int count = 0, maxnum = 0;
        vector<int> res;
        while(cur){
            if(cur->left == NULL){// 左子树为空时，直接比较，然后进入右子树
                if(pre && pre->val == cur->val) count++;
                else count = 1;

                if(count > maxnum){
                    maxnum = count;
                    res.clear();
                    res.push_back(cur->val);
                }else if(count == maxnum){
                    res.push_back(cur->val);
                }

                pre = cur;
                cur = cur->right;
            }else{// 进入左子树
                // 找到cur的前驱结点，分两种情况
                // 1、cur的左子结点没有右子结点，那cur的左子结点就是前驱
                // 2、cur的左子结点有右子结点，就一路向右下，走到底就是cur的前驱
                TreeNode* preceesor = cur->left;
                while(preceesor->right && preceesor->right != cur){
                    preceesor = preceesor->right;
                }

                // 前驱已经指向自己了，直接比较，然后进入右子树
                if(preceesor->right == cur){
                    if(pre && pre->val == cur->val) count++;
                    else count = 1;

                    if(count > maxnum){
                        maxnum = count;
                        res.clear();
                        res.push_back(cur->val);
                    }else if(count == maxnum){
                        res.push_back(cur->val);
                    }

                    preceesor->right = NULL;
                    pre = cur;
                    cur = cur->right;
                }else{ // 前驱还没有指向自己，说明左边还没有遍历，将前驱的右指针指向自己，后进入前驱
                    preceesor->right = cur;
                    cur = cur->left;
                }
            }
        }
        return res;
    }
};
```


#### 参考资料
[望月从良 《面试算法：二叉树的Morris遍历算法》](https://www.jianshu.com/p/484f587c967c)
[COOLUCAS 中序遍历 + 双指针找逆序对 + Morris遍历实现常数复杂度](https://leetcode-cn.com/problems/recover-binary-search-tree/solution/zhong-xu-bian-li-shuang-zhi-zhen-zhao-ni-xu-dui-mo/)