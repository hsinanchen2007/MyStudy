### 解题思路
C# 分治法
使用分组后的最后一个数字作为当前子树的根节点，在当前分组的前Length-1个元素中找到一个索引，使得索引前后的数全部小于和大于子树的根节点数，如果找不到则认为不是二叉搜索树；
如果找到了Index，以此Index将当前分组再次划分，以此类推；

### 代码

```csharp
public class Solution {
    public bool VerifyPostorder(int[] postorder) {
        if (postorder.Length < 2) return true;
        return VerifyPostorder(postorder, postorder.Length - 1, 0, postorder.Length - 2);
    }

    public bool VerifyPostorder(int[] postOrder, int index, int start, int end)
    {
        if (start >= end) return true;
        var rootValue = postOrder[index];
        int leftIndex = start, rightIndex = end;
        // 寻找一个 Index 使 [start, Index] 和 (Index, end] 的数组分别全部小于和大于根节点数字
        while (leftIndex < rightIndex)
        {
            if (postOrder[leftIndex] < rootValue)
            {
                leftIndex++;
            }
            if (postOrder[rightIndex] > rootValue)
            {
                rightIndex--;
            }
            // 不存在这样的 Index
            if (postOrder[rightIndex] < rootValue && postOrder[leftIndex] > rootValue)
            {
                break;
            }
        }

        // 没有找到这样的 Index
        if (rightIndex > leftIndex)
            return false;

        // 找到了符合的 Index
        int rootIndex = leftIndex - 1;
        return VerifyPostorder(postOrder, rootIndex, start, rootIndex - 1) &&
                VerifyPostorder(postOrder, end, rootIndex + 1, end - 1);
    }
}
```