### 解题思路
优先级队列

### 代码

```cpp
int*count1;
class Solution {
public:
int maxm=static_cast<int>(pow(2,31)-1);
struct Num
{
	int belong;
	int val;
	friend bool operator<(const Num&a, const Num&b)
	{
		if (a.val < b.val)
			return true;
		else if (a.val == b.val)
			return count1[a.belong] < count1[b.belong];
		else return false;
	}
	bool operator<( const Num&b)
	{
		if (val < b.val)
			return true;
		else if (val == b.val)
			return count1[belong] < count1[b.belong];
		else return false;
	}
};
    vector<int> smallestRange(vector<vector<int>>& nums) {
    Num t;
	int size = nums.size();
    count1 = new int[size];
	for (int i = 0; i < size; i++)
		count1[i] = 0;
	priority_queue<Num>q;
	int ct = 0;
	int start2 = 0;
	int end2 = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < nums[i].size(); j++)
		{
			t.val = nums[i][j];
			t.belong = i;
			q.push(t);
			count1[i]++;
		}
	}
	bool finish = false;
	int res;
	int*count3 = new int[size];
	for (int i = 0; i < size; i++)
		count3[i] = 0;
	int min = maxm;
	queue<Num>q2;
	while (q.size() != 0)
	{
		t = q.top();
		q2.push(t);
		if (count3[t.belong] == 0)
		{
			ct++;
		}
		count3[t.belong]++;
		q.pop();
		if (ct == size)
		{
			while (q2.size()>0&&ct==size)
			{
				t = q2.front();
				count3[t.belong]--;
				q2.pop();
				if (t.val - q2.back().val <= min)
				{
					min = t.val - q2.back().val;
					start2 = q2.back().val;
					end2 = t.val;
				}
				if (count3[t.belong] <= 0)
				{
					ct--;
					break;
				}
			}
		}
	};
    vector<int>resu;
    resu.push_back(start2);
    resu.push_back(end2);
	return resu;
    }
};
```