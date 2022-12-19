### 解题思路
链表的处理确实很麻烦，我们选择牺牲空间的方法来换取时间的效率。
创建一个数组，保存所有链表的元素。
接下来就是二分法，由于二叉搜索树的平衡的，所以每个父节点都是当前元素范围内的中位数。
然后二分，每一次都一分为二，然后递归。
这样就能保证构造出来的二叉搜索树是平衡的。
仅供参考，还希望大佬们多多交流嘻嘻
![image.png](https://pic.leetcode-cn.com/d1386a03fe4c9aaab89ed2c9cc80c76a45f00aa3984fd49ab5e1070233d9a9a6-image.png)


### 代码

```cpp
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> tmp;
        while(head!=NULL)
        {
            tmp.push_back(head->val);//保存链表所有元素
            head=head->next;
        }
        TreeNode *root=new TreeNode(0);//根节点
        if(tmp.size()!=0)dfs(root,tmp,0,tmp.size()-1);//链表不为空
        else return NULL;//链表为空
        return root;
    }
    void dfs(TreeNode *root,vector<int> &tmp,int low,int high)
    {
        
        if(high-low==1)
        {
          /*范围容量是2，这里为什么是2呢？
          因为无论链表的长度为多少，二分法的过程中，最后肯定会细化成容量为1和2的子数组
          容量为1和为2的子数组处理之后就到了树的底部了，       
          这里是处理二的，而处理容量为1的过程在后面*/
            root->left=new TreeNode(tmp[low]);//小的构建在左节点
            root->val=tmp[high];//大的构建在子树的根节点
            return ;//二叉树到底了，返回
        }
        int mid=(low+high)/2;
        root->val=tmp[mid];//将当前元素范围的中值赋给子树的根节点
        if(mid-low>=1)//左范围容量
        {
            root->left=new TreeNode(0);//新建节点
            dfs(root->left,tmp,low,mid-1);//递归调用左子树
        }
        if(high-mid>=1)//右范围容量
        {
            root->right=new TreeNode(0);//新建节点
            dfs(root->right,tmp,mid+1,high);//递归调用右子树
        }
    }
};
```