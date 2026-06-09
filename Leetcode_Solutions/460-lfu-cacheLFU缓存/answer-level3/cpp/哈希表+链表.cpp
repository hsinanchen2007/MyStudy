链表的节点: pair<访问频率, 键值对链表指针>
键值对链表: pair<key, value>, 新值放在尾
哈希表:     pair<key, pair<链表中的节点的迭代器, 键值对节点的迭代器>>    记录该key在链表中的准确位置

```C++
class LFUCache {
	typedef pair<unsigned int, list<pair<int, int>>* > orderNode;
	typedef pair<list<orderNode>::iterator, list<pair<int, int>>::iterator> mapValue;
	std::unordered_map<int, mapValue> cache;
	std::list<orderNode> order;
	int maxIn;
	int curIn;
public:
	LFUCache(int capacity) {
		maxIn = capacity;
		curIn = 0;
	}

	void update(mapValue& p, int key, int value) {
		int curFreq = p.first->first;
		list<orderNode>::iterator iter = ++(p.first); --p.first;
		if (iter == order.end() || iter->first != curFreq + 1) {
			iter = order.insert(iter, orderNode(curFreq + 1, new list<pair<int, int>>));
		}
		iter->second->push_back(make_pair(key, value));
		cache[key] = make_pair(iter, --(iter->second->end()));
	}

	void del(mapValue& p) {
		list<pair<int, int>>* tar = p.first->second;
		tar->erase(p.second);
		if (tar->empty()) {
			delete tar;
			tar = nullptr;
			order.erase(p.first);
		}
	}

	int get(int key) {
		if (cache.find(key) != cache.end()) {
			mapValue p = cache[key];
			int value = p.second->second;
			update(p, key, value);
			del(p);
			return value;
		}
		else {
			return -1;
		}
	}

	void put(int key, int value) {
		if (maxIn == 0) return;
		if (cache.find(key) == cache.end()) {
			if (curIn == maxIn) {
				int delkey = order.begin()->second->begin()->first;
				mapValue p = cache[delkey];
				cache.erase(delkey);
				del(p);
				curIn--;
			}
			if (order.empty() || order.begin()->first != 1) {
				order.push_front(orderNode(1, new list<pair<int, int>>));
			}
			order.begin()->second->push_back(make_pair(key, value));
			cache[key] = make_pair(order.begin(), --(order.begin()->second->end()));
			curIn++;
		}
		else {
			mapValue p = cache[key];
			update(p, key, value);
			del(p);
		}
	}
};
```
最快144ms吧