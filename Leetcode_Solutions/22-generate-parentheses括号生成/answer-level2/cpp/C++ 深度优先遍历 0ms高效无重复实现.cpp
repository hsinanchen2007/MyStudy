![image.png](https://pic.leetcode-cn.com/4460e0798f22e25d088ce78eb4721e4901e88b7aedc09f05c7bfc43dbd81f2ac-image.png)
C++执行用时0ms, 击败100% + 100%
### 解题思路
根据左括号数量做扩展, 中间剪枝无效的分支, 以左括号数量用完为终止分支的判断条件。
	剪枝依据： 已用左括号数量一定要大于等于已用右括号数量。

思路：先使用n个连续左括号, 再考虑使用n-1个左括号(所以立即跟一个右括号来限定左括号数量), 再考虑n-2个左括号....依此递归进行搜索
	类似零钱兑换等问题的思路, 解这一类题超好用！效率都很高！

[39. 组合总和](https://leetcode-cn.com/problems/combination-sum/solution/ctan-xin-suan-fa-qiu-jie-zhi-xing-0ms-by-lcl-17/)
[322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/solution/c-ling-qian-dui-huan-wen-ti-jing-dian-jie-fa-0ms-b/)
	

***欢迎讨论和交流！***
### 代码

```cpp
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (n == 0)  return{ "" };
		if (n == 1)  return{ "()" };
		vector<string> ans;
		generateParenthesisIter("(", n-1, n, ans);
		return ans;
	}

	void generateParenthesisIter(string valid, int left_num, int right_num, vector<string>& ans){
		if (left_num == 0){
			valid.append(right_num, ')');
			ans.push_back(valid);
			return;
		}
		for (int n = left_num; n >= 0; n--){ //本层使用的左括号数量
			string str = valid;
			if (left_num - n > right_num - 1)//剪枝: 无效的分支 
				return; //剩余括号中左括号数量大于右括号数量，说明已用的右括号数量大于左括号数量
			str.append(n, '(');
			str.append(1, ')');
			generateParenthesisIter(str, left_num - n, right_num - 1, ans);
		}
		return;
	}
};
```