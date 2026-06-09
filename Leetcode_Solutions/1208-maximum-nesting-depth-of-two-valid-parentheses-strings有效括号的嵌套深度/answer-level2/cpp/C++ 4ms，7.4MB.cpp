### 解题思路
先求出seq的最大的嵌套深度depth，再遍历seq，遇到深度大于depth/2的括号就将其移除

### 代码

```cpp
class Solution {
public:
	int depth(const string& seq) {//求嵌套深度
		int res = 0;
		int stack = 0;
		int len = seq.size();
		for (int i = 0; i < len; i++) {
			if (seq[i] == '(') {
				stack++; //入栈
			}
			if (seq[i] == ')') {
				if (seq[i - 1] == '(') {
					res = res > stack ? res : stack;
				}
				stack--;//出栈
			}
		}
		return res;
	}
	vector<int> maxDepthAfterSplit(string seq) {
		int len = seq.size();
		vector<int> res(len, 0);
		if (len == 0) return res;
		int depth = this->depth(seq);//seq的嵌套深度
		depth = depth / 2;

		//开始处理seq
		int stack = 0;
		for (int i = 0; i < len; i++) {
			if (seq[i] == '(') {
				stack++; //入栈
				if (stack > depth)//深度大于depth的'（'全都移出
					res[i] = 1;
			}
			if (seq[i] == ')') {
				if (stack > depth)//深度大于depth的'）'全都移出
					res[i] = 1;
				stack--;//出栈
			}
			
		}

		return res;
	}
};
```
![捕获.PNG](https://pic.leetcode-cn.com/bc9d17905a9412194004306112143bae777a240117e440d9b859286d2143c893-%E6%8D%95%E8%8E%B7.PNG)
