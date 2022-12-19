如果骨牌等价，那么骨牌上数字的和与积一定是唯一的

因此创建hash将骨牌[a,b]映射到82*(a+b)+a*b，保证唯一性

若映射到同一数值的骨牌有n个，则等价组数为C(n,2)，逐一遍历计算即可

代码：
```
class Solution {
public:
	int numEquivDominoPairs(vector<vector<int>>& dominoes) {
		int len = dominoes.size();
		map<int,int> temp;
		for (int i = 0; i < len; i++) {
			int key = (dominoes[i][0] + dominoes[i][1]) * 82 + dominoes[i][0] * dominoes[i][1];
			if (temp.find(key) != temp.end())
				temp[key]++;
			else
				temp[key] = 1;
		}
		int ans = 0;
		map<int, int>::iterator m;
		for (m = temp.begin(); m != temp.end(); m++) {
			int num = m->second;
			ans += num * (num - 1) / 2;
		}
		return ans;
	}
};
```
