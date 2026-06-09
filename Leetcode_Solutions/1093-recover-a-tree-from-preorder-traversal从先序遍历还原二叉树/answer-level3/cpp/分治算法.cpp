### 解题思路


### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
struct Nod
{
	int height;
	int val;
};
void buildTree(vector<Nod>&NodList, TreeNode*ptr,int start,int end,int curr)
{
	if (start > end)
		return;
	int left_id = -1;
	int right_id = -1;
	for (int i = start; i <= end; i++)
	{
		if (curr == NodList[i].height)
		{
			if (left_id == -1)
			{
				left_id = i;
				continue;
			}
			if (left_id != -1 && right_id == -1)
			{
				right_id = i;
				continue;
			}
			if (left_id != -1 && right_id != -1)
				break;
		}
	}
	if (left_id != -1)
	{
		ptr->left = new TreeNode(NodList[left_id].val);
	}
	if (right_id != -1)
	{
		ptr->right = new TreeNode(NodList[right_id].val);
	}
	if (left_id == -1 && right_id == -1)
		return;
	if (left_id != -1 && right_id == -1)
		buildTree(NodList, ptr->left, left_id + 1, end, curr + 1);
	if (left_id != -1 && right_id != -1)
	{
		buildTree(NodList, ptr->left, left_id + 1, right_id - 1, curr + 1);
		buildTree(NodList, ptr->right, right_id + 1, end, curr + 1);
	}
}
    TreeNode* recoverFromPreorder(string S) {
    if(S.size()==0)return NULL;
    int size = S.size();
	Nod temp;
	vector<Nod>NodList;
	int h = 0;
	for (int i = 0; i < size; )
	{
		if (S.at(i) != '-')
		{
			int j;
			for (j = i; j < size; j++)
			{
				if (S.at(j) == '-')
					break;
			}
			j--;
			int num = 0;
			for (int k = i; k <= j; k++)
				num += static_cast<int>(pow(10, j - k ))*(S.at(k) - '0');
			i = j + 1;
			temp.height = h;
			temp.val = num;
			NodList.push_back(temp);
			h = 0;
		}
		else {
			h++;
			i++;
		}
	}
	TreeNode*root = new TreeNode(NodList[0].val);
	buildTree(NodList, root, 1, NodList.size()-1, 1);
    return root;
    }
};
```