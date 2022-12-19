```
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> res;
		unordered_map<int, int> M;
		M[0] = 0;
		int c = 1;
		res.push_back(M[0]);
		for (int i = 1; i <= num; i++)
		{
			if (i == c) {
				M[i] = 1;
				c = c * 2;
			}
			else
				M[i] = 1 + M[i - c / 2];
            res.push_back(M[i]);
		}
		return res;
	}
};
```
