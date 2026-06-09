### 模拟
文首推荐LeetCode官方题解：[A1282. Group the People Given the Group Size They Belong To - LeetCode官方题解 - 哈希映射 - 时间复杂度O(N)](https://leetcode-cn.com/problems/group-the-people-given-the-group-size-they-belong-to/solution/yong-hu-fen-zu-by-leetcode/)

如果两人所在的组的人数一致，则可以简单的将其分到同一组。
 - 将用户ID和用户所在组的大小简单的捆绑在一起，可以用一个结构体，也可以直接用`std::pair`
 - 将用户信息按照其用户组大小进行排序（时间复杂度`O(NlogN)`）
 - 将用户组大小相同的用户分到同一组即可
```
bool func_ComprePeople(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}

class Solution {
public:
	vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
		vector<pair<int, int>> peoples;
		for (size_t i = 0; i < groupSizes.size(); ++i)
			peoples.push_back(make_pair(groupSizes[i], i));

		sort(peoples.begin(), peoples.end(), func_ComprePeople);

		vector<vector<int>> groups;
		vector<int> group;
		for (size_t i = 0; i < peoples.size(); ++i) {
			group.push_back(peoples[i].second);
			if (group.size() >= peoples[i].first) {
				groups.push_back(group);
				group.clear();
			}
		}

		return groups;
	}
};
```
我果真不适合写题解，写文章啊！