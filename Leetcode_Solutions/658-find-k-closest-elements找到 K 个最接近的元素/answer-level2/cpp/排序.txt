### 解题思路
定义结构体num,成员包括数值本身以及与x的差值dif.对该结构体排序并取前k项装入vector中，再对vector排序。

### 代码

```cpp
class Solution {
public:
struct num
{
	int n;
	int dif;
	bool operator<(const num&b)
	{
		if (dif < b.dif)
			return true;
		else if (dif == b.dif)
			return n < b.n;
		else return false;

	}
	friend bool operator<(const num&a,const num&b)
	{
		if (a.dif < b.dif)
			return true;
		else if (a.dif == b.dif)
			return a.n < b.n;
		else return false;

	}
};
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int size = arr.size();
	num*nums = new num[size];
	for (int i = 0; i < size; i++)
		nums[i].n = arr[i], nums[i].dif = (x - arr[i] > 0 ? x - arr[i] : arr[i] - x);
	//priority_queue<num>q;
	sort(nums, nums + size);
	vector<int>res;
	for (int i = 0; i < k; i++)
	{
		res.push_back(nums[i].n);
		//cout << res.back() << " ";
	}
	sort(&res[0], &res[0] + res.size());
    return res;
    }
};
```