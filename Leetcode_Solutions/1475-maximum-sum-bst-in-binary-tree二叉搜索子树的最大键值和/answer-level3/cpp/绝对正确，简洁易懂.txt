# 绝大多数人的代码都有问题，比赛时测试点没有考虑完全
当时比赛时候我就发现了测试点有问题，因为我当时写的代码有问题，但莫名其妙就过了。
比如 这种情况，答案就是错的 [4,3,null,1,5],正确答案为 9 ，而不是 13。

我的代码是看榜二大佬的代码学到的，也算是对榜二大佬代码的翻译吧。
1. 大佬用了一个时间戳，保存每次DFS遍历的次序。返回的是每个孩子的时间戳。这样每个孩子都能找到。右下角圆圈里面的数字是时间戳
![IMG_20200310_134039.jpg](https://pic.leetcode-cn.com/209a17c36d1084c4c72900d5e480f56b4f4c7db85bf887be781f1fed3fbad0c7-IMG_20200310_134039.jpg)


2. 然后对每个节点的状态进行分析。
3. 首先找出来 每个节点本身及其左右孩子中最大的节点的值，然后同样找到最小的。
4. 之后保存当前元素及其所有孩子的和。（不用纠结他是不是二叉搜索树，我们只管加，如果是二叉搜索树再更新最大值就行了。）
5. 然后判断当时元素及其孩子是否是二叉搜索树 `isb[l[x]] && isb[r[x]] && mx[l[x]]<root->val && root->val<mi[r[x]] ;` ，判断左节点是否是二叉搜索树，右节点是否是二叉搜索树，如果都是的话在判断左节点的最大值是不是小于当前元素，右节点最小值是否大于当前元素。（这是二叉搜索树的概念，任意节点的左子树中的键值都 小于 此节点的键值，任意节点的右子树中的键值都 大于 此节点的键值。）
6. 如果当前节点是二叉搜索树，那么更新最大值就可以了。
7. 最后返回最大值。可以证明对任何情况都是成立的。
8. 初始化是因为，如果孩子为空，那么返回时间戳为0，初始化最大值为最小，最小值为最大，这样每次查找到叶子节点的时候，最大最小值就是叶子节点本身了。

代码如下：

```
class Solution {
public:
    static const int maxn=4e4+4;
    int l[maxn],r[maxn],sum[maxn],mx[maxn],mi[maxn],cur,ans;
    bool isb[maxn];
    int dfs(TreeNode* root){
        if(root==nullptr) 
            return 0;
        int x=++cur;
        l[x]=dfs(root->left);
        r[x]=dfs(root->right);
        mx[x]=max(root->val,max( mx[l[x]], mx[r[x]] ));
        mi[x]=min(root->val,min( mi[l[x]], mi[r[x]] ));
        sum[x]=root->val+sum[l[x]]+sum[r[x]];
        isb[x]=isb[l[x]] && isb[r[x]] && mx[l[x]]<root->val && root->val<mi[r[x]] ;
        if(isb[x]) ans=max(ans,sum[x]);
        return x;
    }
    int maxSumBST(TreeNode* root) {
        cur=ans=sum[0]=0;
        isb[0]=true;
        mx[0]=INT_MIN;
        mi[0]=INT_MAX;
        dfs(root);
        return ans;
    }
};
```
如有问题请在评论区留言，我们共同进步！
