### 解题思路
第一眼看这道题，将题目读错了，也意外发现一个加强版的题：它移除并返回栈中出现最频繁的元素及与之相同的元素。但其实，意外发现的加强版题目也是可以写的，但是绝对不会是弹出栈后最大频率减一这么简单，而是需要双向链表实现的栈来写，需要维护一个整数到链表节点指针的映射，push和pop操作对应普通链表的插入和删除操作，具备O(1)时间复杂度，有兴趣的且有疑惑的可以在评论下方留言。
![image.png](https://pic.leetcode-cn.com/6410d23ff92898d1166eb39049bc8843c32bd0777ba388f6bc8ef71bf90a6423-image.png)

### 代码

```cpp
class FreqStack {
public:
	map<int, vector<int>>mp;
	map<int, int>fre;
	stack<int>st;
	int maxf;
	FreqStack() {
		maxf = 0;
	}
	void push(int x) {
		if (fre.count(x) == 0)
			fre[x] = 1;
		else fre[x]++;
		if (mp.count(fre[x]) == 0)
			mp[fre[x]] = vector<int>();
		mp[fre[x]].push_back(x);
		if (maxf < fre[x])
			maxf = fre[x];
	}
	int pop() {
		int res = mp[maxf].back();
		mp[maxf].pop_back();
        fre[res]--;
		if (mp[maxf].size() == 0)maxf--;
		return res;
	}
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
```