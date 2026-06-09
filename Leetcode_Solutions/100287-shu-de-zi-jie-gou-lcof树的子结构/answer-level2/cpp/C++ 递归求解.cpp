### 解题思路
在树A中查找与B树根节点值一样的节点R。如果找到了值相同的节点，则判断树A中以R为根节点的子树是不是和树B具有共同的结构DoseTreeHave()
    - 判断左右子结构是否相同，也可采用递归方式，递归结束条件分为四种情形
        a. B树遍历完了（说明A树子结构和B树子结构相同），return true;
		b. A树遍历完了（此时A树没有遍历完），说明不同，return false;
		c. A树和B树比较的节点的值不同，return false;
		d. A树和B树当前节点值相等，继续比较其左右子树
	- 如果没找到值相同的节点，则将A树的左子树的首节点值和B树比较
	- 如果左子树中不存在和B树节点值相同的节点，则向其右子树进行查找
	- 如果均没有，则result=false,返回result

### 代码

```cpp
class Solution {
public:
	//判断子结构是否相同
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		bool result = false;
		if (A!=nullptr&&B!=nullptr)//A，B都不为空
		{
			if (A->val==B->val)//如果两个值相等，则判断其子树是否相等
			{
				result = DoseTreeHaveTree2(A, B);
			}
			//如果A树的值不和B树值相等，则将其左子树和B树比较
			if (!result)
			{
				result = isSubStructure(A->left, B);
			}
			//如果A树的左子树结构和B树不相等，则将其右子树和子树进行判断是否相等
			if (!result)
			{
				result = isSubStructure(A->right, B);
			}
		}
		return result;
	}
	//判断树的左右结构是否相同
	bool DoseTreeHaveTree2(TreeNode* A, TreeNode* B)
	{
		if (B == nullptr) return true;//如果B为null，说明结构相同
		if (A == nullptr) return false;//如果A为null，则说明子结构不同
		if (A->val != B->val) return false;//如果两个值不同，则说明子结构不同
		return DoseTreeHaveTree2(A->left, B->left) && DoseTreeHaveTree2(A->right, B->right);//如果A和B值相同，则分别判断其左右子树是否相同
	}
	
};
```