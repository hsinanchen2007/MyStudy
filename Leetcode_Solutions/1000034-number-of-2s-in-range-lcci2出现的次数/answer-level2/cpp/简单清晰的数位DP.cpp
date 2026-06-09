### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
int numberOf2sInRange(long int n) {
	long int input = n;
	vector<long int> temp;//保存位数
	while (n) {
		temp.push_back(n % 10);
		n /= 10;
	}
	vector<long int> dp(temp.size());//保存整数位相对2的出现数量
	dp[0] = 1;
	for (int i = 1;i < temp.size();i++) {
		dp[i] = dp[i - 1] * 10 + (long int)pow(10, i);//
	}
	int output = temp[0]>=2?1:0;
	for (int i = temp.size() - 1;i > 0;i--) {
		output += dp[i - 1] * temp[i];
		if (temp[i] > 2)output += (long int)pow(10, i);
		else if (temp[i] == 2)output += input% (long int)pow(10, i)+1;
	}
	return output;
}


};
```