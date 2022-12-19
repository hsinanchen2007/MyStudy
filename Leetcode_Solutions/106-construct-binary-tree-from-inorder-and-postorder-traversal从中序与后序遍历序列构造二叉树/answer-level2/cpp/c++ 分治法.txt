### 声明
&emsp;&emsp;&emsp;&emsp;本题与[#105](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)几乎一致，可以学会105然后自己敲一遍106以巩固提升。
&emsp;&emsp;&emsp;&emsp;与105两点区别：
1. 根结点遍历要从后序遍历数组最后一位开始，这是由后序遍历的顺序而定的。
2. `根右左`建树，因为是后序遍历数组确定根结点值且后序遍历数组倒序就是`根右左`，所以要`先右后左`。

&emsp;&emsp;&emsp;&emsp;其实，练习过105和106，可能更加理解为什么`前序+中序`or`后序+中序`会唯一确定二叉树，而`前序+后序`不能！简而言之，前/后序的功能为提供根结点值，而中序的功能为根据根结点值确定根结点索引以分治思想去递归建树。

<br/>
### 解题思路
&emsp;&emsp;&emsp;&emsp;还是给一例子吧～
>中序遍历 inorder = [9,3,15,20,7]
>后序遍历 postorder = [9,15,7,20,3]

&emsp;&emsp;&emsp;&emsp;如果这是一道选择填空甚至应用题，我们会怎么做？
1. 由后序遍历特点可知，根结点`root`是"吊车尾"，也就是`3`。
2. 根据`root`值找到中序遍历数组中的相应索引，这时由中序遍历特点可知，左子树位于根结点索引左侧，也就是`9`；右子树位于根结点索引右侧`15,20,7`。
3. 对左、右子树数组重复1、2步骤，直到数组为空
&emsp;&emsp;&emsp;&emsp;这就是我们日常做题的步骤，不难发现，其中蕴含着分治和递归的思想。简而言之，就是利用后序遍历得到根结点值去划分中序遍历左右子树，而后按`根、右、左`顺序递归建立二叉树。下面说两点细节：
1. 对于划分左右子树区间以及递归结束条件的确定，参考二分查找的查找区间细节。注意本文的左右指针设置为`l = 0, r = length`，即`[l...r)`左闭右开区间。
2. 如何确定后序遍历中根结点位置？(为什么自减就确定是下一个根结点？)一定要结合后序遍历本身特点(根结点是"吊车尾")，以及我们构建二叉树的顺序(根、右、左)。这就涉及到递归的流程(考虑栈的特点)，一定是等右子树建完再去建左子树。
&emsp;&emsp;&emsp;&emsp;我们一定要明确一点，那就是所谓的`先右后左`建树，是**根据后序遍历数组的特点而定的**，就像`#105`中，`先左后右`的建树顺序是由先序遍历数组的特点而决定的。
<br/>

### 代码
```
class Solution {
public:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int l, int r, int& pos_Index){
        if(l == r)
            return NULL;

        //通过后序遍历的根结点值获取其在中序遍历的索引
        int index_Val = postorder[pos_Index];
        int index = record.find(index_Val)->second;
        TreeNode* root = new TreeNode(index_Val);   //建立根结点
        pos_Index--;                                //寻找下一个根结点
        //根右左建树，因为后序遍历顺序左右根，反映到后序遍历数组上的倒序为根右左
        if(pos_Index >= 0){
            root->right = build(inorder, postorder, index + 1, r, pos_Index);
            root->left = build(inorder, postorder, l, index, pos_Index);
        }
            
        return root;
    
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0)
            return NULL;
        int n = inorder.size();
        //记录
        for(int i = 0; i < n; i++)
            record.insert(make_pair(inorder[i], i));  //(元素，索引))

        //根据后序遍历特点(左右根)得到根结点索引
        int pos_Index = n - 1;

        return build(inorder, postorder, 0, n, pos_Index);
    }

private:
    unordered_map<int,int> record;
};
```

<br/>

>如果有错误或者不严谨的地方，请务必给予指正，十分感谢。
>本人blog：<https://zhengguanyu.github.io>