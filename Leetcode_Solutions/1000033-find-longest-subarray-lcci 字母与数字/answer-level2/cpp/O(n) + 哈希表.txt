```
class Solution {
public:
	vector<string> findLongestSubarray(vector<string>& array) {
		if (array.empty())return {};
		int n = array.size(), cnt = 0, s = 0, e = 0;
		unordered_map<int, int>hash;
		for (int i = 0; i < n; ++i) {
			//是数字就加一,字母就减一
			if (array[i][0] >= '0' && array[i][0] <= '9')++cnt;
			else --cnt;
			if (!cnt) s = 0, e = i;//从开头到 i 位置字母与数字个数相同.
			else {
				if (hash.count(cnt)) {
					if (i + s > e + hash[cnt] + 1 || i + s == e + hash[cnt] + 1 && hash[cnt] + 1 < s) {
						s = hash[cnt] + 1;
						e = i;
					}
				}
				else hash[cnt] = i;//只需要记录最左端的.
			}
		}
		if (s == e)return{};
		return { array.begin() + s,array.begin() + e + 1 };
	}
};
/*

假设 j 位置为 cnt i 位置也为 cnt
那么 说明 [0,j] 区间存在 cnt 个数字,也就是说[j+1,i]位置字母与数字个数相同

*/
```
