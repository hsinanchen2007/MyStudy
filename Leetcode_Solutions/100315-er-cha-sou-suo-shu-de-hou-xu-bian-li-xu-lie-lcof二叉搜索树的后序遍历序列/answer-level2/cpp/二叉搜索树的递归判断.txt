- 二叉搜索树的特点：中序遍历为递增序列
- 二叉树后序遍历的特点：最后一个数字一定是根结点
- 根据以上两点，先找当前树的根节点，再根据左右子树划分，找到左右子树的截止点，递归判断左右子树是否为二叉搜索树

```C++ []
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        // 定义起始点，便于数组分段判断
        int left = 0;
        int right = postorder.size()-1;
        return ispost(postorder, left, right);
    }

    bool ispost(vector<int>& postorder, int left, int right)
    {
        // 递归的终止条件
        if(right - left <= 2)
            return true;
        int mid = left;
        // 找到二叉搜索树的左子树的终点
        while(postorder[mid] < postorder[right])
            mid++;
        // 判断右子树是否满足都大于根结点的特性，不满足则一定不是二叉搜索树
        for(int j = mid; j<right; j++)
        {
            if(postorder[j] < postorder[right])
                return false;
        }
        // 满足右子树的特性后，设置新的起始点，递归判断左右子树
        return ispost(postorder, left, mid-1) && ispost(postorder, mid, right-1);
    }
};
```

