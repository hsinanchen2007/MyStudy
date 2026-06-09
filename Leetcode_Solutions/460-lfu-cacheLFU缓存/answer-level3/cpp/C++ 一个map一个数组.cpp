### 解题思路
![image.png](https://pic.leetcode-cn.com/037d60e7f59f3b10adeddb88b34bbccd416f0a1430131cd8876b011e0809ee60-image.png)
经过四次失败，终于AC了。记录一下解题思路。
这道题的关键就是怎么在存满之后删掉最不经常使用的数据。所以我用了一个vector存储key和使用的次数，当使用次数相同的时候还要判断使用时间先后顺序，所以最近使用的数据也需要记录，但是我不想再申请空间记录，所以用了数组的先后顺序作为记录使用的先后顺序，也就是最后一次访问的数据放在数组的尾部，但是这样会造成每次访问数据都移动一次数组，时间复杂度是O(n)。所以我这种方法并不是很好，只能作为一种解题方法。

### 代码

```cpp
class LFUCache {
public:
	LFUCache(int capacity) {
		if (capacity <= 0)
		{
			cachesize = 0;
		}
		else
		{
			cachesize = capacity;
		}
	}

	int get(int key) {
		auto value = data.find(key);
		if (value == data.end())    return -1;
		bool bFind = false;
		pair<int, int> curCache;
		for (int i = 0; i < cache.size() - 1; i++)
		{
			if (cache[i].first == key)
			{
				bFind = true;
				curCache = cache[i];
				curCache.second += 1;
			}
			if (bFind)
			{
				cache[i] = cache[i + 1];
			}
		}
		if (bFind)
		{
			cache[cache.size() - 1] = curCache;
		}
		else {
			cache[cache.size() - 1].second++;
		}
		return value->second;
	}

	void put(int key, int value) {
		if (cachesize == 0)
			return;
		if (data.find(key) != data.end())
		{
			data[key] = value;
			get(key);
			return;
		}
		if (cache.size() == cachesize)
		{
			pair<int, int>* oldCache = FindOldCache(key);
			int delkey = oldCache->first;
			auto itr = data.find(delkey);
			if(itr == data.end())
			{
				return;
			}
			data.erase(itr);
			data[key] = value;
			*oldCache = make_pair(key, 0);
			get(key);
		}
		else
		{
			data[key] = value;
			cache.push_back(make_pair(key, 1));
		}
	}
private:
	pair<int, int>* FindOldCache(int key)
	{
		auto* oldCache = &cache[0];
		for (int i = 1; i < cache.size(); i++)
		{
			if (cache[i].second < oldCache->second)
			{
				oldCache = &cache[i];
			}
		}
		return oldCache;
	}
private:
	map<int, int> data;
	vector<pair<int, int>> cache;
	int cachesize;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```