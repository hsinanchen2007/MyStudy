速度快主要是因为在分割时只使用split[3]记录分割点的位置，只在最后生成结果时涉及到新字符串创建


```c++
class Solution {
public:
	vector<string> ans;
	string ss;
	int len;
	int split[3] = { 0 }; //记录分割点的位置

	vector<string> restoreIpAddresses(string s) {
		ss = s;
		len = s.size();
		
		dfs(0);
		return ans;
	}

	void dfs(int deep) {
		if (deep == 3) {
			if (len - split[2] > 3 || split[2] >= len) //给第四段剩余的字符数太长，大于三位或者不够1位直接跳出
				return;
			if (valid(ss.substr(split[2], len - split[2] ))) {//给第四段剩余的字符符合条件，可以视为一个结果
				gen_ans();
			}
			return;
		}
		for (int i = 1; i <= 3; i++) {
			int start = deep == 0 ? 0 : split[deep - 1] ;  //start 为上一个分割点的位置
			if (start+i < len &&valid(ss.substr(start, i))){
				split[deep] = start+i; //start+i 为分割点
				dfs(deep+1);
			}
		}
	}

	void gen_ans() {
		string temp(len + 3,'0');
		int j = 0;//记录第j个点的位置
		for (int i = 0; i < len; i++) {
			if (j<3 && i == split[j]) {
				temp[i+j] = '.';
				j++;
			}
			temp[i + j] = ss[i];
		}
		ans.push_back(temp);
	}

	bool valid(const string& s) {
		if (s[0] == '0') {  //防止出现 001，010 等情况
			if (s.size() > 1) {
				return false;
			}
		}
		int val = stoi(s);
		if (val >= 0 && val <= 255) 
			return true;
		else
			return false;
	}
};
```


![93.png](https://pic.leetcode-cn.com/ab0bd9638f2f45959b44e606bde69e5c1144f4733ea16775276a0fb0fbcdec7c-93.png)
