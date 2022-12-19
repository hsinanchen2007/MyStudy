### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {

        //有零个或一个结点，返回真
        if(postorder.size()<=1)
            return true;

        //返回递归结果
        return isBST(postorder,0,postorder.size()-1);

    }
    bool isBST(vector<int>& postorder,int start,int end)
    {
        //传入的子树只有零个或一个结点，返回真
        if(end-start<=1)
            return true;

        //左右子树的起点，都初始为传入的start
        int l1=start;
        int l2=start;

        //postorder[end]是根节点，寻找首个大于根节点的值
        //该值开始到end-1即为右子树
        while(postorder[l2]<postorder[end])
            l2++;

        //右子树中存在小于根节点的值，返回假
        //注意这个判断要比下面的if判断先进行，因为有l2==start的情况
        for(int i=l2;i<end;i++)
        {
            if(postorder[i]<=postorder[end])
                return false;
        }

        //l2==end，没有右子树，则递归判断其左子树是否二叉搜索树
        //l2==start，没有左子树，则递归判断其右子树是否二叉搜索树
        if(l2==end||l2==start)
            return isBST(postorder,start,end-1);
        
        //既有左子树又有右子树，则判断其左右子树是否同时为二叉搜索树
        return isBST(postorder,l1,l2-1)&&isBST(postorder,l2,end-1);
    }
};
```