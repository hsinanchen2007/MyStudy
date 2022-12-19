这是看了官方题解之后的总结：
前面的快慢指针，以及转换为数组的方法我们就不介绍了，直接看时间复杂度为O(n)，空间复杂度为O(logn)的做法（递归的代价）；
我们思考与上面第108题的区别，将有序数组转化为二叉搜索树，我们先找中点，得到根节点，然后左右递归得到左子树和右子树，这其实本质上是前序遍历，（思考一下，先生成根节点，再生成左子树和右子树是不是就是前序遍历）；
而对于链表，找中点的代价为O(n)，所以前序遍历不适合链表，但是我们可以思考二叉搜索树和中序遍历的联系：对二叉搜索树进行中序遍历得到的就是一个有序的序列，和链表联系起来，就是链表遍历的顺序，所以我们可以采用中序遍历的方式来生成二叉搜索树。
但是由于是平衡的二叉搜索树，需要将中点设为根节点，所以可以先得到整个链表的元素个数。
代码如下图所示：
class Solution {
public:
ListNode *myhead;
    TreeNode* sortedListToBST(ListNode* head)
{
int len=length(head);
myhead=head;
return recursion(0,len-1);
}
TreeNode* recursion(int left,int right)
{
if(left>right)
return NULL;
int mid=(left+right)/2;
TreeNode* root=new TreeNode(0);
root->left=recursion(left,mid-1);
root->val=myhead->val;
myhead=myhead->next;
root->right=recursion(mid+1,right);
return root;
}
int length(ListNode* head)
{
int ans=0;
while(head!=NULL)
{
	ans++;
	head=head->next;
}
return ans;
}
};