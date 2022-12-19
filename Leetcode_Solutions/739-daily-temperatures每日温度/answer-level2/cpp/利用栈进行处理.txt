### 解题思路
求之后某一天温度大于当前天数问题，显然应该先知道后面的信息，所以很容易想到倒过来循环遍历；
温度和顺序有关，且找的是最近的那一天的温度，存储的数据结构那就是栈了；
接下里就是剪枝，如果当前的温度比之前的都大，之前的温度信息就没有存在的必要了；
如果不是，就将其插入；
同时由于如果只是将温度值插入，没法获取天数信息，所以需要开一个int单独存储对应的index.

### 代码

```cpp
class Solution {
public:
struct node {
	int index;
	int tempreature;
};

vector<int> dailyTemperatures(vector<int>& T) {
	stack<node> temperatureNode;
	stack<int> stackResults;
	for (int i = T.size() - 1; i >= 0; i--) {
		node temp;
		temp.index = i;
		temp.tempreature = T[i];
		while (!temperatureNode.empty() && temperatureNode.top().tempreature <= T[i])
		{
			temperatureNode.pop();
		}
		if (temperatureNode.empty()) {
			stackResults.push(0);
		}
		else {
			stackResults.push(temperatureNode.top().index - i);
		}
		temperatureNode.push(temp);

	}
	vector<int> results;
	while (!stackResults.empty()) {
		results.push_back(stackResults.top());
		stackResults.pop();
	}
	return results;
}
};
```