### 解题思路
看到本题，我的第一反应是循环数组的思想。
所以，引入了两个指针，指向已考虑的加油站的左边和右边。
其中，给出两种方法。

### 代码
法一：先不判断总量的相对大小，而是计算两者的差值存到diff数组中，并找出diff中的最大值并开始循环。
```
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	vector<int> diff;
	int max = gas[0] - cost[0];
	int max_idx = 0;
	for (int i = 0; i < gas.size(); i++)
	{
		diff.push_back(gas[i] - cost[i]);
		if (diff[i] > max)
		{
			max = diff[i];
			max_idx = i;
		}
	}
	if (max < 0)
		return -1;
	int left = max_idx;
	int right = left == diff.size() - 1 ? 0 : left + 1;
	int temp=diff[left] + diff[right];
	while (right != left)
	{
		if (temp >= 0)
		{
			right = right == diff.size() - 1 ? 0 : right + 1;
			temp += diff[right];
		}
		else
		{
			left = left == 0 ? diff.size() - 1 : left - 1;
			temp += diff[left];
		}
	}
	return temp >= 0?left:-1;
}
```

法二：优化：先通过计算gas和cost的总量进行判断，如果满足条件才进行后面的运算。
TIPS： accumulate为std中的累加函数！！
```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	if (gas.size() == 1)
		return gas[0] >= cost[0] ? 0 : -1;
	int gas_sum = accumulate(gas.begin(), gas.end(),0);//0为累加的初值
	int cost_sum = accumulate(cost.begin(), cost.end(), 0);
	if (gas_sum < cost_sum )//这里进行初始判断，如果总汽油量小于总花费量直接返回-1.
		return -1;
	int left = 0;//由于条件以满足，故left可以任意赋初值。
	int right = 1;
	int temp = gas[left]-cost[left];
    int N=gas.size();
	while (right != left)
	{
		if (temp >= 0)
		{
			temp += gas[right] - cost[right];//这里要先加再改right，因为之前还没有加
			right = right == N - 1 ? 0 : right + 1;
		}
		else
		{
			left = left == 0 ? N - 1 : left - 1;//这里要先改left再加。
			temp += gas[left] - cost[left];
		}
	}
	return left;
}
};

```