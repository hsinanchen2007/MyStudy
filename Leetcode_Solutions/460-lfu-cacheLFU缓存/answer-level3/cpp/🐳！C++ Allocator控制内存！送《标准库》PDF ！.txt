## 结构设计
cache 基于两层list实现。第一层为出现的次数，第二层为具体的元素。
router 是一个 unordered_map。记录每个 key 在 cache 中的位置。 
具体结构如下图所示：
![LFU.png](https://pic.leetcode-cn.com/c5f758cb360e8d6bf6ecf9b06672bc26b99fabf892a376c8e9cfd3a2d9023482-LFU.png)

## 功能设计
### GET
**时间复杂度：O(1)**

直接访问 router，判断 key 是否存在：
* 不存在，返回 -1。
* 存在，通过router中缓存的位置，直接访问对应的数据链表结点，返回数据。

### PUT
**时间复杂度：O(1)**
首先判断 key 是否在 router 中：
* 如果在，直接更新对应数据链表结点的值，并调用 updateFreq 更新访问次数。PUT结束。
* 如果不存在。则判断是否已满：若已满先调用 swapOut (该函数会按LFU规则淘汰一个元素，后面会讨论)。
* 判断次数为1的频次链表结点是否存在，不存在则创建。
* 将数据插入到次数为 1 的数据链表。并更新 router。PUT 结束。

以插入(key = 5, val = 5) 为例，图示如下：
![LFU插入.png](https://pic.leetcode-cn.com/46287cb09c76bd0ed7243c70a6bc2a24237e5ad3545dd130f4f8a811aa50e1cd-LFU%E6%8F%92%E5%85%A5.png)
### updateFreq
**时间复杂度：O(1)**
每次更新或查询，对应元素的频次只会增加一，也就是说对应的数据结点**应从当前的数据链表移动到下一个数据链表**，如果下一个数据链表**不存在或者对应的频次不符**，则应创建新的数据链表。
以更新(key=5, val = 5)为例，过程如下图示：

<![](https://pic.leetcode-cn.com/d41d72efe878cb6965a3a4371ae7341a3c781d41f0d9f71511472b7c5b2410a2-1.png),![](https://pic.leetcode-cn.com/6a3b1ddd96e07276cc901096737db7a14dca7787b74a9031fdd29e2248a48086-2.png)>

### swapOut
**时间复杂度：O(1)**
弹出频次最小的数据链表的最后一个元素，并删除router。
![LFU-swapout.png](https://pic.leetcode-cn.com/b8844ce65cdc4dac9b029bbf0a4453caf34e72066d7562e54afad6214072b925-LFU-swapout.png)

## 代码实现

```cpp
//为 list 自定义一个内存管理类模板
template<typename T>
class SingleAlloctor {
	enum {
		MAXN = 5000,
	};
	static T *data;    //内存池为全局变量，防止重复申请。
	static int current;
	static int pool[MAXN]; //pool本质上是一个链表；current 为头结点，标记了哪些data可用。
	public:
		typedef T value_type;
		T * allocate(int num) {
			int cur = current;
			current = pool[current];
			return data + cur;
		}
		void deallocate(T *p, std::size_t) {
			ptrdiff_t offset = p-data;
			pool[offset] = current;
			current = offset;
		}
		SingleAlloctor() {
            if(data != nullptr) { //应该还有对应的delete，哈哈偷懒了。
                return;
            }
			data = static_cast<T*>(::operator new (MAXN * sizeof(T)));
			for(int i = 0; i < MAXN; i++) {
				pool[i] = i-1;
			}
			current = MAXN-1;
		}
};

template<typename T>
int SingleAlloctor<T>::current;

template<typename T>
int SingleAlloctor<T>::pool[SingleAlloctor<T>::MAXN];

template<typename T>
T *SingleAlloctor<T>::data = nullptr;

class LFUCache {
    struct FreqNode;
	typedef list<FreqNode, SingleAlloctor<FreqNode>> FreqList;

	struct DataNode {
		int key;     //索引
		int value;   //数据
		FreqList::iterator fit; //对应的频次链表的结点
		DataNode(int k = 0, int v = 0, FreqList::iterator f = FreqList::iterator())
			: key(k), value(v), fit(f) {}
	};
	typedef list<DataNode, SingleAlloctor<DataNode>> DataList;

    struct FreqNode {
        int cnt;      //频次
        DataList dataList;  //对应的数据结点列表
		FreqNode(int c = 0) : cnt(c) {}
    };
	FreqList cache;
	unordered_map<int, DataList::iterator> router;

	size_t capacity;

	void updateCache(int key) {
		auto rit = router.find(key);
		auto it = rit->second;
		if(it->fit == cache.begin()) {
			cache.push_front(FreqNode(it->fit->cnt+1)); //更高频次的结点不存在，创建它！
		} else {
			FreqList::iterator pre = it->fit; --pre;    
			if(pre->cnt != it->fit->cnt+1) {       // 更高频次的结点频次不匹配，插入一个新的。
				cache.insert(it->fit, FreqNode(it->fit->cnt+1));
			}
		}
		auto curIt = it->fit;          //从当前数据链表断开，插入到更高频次的数据链表。
		auto preIt = it->fit; --preIt;
		preIt->dataList.push_front(DataNode(key, it->value, preIt));
		curIt->dataList.erase(it);
		rit->second = preIt->dataList.begin(); //更新 router
	}

	void swapOut() {
		for(auto it = --cache.end(); ;) {
			if(it->dataList.size()) { //删除最后一个
				auto out = it->dataList.back();
				router.erase(out.key);
				it->dataList.pop_back();
				break;
			} else {       //可能存在若干个空的数据链表，清楚它。均摊 O(1)。
				cache.erase(it--);
			}
		}
	}
    
public:
    LFUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
		auto it = router.find(key);
		if(it == router.end()) {
			return -1;
		}
		int val = it->second->value;
		updateCache(key);
		return val;
    }

    void put(int key, int value) {
		if(capacity == 0) {
			return;
		}
		auto rit = router.find(key);
		if(rit != router.end()) {
			rit->second->value = value; //key已存在，更新value。
			updateCache(key);
		} else {
			if(router.size() == capacity) {
				swapOut();
			}
			if(cache.empty() || cache.back().cnt != 1) {
				cache.push_back(FreqNode(1)); //不存在频次为 1 的数据链表，创建一个。
			}
			auto it = --cache.end();
			it->dataList.push_front(DataNode(key, value, it)); //插入到数据链表。
			router.insert(make_pair(key, it->dataList.begin())); //更新router
		}
    }
};
```

**对STL不熟悉的小伙伴，可以关注公众号回复 "CPP标准库" 获取相关PDF哦。**
# 如果感觉有点意思，可以关注👏HelloNebula👏
* **分享周赛题解**
* **分享计算机专业课知识**
* **分享C++相关岗位面试题**
* **分享专业书籍PDF**

![qrcode_for_gh_6e5f8557b1f8_258.jpg](https://pic.leetcode-cn.com/05e5a3b25cb51d114880f718c50446c6a6e9d3f242c7418e6b6e52fb2db48994-qrcode_for_gh_6e5f8557b1f8_258.jpg)


