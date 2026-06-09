### 
![image.png](https://pic.leetcode-cn.com/903e160fdbbf89bddc03f818a83addd829d8fe3564d56bdd2e2691d4e99b3d60-image.png)


### 代码

```cpp
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		string ip;
		helper(s, 0, ip);
		return res;
	}
	void helper(string s, int n, string ip) {
		if (n == 4) {
			if (s.empty()) res.push_back(ip); 
		}
		else {
			for (int k = 1; k < 4; ++k) {
				if (s.size() < k) break;
				int val = stoi(s.substr(0, k));
				//值大于255或者以0开头不符合IP规定,可以剪枝
				if (val > 255 || k != std::to_string(val).size()) continue; 
				helper(s.substr(k), n + 1, ip + s.substr(0, k) + (n == 3 ? "" : "."));
			}
		}
		return;
	}
private:
	vector<string> res;
};
```