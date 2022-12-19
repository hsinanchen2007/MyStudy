我后面的分类讨论肯定是写繁了。
看了一下 [这个](https://leetcode-cn.com/problems/largest-multiple-of-three/solution/c-qu-diao-zui-xiao-zhi-8ms-by-yusenzhang_chatc/) 解法：求和后倒过来减去一些数，这样要判断的简单多了。
```C++ []
class Solution {
public:
	string largestMultipleOfThree(vector<int>& digits) {
		queue<int> st1, st2;
		vector<int> res;
		//从大到小排序
		sort(digits.begin(), digits.end(), greater<int>());
		for (int i = 0; i < digits.size(); i++) {
			if (digits[i] == 9 || digits[i] == 6 || digits[i] == 3 || digits[i] == 0)
				res.push_back(digits[i]);
			if (digits[i] == 8 || digits[i] == 5 || digits[i] == 2) {
				st2.push(digits[i]);
			}
			if (digits[i] == 7 || digits[i] == 4 || digits[i] == 1) {
				st1.push(digits[i]);
			}
		}
		int min = st2.size() < st1.size() ? st2.size() : st1.size();
		min -= 2;	//多留两个
		for(int i=0;i<min;i++){
			res.push_back(st2.front());
			st2.pop();
			res.push_back(st1.front());
			st1.pop();
		}
		while(st2.size() > 4){
			res.push_back(st2.front());
			st2.pop();
			res.push_back(st2.front());
			st2.pop();
			res.push_back(st2.front());
			st2.pop();
		}
		while (st1.size() > 4) {
			res.push_back(st1.front());
			st1.pop();
			res.push_back(st1.front());
			st1.pop();
			res.push_back(st1.front());
			st1.pop();
		}
		//余数为2,2,2,2,1,1或2,2,2,2,1时，取2,2,2,2,1
		if ((st1.size() == 2 || st1.size() == 1)&& st2.size() == 4) {
			res.push_back(st1.front());
			st1.pop();
			for (int i = 0; i < 4; i++) {
				res.push_back(st2.front());
				st2.pop();
			}
		}
		//余数为2,2,1,1,1,1或2,1,1,1,1时，取2,1,1,1,1
		if (st1.size() == 4 && (st2.size() == 2|| st2.size() == 1)) {
			res.push_back(st2.front());
			st2.pop();
			for (int i = 0; i < 4; i++) {
				res.push_back(st1.front());
				st1.pop();
			}
		}
		//余数为2,2,2,1,1或2,2,1,1,1或2,2,1,1时，取2,2,1,1
		if ((st1.size() == 2 && st2.size() == 3) || (st1.size() == 3 && st2.size() == 2) || (st1.size() == 2 && st2.size() == 2)) {
			for (int i = 0; i < 2; i++) {
				res.push_back(st1.front());
				st1.pop();
			}
			for (int i = 0; i < 2; i++) {
				res.push_back(st2.front());
				st2.pop();
			}
		}
		//余数为2,1,1,1时，取1,1,1
		if (st1.size() == 1 && st2.size() == 3) {
			for (int i = 0; i < 3; i++) {
				res.push_back(st2.front());
				st2.pop();
			}
		}
		//余数为2,2,2,1时，取2,2,2
		if (st1.size() == 3 && st2.size() == 1) {
			for (int i = 0; i < 3; i++) {
				res.push_back(st1.front());
				st1.pop();
			}
		}
		//余数为2,2,1或2,1,1或2,1时，取2,1
		if ((st1.size() == 1 && st2.size() == 2) || (st1.size() == 2 && st2.size() == 1) || (st1.size() == 1 && st2.size() == 1)) {
			res.push_back(st1.front());
			st1.pop();
			res.push_back(st2.front());
			st2.pop();
		}
		while (st2.size() > 2) {
			res.push_back(st2.front());
			st2.pop();
			res.push_back(st2.front());
			st2.pop();
			res.push_back(st2.front());
			st2.pop();
		}
		while (st1.size() > 2) {
			res.push_back(st1.front());
			st1.pop();
			res.push_back(st1.front());
			st1.pop();
			res.push_back(st1.front());
			st1.pop();
		}

		//重新排序并化为string
		sort(res.begin(), res.end(), greater<int>());
		string s = "";
		for (int i = 0; i < res.size(); i++) {
			s += to_string(res[i]);
		}
		//判断多个0的情况，同时排除res为空的情况
		if (s == string(res.size(), '0')&&s!="")
			s = "0";
		return s;
	}
};
```
