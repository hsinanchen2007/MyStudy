## 5356. 矩阵中的幸运数
**题目类型**：暴力枚举
枚举每个元素，然后检查是否符合幸运数的要求。
```cpp
class Solution { 
    public:
        vector<int> luckyNumbers (vector<vector<int>>& matrix) {
            vector<int> res; 
            for(int i = 0, n = matrix.size(); i < n; i++) { 
                for(int j = 0, m = matrix[i].size(); j < m; j++) {
                    bool flag = true;
                    for(int k = 0; flag && k < m; k++) {
                        if(k == j) { continue; }
                        if(matrix[i][j] > matrix[i][k]) { flag = false;}
                    }
                    for(int k = 0; flag && k < n; k++) {
                        if(k == i) { continue; }
                        if(matrix[i][j] < matrix[k][j]) { flag = false;}
                    }
                    if (flag) {
                        res.push_back(matrix[i][j]);
                    }
                }
            }
            return res;
        } 
};

```
## 5357. 设计一个支持增量操作的栈
**题目类型**：模拟，栈
使用 size 变量记录栈的容量，使用 top 变量记录栈顶位置。
坑点：进行 increment 操作时，栈内的元素可能不足 k 个。

```cpp
const int MAXN = 1000;

class CustomStack {
	int data[MAXN];
	int size;
	int top;
	public:
		CustomStack(int maxSize): size(maxSize), top(0) {}

		void push(int x) {
			if (top < size) {
				data[top++] = x;
			}
		}

		int pop() {
			if(top > 0) {
				return data[--top];
			}
			return -1;
		}

		void increment(int k, int val) {
			for(int i = 0, n = min(k, top); i < n; i++) {
				data[i] += val;
			}
		}
};

```
## 5179. 将二叉搜索树变平衡
**题目类型**：树的遍历，递归，构造
先遍历给出的二叉搜索树，按照中序遍历的顺序将树中元素保存下来。

根据**升序数组**构造平衡二叉搜索树：
 1. 如果数组为空，则对应的树亦为空。
 2. 如果数组不为空，设长度为 n，那么位置$\frac{n}{2}$处的元素应为树的根节点。子数组 $[1, \frac{n}{2}-1]$ 及 $[\frac{n}{2}+1, n]$ 分别对应左右子树。因为两个子数组的长度相差不会超过 1，所以保证了左右子树的高度相差不会超过 1。

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
    void dfs(TreeNode *root, vector<int> &vec) {
        if(root == nullptr) { return; }
        dfs(root->left, vec);
        vec.push_back(root->val);
        dfs(root->right, vec);
    }
    TreeNode* construct(const vector<int> &vec, int L, int R) {
        if(L > R) {
            return nullptr;
        }
        int mid = (L+R)>>1;
        auto ptr = new TreeNode(vec[mid]);
        ptr->right = construct(vec, mid+1, R);
        ptr->left = construct(vec, L, mid-1);
        return ptr;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(root == nullptr) {
            return nullptr;
        }
        vector<int> data;
        dfs(root, data);
        return construct(data, 0, data.size()-1);
    }
};
```
## 5359. 最大的团队表现值
**题目类型**：快速排序，堆排序，枚举
**C++知识点**：std::priority_queue，std::greater，运算符重载
**坑点**：注意在运算过程中数据范围有可能超出 int32。

> std::priority_queue 可以参见 http://www.cplusplus.com/reference/queue/priority_queue/
> std::greater 可以参见 http://www.cplusplus.com/reference/functional/greater/ 

**思考路书**：
当两种方案的efficiency相等时，speed之和更大的方案显然更优。
题目的输入决定了最多有 n 种 efficiency。
对于每种 efficiency 肯定都会存在最优的方案。
最终答案肯定就是这个n种方案里面最优的那个。
问题转化成了如何快速求出每种 efficiency 的最优方案：
 - 从大到小枚举efficiency，使用一个数组维护可选的职员。因为efficiency不断减小，所以职员只会被加入这个数组，而绝不会被删除。
 - 在数组种选取 k 个最大的 speed(可使用堆排序维护)，**使用当前枚举到 efficiency** 与 k个最大的speed之和相乘作为当前 efficiency 的最优解。
 
**注意**： 选取的 k 个最大speed对应的efficiency可能都大于当前枚举的 efficiency，但是这并不影响最终答案的正确性。因为如果这个选择方案的确为最终答案的话，则其值必然记录在其他 efficiency 的最优解中。
**编程技巧**：使用 std::priority_queue 代替堆排序代码，提高编码速度。

```cpp
class Solution {
	struct Engineer {
		int64_t s;
		int64_t e;
		Engineer(int64_t _s, int64_t _e) : s(_s), e(_e) {}
		bool operator < (const Engineer &r) const {
			return this->e > r.e;
		}
	};
	vector<Engineer> data;
	priority_queue<int, vector<int>, greater<int>> pq;
	public:
	int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
		for(int i = 0; i < n; i++) {
			data.push_back(Engineer(speed[i], efficiency[i]));
		}
		sort(data.begin(), data.end());
		int64_t sum = 0, anw = 0;
		for(int i = 0; i < n; i++) {
            sum += data[i].s;
			pq.push(data[i].s);
			if(pq.size() > size_t(k)) {
				int64_t tmp = pq.top();
				pq.pop();
				sum -= tmp;
			}
			anw = max(anw, sum * data[i].e);
		}
		return anw%(1000000007);
	}
};
```
![](https://pic.leetcode-cn.com/9a6ec1ec20ba82ba0133353c61c5f2af82603f6a9c5a0f586c28b936d5a064b9.jpg)
**扫描关注 HelloNebu 获取更多计算机相关文章~**