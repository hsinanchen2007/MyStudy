### 解题思路
使用map配合bitset记录状态

### 代码

```cpp
class Solution {
public:
struct Bits
{
	bitset<12>bits;
	friend bool operator<(const Bits&a, const Bits&b)
	{
		return a.bits.to_ulong() < b.bits.to_ulong();
	}
	bool operator<( const Bits&b)
	{
		return bits.to_ulong() < b.bits.to_ulong();
	}
};
    int shortestPathLength(vector<vector<int>>& graph) {
    /*if(graph.size()==2)
        return 1;
    int size = graph.size();
	bool*access = new bool[size];
	for (int i = 0; i < size; i++)access[i] = false;
	bool finish = false;
	queue<int>q1;
	queue<bitset<12>>q2;
	queue<int>length;
	for (int i = 0; i < size; i++)
	{
		q1.push(i);
		bitset<12>t;
		t.reset();
		t.set(i, 1);
		q2.push(t);
		length.push(0);
	}
	if (size == 1)
		finish = true;
	while (!finish)
	{
		int h = length.front();
		for (int i = 0; i < graph[q1.front()].size(); i++)
		{
			bitset<12>t = q2.front();
			q1.push(graph[q1.front()][i]);
			t.set(graph[q1.front()][i],1);
			if (t.count() == size)
			{
				finish = true;
				break;
			}
			q2.push(t);
			length.push(h + 1);
		}
		q1.pop();
		q2.pop();
		length.pop();
	}*/
    if (graph.size() == 2)
		return 1;
	int size = graph.size();
	bool*access = new bool[size];
	for (int i = 0; i < size; i++)access[i] = false;
	bool finish = false;
	queue<int>q1;
	queue<Bits>q2;
	map<Bits, map<short int, bool>>acc;
	queue<int>length;
	int temp;
	for (int i = 0; i < size; i++)
	{
		q1.push(i);
		Bits t;
		t.bits.reset();
		t.bits.set(i, 1);
		q2.push(t);
		length.push(0);
		acc[t][i] = true;
	}
	if (size == 1)
		finish = true;
	while (!finish)
	{
		int h = length.front();
		temp = q1.front();
		for (int i = 0; i < graph[temp].size(); i++)
		{
			Bits t = q2.front();
			t.bits.set(graph[temp][i], 1);
			if (acc.count(t) != 0)
				if (acc[t].count(graph[temp][i]) != 0)
					continue;
			acc[t][graph[temp][i]] = 1;
			q1.push(graph[temp][i]);
            length.push(h + 1);
			if (t.bits.count() == size)
			{
				finish = true;
				break;
			}
			q2.push(t);
		}
		q1.pop();
		q2.pop();
		length.pop();
	}
	return length.back();
    }
};
```