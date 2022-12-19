### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		int n = target / 2 + 1;
		vector<vector<int>> res;
		for (int i = 1; i <= n; i++) {
			vector<int> line;
            long long int ii=(long long)i*(long long)i;
            long long int a=ii-i;
            long long int c= 2 * target;
			long long int m = (1 + 4 * (a+c));
			if (1 + 4 * m < 0) { continue; }
			else {
				
				int nn = sqrt(m);
				if (m%nn!=0) {
					continue;
				}
				else {
					int mm = -1 + nn;
					if (mm%2!=0) {
						continue;
					}
					else {
						int xiee = mm / 2;
						for (int j = i; j <= xiee;j++) {
							line.push_back(j);
						}
						res.push_back(line);
					}
				}
			
			}
		}

		return res;
	}
};
```