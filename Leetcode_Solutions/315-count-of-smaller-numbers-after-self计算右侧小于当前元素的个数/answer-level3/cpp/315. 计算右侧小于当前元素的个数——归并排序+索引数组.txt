本质上是求“逆序对”的数目，可以使用归并排序，但因为需要定位至每个元素的逆序对，所以可以使用索引数组
```
class Solution
{
public:
	vector<int> count;
	vector<int> id;
	vector<int> tmp;

	void Copy(int begin, int size)
	{
		for (int i = begin; i < begin+size; i++) {
			tmp[i] = id[i];
		}
	}

	void Sort(vector<int>& in, int begin, int size)
	{
		if (size <= 1) {
			return;
		} else if (size <= 2) {
			int end = begin + 1;
			if (in[id[begin]] > in[id[end]]) {
				count[id[begin]]++;
				swap(id[begin], id[end]);
			}
			return;
		}
		Sort(in, begin, size / 2);
		Sort(in, begin + size / 2, size - size / 2);
		int rfirst = begin + size / 2;
		int l = begin;
		int r = rfirst;
		Copy(begin, size);
		for (int i = begin; ; i++) {
			if (l >= rfirst) {
				if (r >= begin + size) {
					break;
				}
				id[i] = tmp[r];
				r++;
				continue;
			} else if (r >= begin + size) {
				if (l >= rfirst) {
					break;
				}
				id[i] = tmp[l];
				l++;
				count[id[i]] += r - rfirst;
				continue;
			}
			if (in[tmp[l]] <= in[tmp[r]]) {
				id[i] = tmp[l];
				l++;
				count[id[i]] += r - rfirst;
			} else {
				id[i] = tmp[r];
				r++;
			}
		}
	}
	vector<int> countSmaller(vector<int>& in)
	{
		count.assign(in.size(), 0);
		tmp.assign(in.size(), 0);
		id.assign(in.size(), 0);
		for (int i = 0; i < in.size(); i++) {
			id[i] = i;
		}
		
		Sort(in, 0, in.size());

		return count;
	}
};
```
