这道题实在太有启发性了，位运算在这道题里发挥的作用实在是太大了。
1，集合的表示：26 个小写英文字母 ，用int足够表示出所有的集合
2，集合的运算：A&B=A,表示A是B的子集
3，子集的遍历：for(int i=A;i;i=(i-1)&A){}实在是太妙了。
4，算法上的启发：一般的思路是我们拿word对应的num1注意跟puzzle对应的num2进行交集判断，也就是判断num1是否是num2的子集，如果是num2不确定的情况下，上面的做法无可厚非。但是这里规定了pupple只有7位，也就说我们的子集已经是限制出来了，完全可以反过来，挑出每一个子集看看是不是出现在word里面，这个时候，哈希表马上就出来了。所以这是一种检索的思维习惯问题。
```
class Solution {
public:
	vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles) {
		int n = puzzles.size();
		vector<int>ret;
		int wn = words.size();
		unordered_map<int, int>count;
		for (auto word : words)
		{
			int num = 0;
			for (auto c : word)
			{
				num |= 1 << c - 'a';
			}
			count[num]++;
		}
		for (auto p : puzzles)
		{
			int num = 0;
			for (auto c : p)
			{
				num |= 1 << c - 'a';
			}
			auto first_num = 1 << p[0] - 'a';
			int cnt = 0;
			for (int j = num; j; j = (j - 1)&num)
			{
				if ((j&first_num)&& count.count(j))
					cnt += count[j];
			}
			ret.push_back(cnt);
		}
		return ret;
	}
};
```
