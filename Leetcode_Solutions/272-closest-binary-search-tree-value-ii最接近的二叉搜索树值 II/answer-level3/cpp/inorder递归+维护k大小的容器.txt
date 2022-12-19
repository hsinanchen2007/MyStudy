### 解题思路
节点为空返回
递归查找左孩子
容器还没满
	容器是空的，直接push
	容器不是空的，将当前值按照从小到大的顺序插入
容器满了
	将当前值按照从小到大的顺序插入，pop容器最后一个元素
递归查找右孩子

### 代码

```cpp
class Solution {
	vector<int>res;
	vector<double>dif;
public:
	vector<int> closestKValues(TreeNode* root, double target, int k) {
		traverse(root, target, k);
		return res;
	}

	void traverse(TreeNode* root, double target, int k) {
		if (root == NULL) return;
		traverse(root->left, target, k);
		double val = abs(root->val - target);
		if (dif.size()<k) {
			//堆还不满
			if (dif.size() == 0) {
				//堆是空的
				dif.push_back(val);
				res.push_back(root->val);
			}
			else {
				//按照从小到大插入
				int i = dif.size() - 1;
				for (i; i >= 0; i--) {
					if (val>dif[i]) break;
				}
				i++;
				dif.insert(dif.begin() + i, val);
				res.insert(res.begin() + i, root->val);
			}
		}
		else if (val<dif[k - 1]) {
			//需要进行替换,替换最后一个元素
			int i = k - 1;
			for (i; i >= 0; i--) {
				if (val>dif[i]) break;
			}
			i++;
			dif.insert(dif.begin() + i, val);
			dif.pop_back();
			res.insert(res.begin() + i, root->val);
			res.pop_back();
		}
		traverse(root->right, target, k);
	}
};
```