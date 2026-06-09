### 解题思路
一开始没想到递归，就是想着怎么不断的遍历数组构造二叉树。
观察可知，对于前序序列，它在某种程度上决定了节点的层次位置，对于数组`[3,9,20,15,7]`，可知9、20在3的下面，15、7在20的下面，当然具体的判断还要结合中序序列；
同样的对于中序序列，他在某种程度上决定了节点的左右关系，对于数组`[9,3,15,20,7]`，可知，9在3的左侧，20、15、7在3的右侧；
那么把上述的两个规律相结合，便可以得到一种方法：
* 先遍历前序序列，找到下一个需要处理的孩子节点的值child_val，对应函数`int next(vector<int> preorder)`；
* 再遍历中序序列，找到上述孩子节点与他的根节点（curr）的相对位置，对应函数`int find(vector<int>& inorder, int curr_val, int target, set<int> &used)`，若：
   - 返回0，表示此时根节点已经没有左右子树，该孩子节点并不是curr节点的孩子；
   - 返回-1，表示孩子节点在curr的左侧；
   - 返回1，表示孩子节点在curr的右侧。
* 找到相对位置后，进行连接，将此时的curr入栈，调用`next`找到下一个孩子节点；如果是返回0的情况，则说明孩子节点不属于当前的curr（curr节点已经没有孩子），则将栈顶元素赋值给`curr`（类似于回溯），再次查找相对位置。

* 函数`int next(vector<int> preorder)`说明：从左至右遍历preorder，将使用过的节点置为preorder[0]，防止二次选中，其实直接用一个int也可以代替。。。
* 函数`int find(vector<int>& inorder, int curr_val, int target, set<int> &used)`说明：set的作用是记录已经使用过的节点，当一个节点在inorder序列中的左右响铃节点都被使用后，就说明他已经没有左右子树了，此时可以返回0，其他情况下，找到curr_val和target的位置，对比返回即可。
### 代码

```cpp
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		stack<TreeNode *> st;
		set<int> used;
		TreeNode *curr;
		if (preorder.size() == 0)
			return nullptr;
		TreeNode *root = new TreeNode(preorder[0]);
		used.insert(root->val);
		curr = root;
		//int child_val = next(preorder);
		int next=1;
		//while (child_val != INT_MAX)
		while (next<preorder.size())
		{
			int child_val=preorder[next];
			int child_pos = find(inorder, curr->val, child_val, used);
			if (child_pos == 0)
			{
				curr = st.top();
				st.pop();
				continue;
			}
			if (child_pos == -1)
			{
				curr->left = new TreeNode{ child_val };
				st.push(curr);
				curr = curr->left;
			}
			else if (child_pos == 1)
			{
				curr->right = new TreeNode{ child_val };
				st.push(curr);
				curr = curr->right;
			}
			++next;
			//child_val = next(preorder);
		}
		return root;
	}

	int find(vector<int>& inorder, int curr_val, int target, set<int> &used)
	{
		int curr_pos, target_pos;
		for (int i = 0; i<inorder.size(); i++)
		{
			if (inorder[i] == curr_val)
				curr_pos = i;
			if (inorder[i] == target)
				target_pos = i;
		}
		if ((curr_pos - 1<0 || used.find(inorder[curr_pos - 1]) != used.end())
			&& (curr_pos + 1 >= inorder.size() || used.find(inorder[curr_pos + 1]) != used.end()))
			return 0;
		used.insert(inorder[target_pos]);
		return curr_pos>target_pos ? -1 : 1;
	}
	/*int next(vector<int>& preorder)
	{
		int i = 1, child_val = INT_MAX;
		while (i<preorder.size())
		{
			if (preorder[i] != preorder[0])
			{
				child_val = preorder[i];
				preorder[i] = preorder[0];
				break;
			}
			++i;
		}
		return child_val;
	}*/
};
```