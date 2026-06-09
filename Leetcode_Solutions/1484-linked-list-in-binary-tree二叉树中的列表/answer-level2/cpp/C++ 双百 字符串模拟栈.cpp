![TIM截图20200302212555.png](https://pic.leetcode-cn.com/e2a30b5ea1f81cdb6e8d5f0f3d8e621822606e9b348786bee6135c72c92e2ac8-TIM%E6%88%AA%E5%9B%BE20200302212555.png)
将链表转化为字符串，深度优先遍历二叉树，对于每一条从根节点到叶子节点的路径，也转化为字符串，用find函数判断路径字符串是否包含链表字符串，如果包含，则令flag=1。执行完verify函数后，按照root->val位数退栈，root->val是几位数就在末尾删除几个字符（用substr实现退栈）。
```
class Solution {
public:
string goal="";
int flag=0;
string s;
void verify(TreeNode* root){
    int x,w;
	if(flag==1)return;
	if(root==nullptr)return;
	if(root->left==nullptr&&root->right==nullptr){
		s+=to_string(root->val);
		if(s.find(goal)<s.size())flag=1;
		if(root->val/10==0)
		w=0;
        x=root->val;
	    while(x!=0){
		    w++;
		    x/=10;
	    }
	    s=s.substr(0,s.size()-w);
		return;
	}
	s+=to_string(root->val);
	verify(root->left);
	if(flag==1)return;
	verify(root->right);
	if(flag==1)return;
     w=0;
     x=root->val;
	while(x!=0){
		w++;
		x/=10;
	}
	s=s.substr(0,s.size()-w);
}



bool isSubPath(ListNode* head, TreeNode* root) {
    
	while(head!=nullptr){
		goal+=to_string(head->val);
		head=head->next;
	}
	verify(root);
	if(flag==1)return true;
	return false;
}
};
```

