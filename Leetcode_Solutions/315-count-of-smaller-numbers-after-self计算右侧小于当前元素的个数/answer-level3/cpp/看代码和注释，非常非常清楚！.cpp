### 解题思路
此处撰写解题思路

### 代码

```cpp

#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

 class Solution{
	public:
	/*
	主要思想：建立二叉搜索树来求解。
	*/
	struct BSTNode{
		int val;//当前节点的值。
		int s;//s表示左子树的个数
		BSTNode * left;
		BSTNode * right;
		BSTNode(int x):val(x),left(nullptr),right(nullptr),s(0){}
	};

	BSTNode * insert(BSTNode * root,int target,vector<int> &ans,int index){//插入操作
		if(root==nullptr){//如果根节点为nullpptr，那么就将要插入的节点作为根节点，并返回
			BSTNode * temp=new BSTNode(target);
			return temp;
		}
		if(target<=root->val){//如果要插入的节点要小于等于当前节点，那么就应该将其插入左子树
			root->s++;//左子树的节点数目+1
			root->left=insert(root->left,target,ans,index);//插入到左子树
		}
		else{//要插入的节点要大于当前节点，那么就应该将其插入右子树
			ans[index]+=root->s+1;//此时，需要计算该节点，右边有多少个比该节点小的节点，ans[index]的组成是：root的左子树的节点个数（root->s）+root节点本身（1）。
			root->right=insert(root->right,target,ans,index);//插入到右子树
		}
		return root;
	}

	vector<int> countSmaller(vector<int>& nums) {
		if(nums.size()==0){
			vector<int> ans;
			return ans;
		}

		BSTNode * root=nullptr;
		vector<int> ans(nums.size(),0);
		for(int i=nums.size()-1;i>=0;i--){//从后往前插入，原因：当我们插入nums[i]时，我们会发现在这个节点右边的节点都已经插入到二叉搜索树当中了，所以就可以直接结果了。
			root=insert(root,nums[i],ans,i);
		}

		return ans;
	}
	 
 };

 int main(){
	int n;
	scanf("%d",&n);
	vector<int> nums;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		nums.push_back(x);
	}

	Solution so1;
	vector<int> ans=so1.countSmaller(nums);
	for(int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
	
 }
```