创建长度为60的整型数组，统计时长对60取余结果为对应数组下标的歌曲数量

统计好后，count[0]与count[30]内部消化，组数C(count[0],2)和C(count[30],2)

其余组为count[k]与count[60-k]各任取一个，组数为count[k]*count[60-k]

所有组数作和即可

代码：
```
class Solution {
public:
	int numPairsDivisibleBy60(vector<int>& time) {
		int count[60] = { 0 };
		int len = time.size();
		for (int i = 0; i < len; i++)
			count[time[i] % 60]++;
		int ans = (count[0] * (count[0] - 1) + count[30] * (count[30] - 1)) >> 1;
		for (int i = 1; i < 30; i++)
			ans = ans + count[i] * count[60 - i];
		return ans;
	}
};
```
