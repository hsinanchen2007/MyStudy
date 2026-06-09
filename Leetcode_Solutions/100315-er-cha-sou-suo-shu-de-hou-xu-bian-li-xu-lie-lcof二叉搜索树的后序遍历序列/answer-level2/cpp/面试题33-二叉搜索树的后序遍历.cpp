### 解题思路
探索规律，举个例子`[1,3,2,6,5]`
```
     5
    / \
   2   6
  / \
 1   3
```
- 后序遍历的最后一个是根节点，二叉搜索树的左子树都比根节点小，右子树都比跟节点大。
- 挨个与5比较，小于5的都是左，大于5的都是右。
- 关键在检测右子树的过程中，如果出现了比5小的，那就不符合二叉搜索树。
- 如果没问题继续检查子树是否满足。
- 所以方法就是递归了。
- 需要传入起始`start`和结束`end`位置，返回值是bool，终止条件是如果起始`start`和结束`end`位置指到一起了，也就是到叶节点了就返回true了。
- 注意：输入为空，或者只有1、2个节点，那肯定都是满足二叉搜索树的。


### C++代码

```cpp
class Solution {
public:
    vector<int> postorderCopy;
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size()<3)
            return true;
        postorderCopy = postorder;
        return helper(0,postorderCopy.size()-1);
    }
    bool helper(int start,int end)
    {
        if(start>=end)
            return true;
        int i = start;
        while(postorderCopy[i] < postorderCopy[end])
            ++i;
        int bound = i;
        while(postorderCopy[i] > postorderCopy[end])
            ++i;
        if(i != end)
            return false;
        else
        {
            return helper(start,bound-1) && helper(bound,end-1);
        }
}
};
```