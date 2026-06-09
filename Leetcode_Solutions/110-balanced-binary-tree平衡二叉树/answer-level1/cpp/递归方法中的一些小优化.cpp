
## 递归函数的功能，在逻辑上需要以下的步骤：

1. 检测左子树的平衡性、高度
2. 检测右子树的平衡性、高度
3. 对比两侧子树的高度差
4. 当两侧子树都各自平衡，并且高度差小于等于1时，即可认为当前节点引出的树也平衡

## 实现细节

### 问题1：我们想用一个递归函数，同时返回平衡性和高度的信息
- 乍看之下的想法是，用Python、或者C++用tuple等技术，返回两个值，一个bool型判断平衡性，一个int型给出高度信息
- 分析一下可以发现，其实如果平衡性为false，那么我们也就不关心高度值了，反正最后结果肯定是不平衡了。所以我们可以把int型的负数域利用起来（因为高度值一定为自然数），于是不平衡时直接给出负数值，平衡则给出自然数（代表高度值）。由此可见，我们还是只需要一个整型返回值就够了

### 问题2：如何减少不必要的递归调用与计算
上面提到了平衡性的判断分为四步：检测左子树、检测右子树、计算高度差、返回较大的那个高度。但是在不平衡的情况下，这四步不会完全走完，前三步任何一个条件一旦不满足，就不必继续接下来的步骤。因此我们分别依次执行前三个步骤，测到哪一个步骤不满足就立刻返回负数值

## Code

```
class Solution {
public:

    bool isBalanced(TreeNode* root) {
        /* 
           How to bind height info with balance info?
           If subtree is balanced, we get its height
           If subtree is unbalanced, we get -1
        */
        return TreeHeight(root) != -1;
    }

    int TreeHeight(TreeNode* root) {
        // Base case
        if(!root) return 0; // Empty subtree: define the ground height as 0
        if(!root -> left && !root -> right) return 1; // Leaf node: define as 1

        // If left subtree is unbalanced, we don't need to compute for right subtree
        int left_subtree_height = TreeHeight(root -> left);
        if(left_subtree_height < 0) return -1;

        // If right subtree is unbalanced, we don't need to compare subtrees' heights
        int right_subtree_height = TreeHeight(root -> right);
        if(right_subtree_height < 0) return -1;

        // Verify the balance condition
        if(abs(left_subtree_height - right_subtree_height) > 1) return -1;
        
        // Return max depth as the height only when both subtrees are balanced and their height difference <= 1
        return max(left_subtree_height, right_subtree_height) + 1;
    }

};
```