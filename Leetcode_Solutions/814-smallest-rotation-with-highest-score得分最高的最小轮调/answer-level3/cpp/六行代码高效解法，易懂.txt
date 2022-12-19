
如果把初始分数看成一个常数S,那么每一次调度都会导致其变化
那么就只考虑调度次数不同情况下的变化即可
那么先记录每个元素调度多少次后开始让分数较少
即从某一步开始，每调度一次就扣一分
那么，最后只需要从标记数组中找到最大的下标即可
```python []
class Solution():
    def bestRotation(self, A):
        #score[k]:表示移动K步后，当前分数应该加几分，正数为加，负数为扣
        score = [0] * len(A)
        for i in range(len(A)):
            score[(i + len(A) - A[i] + 1) % len(A)] -= 1
        for i in range(1, len(A)):
            score[i] += score[i - 1] + 1
        return score.index(max(score))

```
```C++ []
class Solution {
public:
	int bestRotation(vector<int>& A) {
		int n = A.size();
		vector<int> score(n, 0);
		for (int i = 0; i < n; ++i) 
			--score[(i + n - A[i] + 1) % n];
		for (int i = 1; i < n; ++i)
			score[i] += score[i - 1] + 1;
		return distance(score.begin(), max_element(score.begin(), score.end()));
	}
};
```
