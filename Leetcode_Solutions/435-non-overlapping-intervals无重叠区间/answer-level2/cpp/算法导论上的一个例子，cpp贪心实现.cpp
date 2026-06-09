# 无重叠区间
这题就是算法导论上面一个例子的改编，算法导论例子是安排活动教室，也就是安排最大不重叠的区间。有两种做法，一种是贪心，一种是动态规划。贪心就是按照结束时间排序，选择结束时间短的，如果有区间和这个区间重叠，就删去重叠区间。算法的正确性证明可以参看算法导论。

```cpp
static bool cmp(vector<int> p1, vector<int> p2) {
	return p1[1] < p2[1];
}
//移除最少数量的区间，使得不再重叠
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
	int sz = intervals.size();
	if (sz < 1) return 0;
	sort(intervals.begin(), intervals.end(), cmp);
	int cnt = 0;
	int tail = intervals[0][1];
	for (int i = 1; i < sz; i++) {
		if (intervals[i][0] < tail) cnt++;
		else {
			tail = intervals[i][1];
		}
	}
	return cnt;
}
```
# 跳跃游戏
[55.跳跃游戏](https://leetcode-cn.com/problems/jump-game/)
算法思想就是贪心，选则跳到下一个点`j`，使得跳动距离 + 跳到的目的地能够跳的距离之和最大。 
即·`max(m+nums[i+m])` 

```cpp
bool canJump(vector<int>& nums) {
	int j = 0;
	for (int i = 0; i < nums.size(); ) {
		int k = nums[i];
		if (i + k >= nums.size() - 1) return true; //可以跳到
		j = i; 
		int max = 1 + nums[i + 1]; //最少跳一步,否则终止
		for (int m = 1; m <= k; m++) {
			if (m + nums[i + m] >= max) { //选择跳到j之后，并且能跳得更远的点
				max = m + nums[i + m];
				j = m + i;
			}
		}
		if (i == j) return false; //无法跳动，则无法跳到终点
		else i = j;
	}
	return false;
}
```
# 跳跃游戏II
[跳跃游戏II](https://leetcode-cn.com/problems/jump-game-ii/)
和跳跃游戏做法一样，计算跳跃次数即可。
```
int jump(vector<int>& nums) {
	int j = 0;
	int cnt = 0;
	for (int i = 0; i < nums.size(); ) {
		int k = nums[i];
		if (i + k >= nums.size() - 1) { //可以跳到
			if (i != nums.size() - 1) cnt++;
			return cnt;
		}
		j = i;
		int max = 1 + nums[i + 1];
		for (int m = 1; m <= k; m++) {
			if (m + nums[i + m] >= max) {
				max = m + nums[i + m];
				j = m + i;
			}
		}
		i = j;
		cnt++;
	}
	return cnt;
}
```
# 去除重复字母
[316. 去除重复字母](https://leetcode-cn.com/problems/remove-duplicate-letters/)
对于当前字符s[i]，如果当前字符没有访问过，则删除栈中字典序比该字符大的并且栈中要删除的字符后续还会出现，即存在字典序更小的答案。将当前未访问过的字符加入到栈中。直接使用字符串模拟栈的操作即可。
```
//去除重复字母，每个字母只出现一次，不改变相对顺序，得到的字典序最小
string removeDuplicateLetters(string s) {
	int nums[26] = { 0 };
	int visited[26] = { 0 };
	for (int i = 0; i < s.size(); i++) {
		nums[s[i] - 'a']++;
	}
	string str = "";
	for (int i = 0; i < s.size(); i++) {
		nums[s[i] - 'a']--; //当前字符存在未访问的数目减1
		while (str.size() != 0 && !visited[s[i] - 'a']) { //如果当前字符未访问
			char c = str.back();
			if (s[i] < c && nums[c - 'a']>=1) { //存在字典序更小的字符串，删除后续还有的元素
				visited[c - 'a'] = 0;
				str.pop_back();
			}
			else break;
		}
		//当前字符未访问过，加入栈中
		if (visited[s[i] - 'a'] == 0) {
			str = str + s[i];
			visited[s[i] - 'a'] = 1;
		}
	}
	return str;
}
```
