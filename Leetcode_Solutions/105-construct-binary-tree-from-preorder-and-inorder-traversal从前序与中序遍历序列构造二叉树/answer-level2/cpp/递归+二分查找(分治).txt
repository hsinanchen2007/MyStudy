### 解题思路
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;还是给一个例子吧！
>前序遍历 preorder = [3,9,20,15,7]
>中序遍历 inorder = [9,3,15,20,7]


&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;如果这是一道选择填空甚至应用题，我们会怎么做？

 1. 由前序遍历特点可知，根结点`root`是"排头兵"，也就是`3`。
 2. 根据`root`值找到中序遍历数组中的相应索引，这时由中序遍历特点可知，左子树位于根结点索引左侧，也就是`9`；右子树位于根结点索引右侧`15,20,7`。
 3. 对左、右子树数组重复1、2步骤，直到数组为空
 
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;这就是我们日常做题的步骤，不难发现，其中蕴含着分治和递归的思想。分治部分可以参考二分查找算法，其实最后实现下来没差太多～简而言之，就是利用前序遍历得到根结点值去中序遍历数组中划分左右子树区间，而后按`根、左、右`顺序递归建立二叉树。下面说三个细节：
1. 如何通过前序遍历的根结点值找到对应中序遍历索引？当然可以通过遍历中序数组查找到根结点值。不过，为了降低执行用时，本文采用`unordered_map`提前记录中序遍历键值对(亲自测试，从20ms降到12ms~)。
2. 对于划分左右子树区间以及递归结束条件的确定，参考二分查找的查找区间细节。注意本文的左右指针设置为`l = 0, r = length`，即`[l...r)`左闭右开区间。
3. 如何确定先序遍历中根结点位置？(为什么自增就确定是下一个根结点？)一定要结合先序遍历本身特点(根结点是"排头兵")，以及我们构建二叉树的顺序(根、左、右)。这就涉及到递归的流程(考虑栈的特点)，一定是等左子树建完再去建右子树。所以这样自增是么问题哒。如果是根右左建树，显然自增不管用了，得通过中序遍历数组找右子树"排头兵"，忒麻烦了~~
<br/>
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;最后，还是求一个非递归解法吧🤔
<br/>

### 代码

```cpp
class Solution {
public:
    //分治思想，参考二分查找
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //记录
        for(int i = 0; i < inorder.size(); i++)
            record.insert(make_pair(inorder[i],i));          //(结点值，结点索引)
        return build(preorder, inorder, 0, inorder.size());  //[l...r)左闭右开,用于递归结束条件
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l, int r){
        if(l == r)
            return NULL;
        
        int root_Val = preorder[root_Pre];         //从先序遍历数组中获取当前根结点值
        int index = record.find(root_Val)->second; //再从中序遍历数组中找到当前根结点的索引处
        root_Pre++;         //为什么自增就确定是下一个根结点？
                            //一定要结合先序遍历本身特点(根结点是"排头兵")，以及我们构建二叉树的顺序(根、左、右)
                            //这就涉及到递归的流程(考虑栈的特点)，一定是等左子树建完再去建右子树。
                            //所以这样自增是么问题哒。如果是根右左建树，显然自增不管用了，得通过中序遍历数组找右子树"排头兵"，忒麻烦了。。。
        TreeNode* root = new TreeNode(root_Val);   //建立根结点
        root->left = build(preorder, inorder, l, index);       //注意是[l...r)左闭右开哦！
        root->right = build(preorder, inorder, index + 1, r);  //构成一个完整、无重复的区间

        return root;
    }

private:
    int root_Pre = 0;               //根结点在先序遍历的索引位置
    unordered_map<int,int> record;  //记录各结点在中序遍历数组的索引，用于通过根结点划分左右子树区域
};
```