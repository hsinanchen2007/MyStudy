### 解题思路
![exec.png](https://pic.leetcode-cn.com/c2b3f225b1c2280dd7edf5b4df8ca12ecf240f19933cd5fdf462dae637ca1eec-exec.png)
将电话号码对应的按键作为结点，用DFS+回溯法对按键组合进行穷举。

### 代码

```cpp
class Solution {
public:
	vector<string> v;	//号码表
	string tmp; 		//暂存组合
	vector<string> ans; //保存结果数组
	void initV(){		//建立号码表
		v.resize(10);
		v[0] = ""; v[1] = ""; v[2] = "abc"; v[3] = "def"; v[4] = "ghi";
		v[5] = "jkl"; v[6] = "mno"; v[7] = "pqrs"; v[8] = "tuv"; v[9] = "wxyz";
	}

	void dfs(unsigned index, string digits){
		int alphabet = digits[index] - '0'; //建立digit到号码表的下标映射
		if(index + 1 == digits.size()){		//到达最后一个字符
			for(unsigned i = 0; i < v[alphabet].size(); i++){
				tmp += v[alphabet][i];		//加入键值
				ans.push_back(tmp);
				tmp.erase(tmp.size() - 1);	//回溯
			}
		}
		else{
			if(alphabet == 0 || alphabet == 1){//按键为0或1则跳过
				dfs(index + 1, digits);
				return;
			}
			for(unsigned i = 0; i < v[alphabet].size(); i++){//根据一个号码上不同字符遍历
				tmp += v[alphabet][i];		//加入该键值
				dfs(index + 1, digits);		//dfs
				tmp.erase(tmp.size() - 1);	//回溯
			}
		}
	}

    vector<string> letterCombinations(string digits) {
    	if(digits.size() == 0) return ans;
    	initV();
    	dfs(0, digits);
    	return ans;
    }
};
```