### 解题思路
此处撰写解题思路

设数组长度为n
因为是后序遍历，数组的最后一个数肯定是根结点的值(rootVal)
用rootVal把数组前面的n - 1个数分成左右两部分
左部分必须小于rootVal，否则返回false
右部分必须大于rootVal，否则返回false
如果左右部分都满足上面条件，分别递归检查左右部分是不是二叉搜索树，只要有一个不是就返回false

### 代码

```csharp
public class Solution {
    public bool VerifyPostorder(int[] postorder) {
        return isSearchTree(postorder, 0, postorder.Length - 1);
    }

    bool isSearchTree(int[] postorder, int low, int high)
    {
        if(low >= high)
        {
            return true;
        }

        int rootVal = postorder[high--];
        int middle = high;
        for(; middle >= low; middle--)
        {
            if(postorder[middle] < rootVal)
            {
                break;
            }
        }

        for(int i = low; i < middle; i++)
        {
            if(postorder[i] > rootVal)
            {
                return false;
            }
        }

        if(!isSearchTree(postorder, low, middle))
        {
            return false;
        }

        if(!isSearchTree(postorder, middle + 1, high))
        {
            return false;
        }

        return true;
    }
}
```