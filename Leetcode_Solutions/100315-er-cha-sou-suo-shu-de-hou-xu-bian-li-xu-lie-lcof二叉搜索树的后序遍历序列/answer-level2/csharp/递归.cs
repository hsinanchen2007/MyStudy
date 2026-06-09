### 解题思路
数组的最后一个为根节点，所以根节点前面的区间为左右子树集合，比如1,3,2,6,5中，5为根1，3，2为左子树，6为右子树。所有又可以分成几个情况：
1. 根节点前都比根节点大 --> [右子树元素] 根节点
2. 根节点前都比根节点小 --> [左子树元素] 根节点
3. 根节点前，前半部分比其小，后半部分比其大 --> [[右子树元素][左子树元素]]根节点
4. 非1，2，3情况即不满足二叉搜索树条件

满足1，2，3的情况下继续递归查看子树是否符合二叉搜索数要求。


### 代码

```csharp
public class Solution {
    public bool VerifyPostorder(int[] postorder) {
        if(postorder == null)
        {
            return false;
        }

        return Helper(postorder, 0, postorder.Length - 1);
    }

    private bool Helper(int[] postorder, int start, int end)
    {
        //递归终止条件
        if(start >= end)
        {
            return true;
        }
        //当前根节点
        int rootValue = postorder[end];
        //index用来标识第一个大于根节点的索引
        int index = 0;
        for(; index < end; index++)
        {
            if(postorder[index] > rootValue)
            {
                break;
            }
        }

        int j = index;
        for(; j < end; j++)
        {
            //如果在右子树的区间出现了比根节点小的节点，则返回false
            if(postorder[j] < rootValue)
            {
                return false;
            }
        }

        //只有左子树或右子树
        if(index == start || index == end)
        {
            return Helper(postorder, start, end - 1);
        }else
        {
            //同时有右子树和左子树
            return Helper(postorder, start, index - 1) && Helper(postorder, index, end);
        }
    }
}
```