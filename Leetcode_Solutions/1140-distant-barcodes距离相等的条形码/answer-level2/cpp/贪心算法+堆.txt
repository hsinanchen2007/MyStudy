### 解题思路
构建一个大根堆，以每个条形码在数组中出现的次数为依据进行比较，设返回的vector为re，re从0到barcodes.size()-1，每次取出堆顶。若堆顶和re的最后一个元素相同，则定义一个temp来保存堆的top()，将堆pop()，然后在re尾部添加堆顶所对应的数值，将堆顶的amount减一，存到temp中，堆pop（）后再将temp放入堆中。若堆顶和re的最后一个元素不同，在re尾部添加堆顶所对应的数值，将堆顶的amount减一，存到temp中，堆pop（）后再将temp放入堆中。

### 代码

```cpp
class Solution {
public:
struct Bar
{
	int amount;//出现次数
	int num;//大小;
	bool operator>(const Bar&a)
	{
		return amount > a.amount;
	}
	friend bool small(const Bar&b, const Bar&a)
	{
		return b.amount > a.amount;
	}
	friend bool operator<(const Bar&b, const Bar&a)
	{
		return b.amount < a.amount;
	}
};
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    if(barcodes.size()<=1)
    return barcodes;
    int size = barcodes.size();
	Bar temp;
	vector<Bar>bars;
	map<int, int>mp;
	for(int i=0;i<size;i++)
		if (mp.count(barcodes[i]) == 0)
		{
			temp.amount = 1;
			temp.num = barcodes[i];
			mp[barcodes[i]] = bars.size();
			bars.push_back(temp);
		}
		else bars[mp[barcodes[i]]].amount++;
	//sort(&bars[0], &bars[0] + bars.size());
	/*for (int i = 0; i < bars.size(); i++)
		cout << bars[i].num << " " << bars[i].amount << endl;*/
	priority_queue<Bar>q;
	for (int i = 0; i < bars.size(); i++)q.push(bars[i]);
	//cout << q.top().num << endl;
	vector<int>re;
	while (re.size() < size)
	{
		if (re.size() == 0)
		{
			re.push_back(q.top().num);
			temp = q.top();
			q.pop();
			temp.amount--;
			q.push(temp);
		}
		else
		{
			if (re[re.size() - 1] == q.top().num)
			{
				Bar temp2 = q.top();
				q.pop();
				re.push_back(q.top().num);
				temp = q.top();
				q.pop();
				temp.amount--;
				q.push(temp);
				q.push(temp2);
			}
			else
			{
				temp = q.top();
				re.push_back(temp.num);
				q.pop();
				temp.amount--;
				q.push(temp);
			}
		}
	}
	return re;
    }
};
```