![image.png](https://pic.leetcode-cn.com/ef7faa89ca2375d7fe802af03073e44f1c122257f4eea64f4494406eb659633d-image.png)
解题思路：用一个vector保存S中各位置的字符串代表的值，循环叠加，判断和：超过100,行加一，sum置0，叠加；等于100，行加一，sum置0，进入下一次循环；小于100，只叠加。
```
vector<int> numberOfLines(vector<int>& widths, string S) {
	int val[S.size()] = { 0 }; int sum = 0; int row = 0; vector<int>res;
	int i = 0, j = 0, flag = 0;
	for (; j<S.size(); ++j)
		val[j] = widths[S[j] - 'a'];
	for (; i < j; ++i) {
		if  (sum + val[i] == 100) { ++row; sum = 0; continue; }
		else if((sum + val[i]) / 100 != sum / 100 &&  sum + val[i] !=100) {++row; sum = 0;}
		
		 sum += val[i];
	}
	if (sum != 0) flag = 1;
	res.push_back(flag + row);
	res.push_back(sum);
	return res;
}
```
