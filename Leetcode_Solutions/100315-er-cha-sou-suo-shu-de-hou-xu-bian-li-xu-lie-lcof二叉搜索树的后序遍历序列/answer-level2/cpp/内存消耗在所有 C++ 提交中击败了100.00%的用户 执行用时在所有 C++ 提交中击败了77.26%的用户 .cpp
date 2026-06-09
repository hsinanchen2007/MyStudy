### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了77.26%的用户
内存消耗 :9.3 MB, 在所有 C++ 提交中击败了100.00%的用户
别看他们的，花里胡哨，花拳绣腿，毫无意义
直接用二叉搜索树的性质，根节点比左子节点都大，比右子节点都小
后序遍历：根节点全在树遍历的最后一个
1.从后往前找到左子节点（第一个比根节点小的）
2.从第一个左子节点往前找，如果有比根节点大的，就说明错了（因为根节点比左子节点都大）
3.递归左子树&&右子树
4.如果数组空了，就说明全没错，返回true

### 代码

```cpp
class Solution {
public:
    bool helper(vector<int>& postorder,int start,int end)
    {
        int right=start;
        if(start>=end)
            return true;
        for(int i=end-1;i>=start;i--)
        {
            if(postorder[i]<postorder[end])
            {
                right=i+1;
                break;
            }
        }
        for(int i=start;i<right;i++)
        {
            if(postorder[i]>postorder[end])
                return false;
        }
        return helper(postorder,start,right-1)&&helper(postorder,right,end-1);
    }

    bool verifyPostorder(vector<int>& postorder) 
    {
        if(postorder.empty())
            return true;
        return helper(postorder,0,postorder.size()-1);
    }
};
```