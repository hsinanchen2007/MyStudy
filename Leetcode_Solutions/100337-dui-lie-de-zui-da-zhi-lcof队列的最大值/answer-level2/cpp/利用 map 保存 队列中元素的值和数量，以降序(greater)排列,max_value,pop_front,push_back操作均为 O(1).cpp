### 解题思路
思路：
  1. 要完成max_value,pop_front,push_back操作毫无疑问首先想到的是  set/map
  2. max_value，将哈希表降序排列，之后取第一个 hash元素的键值即可
  3. push_back，将哈希表和队列均添加其元素
  4. pop_front，出队，哈希表对应其出队元素的键，其值减一（代表该元素已经出队，不进行保存），如果减一后该 键值对的值为0，则删除其键值
### 代码

```cpp
class MaxQueue {
public:
	MaxQueue() {
		maxMap={};
        que={};
	}

	int max_value() {
		return (maxMap.size()==0 ? -1 : maxMap.begin()->first);
	}

	void push_back(int value) {
       que.push(value);
       ++maxMap[value];
	}

	int pop_front() {
        cout<<que.size()<<ends;
		if(que.size() == 0)
			return -1;
		int val = que.front();
		que.pop();
		if(--maxMap[val]==0) maxMap.erase(val);
        
		return  val;
	}
private:
	map<int,int,greater<int>> maxMap;
	queue<int> que;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```