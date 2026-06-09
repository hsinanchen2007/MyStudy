这个题目说是从 [1,1,1] ==> [9,3,5]
其实反过来会更好做一点

比赛的时候没想出什么好办法，就暴力做了

首先我们分析 [9,3,5]中最大的那个9 一定是最近一次刚刚更新的，那么这个9之前会是什么数字呢？

是1，因为只有那个数是1的时候，这个数组加起来才会是9而 1是9-(3+5)得到的
那么[9,3,5]就变成了 [1,3,5]

同样 [1,3,5] ==> [1,3,1] ==> [1,1,1]

好了 知道怎么逆推了之后，可以用一个优先队列，这样子确保每次吐出的是最大的那个数，

```
class Solution {
public:
	bool isPossible(vector<int>& target) {
		priority_queue<int, vector<int>, less<int>> p;
		long long sum = 0;
		for (auto t : target) {
			sum += t;
			p.push(t);
		}
		while (p.top()!=1) {
			long long temp = p.top(); p.pop();
			long long ls = sum - temp;
			sum = temp;
			if (temp < ls) return false;
			temp -= ls;
			p.push(temp);
		}
		return true;
	}
};
```

ps 因为 sum最后加起来很能会是一个超大的数..必须用long long 不然妥妥得出错
