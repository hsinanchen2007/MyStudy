
 > 下面内容可能有不严谨的地方，欢迎批评指正。


力扣对于C++特别严格，直接用**链表**`list`或者**变长数组**`vector`都会超时。
```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        vector<int> circle(n);
    	std::iota(n.begin(), n.end(), 0);
        for (int i = (m-1)%circle.size(); circle.size()>1; i=(i+m-1)%circle.size()) {
            circle.erase(circle.begin()+i);
        }
        return circle[0];
    }
};
```
**链表**删除速度快，每次删除为`O(1)`；但查找速度慢，每次找到要删除的数字，都得花费`O(m)`的时间。
**变长数组**查找速度快，每次查找为`O(1)`；但删除速度慢，每次删除都得移动后面的数字，并花费`O(n)`的时间。

所以我希望结合两者，让查找速度和删除速度都比较快，我想到了跳跃链表。

**跳跃链表**与**链表**相似，但它会在链表结点的基础上，间隔着设计一些**关键结点**：

![image.png](https://pic.leetcode-cn.com/8e3e2ca2028b4b629884033113fff5a0894572d56992050b2fe7f613bd897826-image.png)

查找时，可以跳跃式地查找，时间复杂度为`O(log m)`

![image.png](https://pic.leetcode-cn.com/3088f4d62b402ba6404e4d967bb31db9fc3988e93d1b88fd72a874068f16ca1d-image.png)

删除速度与链表接近，时间复杂度为`O(1)`

**结点**和**关键结点**的定义：

```cpp
struct ListNode {
	ListNode(int v) :val(v) {};
	int val;
	ListNode* next = nullptr;
};

struct KeyNode {
	KeyNode(ListNode* n) { node = n; };
	ListNode* node;
	int cnt;	// 计数，从这个**关键结点**到下个**关键结点**之间还有多少**结点**
	KeyNode* next;
	KeyNode* prev;
};
```
首先创建一个如图的链表环。下图展示了`n=6`的情况。外圈为**关键结点**，内圈为**结点**。**关键结点**间隔`sqrt(n)`。

![图片2.png](https://pic.leetcode-cn.com/08238f4f9975f3dd5877f8ae68228b62f637c1d3e930fdd9523e45857f73750a-%E5%9B%BE%E7%89%872.png)


```cpp
int sqrtn = sqrt(n);	// 每 √n 个结点安排一个关键结点，一共 √n 个

ListNode* head = new ListNode(0);	//记录头结点，方便最后成环
ListNode* node = head;

KeyNode* headKey = new KeyNode(head);
KeyNode* key = headKey;

int keyCnt = 1;

for (int i = 1; i < n; i++) {
	node->next = new ListNode(i);
	node = node->next;
	if (keyCnt == sqrtn) {
		key->cnt = keyCnt;
		key->next = new KeyNode(node);
		key->next->prev = key;
		key = key->next;
		keyCnt = 0;
	}
	keyCnt++;
}
node->next = head;	//成环
key->cnt = keyCnt;
key->next = headKey;
key->next->prev = key;
int offset = key->cnt - 1;	// 记录node在key之后偏移了多少
```
此时的**结点**指向5，对应的**关键结点**为4，偏移量`offset=1`
![图片1.png](https://pic.leetcode-cn.com/a698e0383aa93016b930623ccf44248b7ae727eca594d6b263185f87fdc3f06e-%E5%9B%BE%E7%89%871.png)

以此结点为起点，找到第`i`个结点的方法如下。（动图演示的是从`3`开始走`i=5`步找到`1`）
![演示文稿1.gif](https://pic.leetcode-cn.com/a8bf6843be114bd1c73a89c6529562ce2a57c5f6556a0e48cc275f873632afaa-%E6%BC%94%E7%A4%BA%E6%96%87%E7%A8%BF1.gif)
先在**关键结点**间跳跃搜寻（对应代码的`while`部分），然后从**关键结点**开始找到对应**结点**（对应代码`for`部分）。
```cpp
auto advance = [&](int i) {
	while (offset + i >= key->cnt) {
		i -= key->cnt - offset;
		offset = 0;
		key = key->next;
		node = key->node;
	}
	for (int x = 0; x < i; x++) {
		offset++;
		node = node->next;
	}
};
```

接着就可以跳到对应位置，并删除对应的节点啦~！
```cpp
for (advance((m - 1) % n); n > 1; advance((m - 1) % n)) {
	// 删除当前结点的下一个结点
	node->next = node->next->next;

	// 如果下一个结点正好是下一个关键结点
	if (offset == key->cnt - 1) {
		//将下一个关键结点移到下下个结点
		key->next->cnt--;
		key->next->node = key->next->node->next;
		if (key->next == key)
			offset--;
	}
	else {
		key->cnt--;
	}

	// 删除所有空的关键结点
	while (key->next->cnt <= 0) {
		key->next = key->next->next;
		key->next->prev = key;
	}
	while (key->cnt <= 0) {
		key->prev->next = key->next;
		key->next->prev = key->prev;
		key = key->next;
	}
	n--;
}
```

因为要执行`n-1`次查找和删除，因此最终的时间复杂度为`O(n log m)`。
代码很长，执行用时也属于倒数水平（984 ms，勉强过关）。但是相对数学方法要好理解得多（个人感觉）。

---

完整程序如下：
```cpp
class Solution {
public:
	struct ListNode {
		ListNode(int v) :val(v) {};
		int val;
		ListNode* next = nullptr;
	};
	struct KeyNode {
		KeyNode(ListNode* n) { node = n; };
		ListNode* node;
		int cnt;
		KeyNode* next;
		KeyNode* prev;
	};
	int lastRemaining(int n, int m) {
		int sqrtn = sqrt(n);

		ListNode* head = new ListNode(0);
		ListNode* node = head;

		KeyNode* headKey = new KeyNode(head);
		KeyNode* key = headKey;

		int keyCnt = 1;

		for (int i = 1; i < n; i++) {
			node->next = new ListNode(i);
			node = node->next;
			if (keyCnt == sqrtn) {
				key->cnt = keyCnt;
				key->next = new KeyNode(node);
				key->next->prev = key;
				key = key->next;
				keyCnt = 0;
			}
			keyCnt++;
		}
		node->next = head;
		key->cnt = keyCnt;
		key->next = headKey;
		key->next->prev = key;
		int offset = key->cnt - 1;

		auto advance = [&](int i) {
			while (offset + i >= key->cnt) {
				i -= key->cnt - offset;
				offset = 0;
				key = key->next;
				node = key->node;
			}
			for (int x = 0; x < i; x++) {
				offset++;
				node = node->next;
			}
		};
		for (advance((m - 1) % n); n > 1; advance((m - 1) % n)) {
			node->next = node->next->next;
			if (offset == key->cnt - 1) {
				key->next->cnt--;
				key->next->node = key->next->node->next;
				if (key->next == key)
					offset--;
			}
			else {
				key->cnt--;
			}
			while (key->next->cnt <= 0) {
				key->next = key->next->next;
				key->next->prev = key;
			}
			while (key->cnt <= 0) {
				key->prev->next = key->next;
				key->next->prev = key->prev;
				key = key->next;
			}
			n--;
		}
		return node->val;
	}
};
```