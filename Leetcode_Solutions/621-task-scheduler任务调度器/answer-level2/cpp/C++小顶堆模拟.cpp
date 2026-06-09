提交通过。将每种任务当前剩余的执行次数保存到priority_queue中自动降序。模拟执行时借用另一个priority_queue临时保存剩余次数。
```
class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		int time_count = 0;
		unordered_map<char, int> hash;
		for (auto a : tasks) {
			hash[a]++;//统计各种任务出现的次数
		}
		priority_queue<int>queue1, queue2;
		for (auto a : hash) {
			queue1.push(a.second);
		}
		bool end_in_this_round = false;
		while (1) {
			if (queue1.empty())return time_count;//queue1.top() == 1表明即将执行最后一轮
			if (queue1.top() == 1)end_in_this_round = true;
			for (int i = 0; i <= n; ++i) {//循环n+1次因为只要不退出，每轮必消耗n+1单位时间
				++time_count;
				if (!queue1.empty()) {//queue1中的任务执行一次，保存到queue2中
					if (queue1.top() > 1)queue2.push(queue1.top() - 1);
					queue1.pop();
				}
				else {
					if (end_in_this_round)return time_count - 1;
				}
			}
			while (!queue1.empty()) {
				queue2.push(queue1.top());//将未执行的任务搬运到queue2
				queue1.pop();
			}
			swap(queue1, queue2);//交换引用
		}
	}
};
```

