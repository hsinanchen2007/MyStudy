# 相爱相杀好基友——数组与链表
作为线性表的两种存储方式 —— 链表和数组，这对相爱相杀的好基友有着各自的优缺点。接下来，我们梳理一下这两种方式。

**数组**，所有元素都连续的存储于一段内存中，且每个元素占用的内存大小相同。这使得数组具备了通过下标快速访问数据的能力。
但连续存储的缺点也很明显，增加容量，增删元素的成本很高，时间复杂度均为 O(n)。
增加数组容量需要先申请一块新的内存，然后复制原有的元素。如果需要的话，可能还要删除原先的内存。
![数组扩容](https://pic.leetcode-cn.com/98bb83539036be84fdccfeeeea82414aff6dccfdc9652079b8e01dff828fc13e.gif)
删除元素时需要移动被删除元素之后的所有元素以保证所有元素是连续的。增加元素时需要移动指定位置及之后的所有元素，然后将新增元素插入到指定位置，如果容量不足的话还需要先进行扩容操作。

![数组删除元素](https://pic.leetcode-cn.com/3243edbd1f7a9112d8fd5d5e33386c63d4295a992e76e7b7568a55436b54fd14.gif)
总结一下数组的优缺点：
* 优点：可以根据偏移实现快速的随机读写。
* 缺点：扩容，增删元素极慢。

链表，由若干个结点组成，每个结点包含数据域和指针域。结点结构如下图所示：
![链表的一个结点](https://pic.leetcode-cn.com/9448dd3845e74dfbbd1ae6506618cfefcba69e4a27585992c1830e0eb13bc5cb.png)
一般来讲，链表中只会有一个结点的指针域为空，该结点为**尾结点**，其他结点的指针域都会存储一个结点的内存地址。链表中也只会有一个结点的内存地址没有存储在其他结点的指针域，该结点称为**头结点**。
![内存中的链表](https://pic.leetcode-cn.com/df53b2ae43faee93592fea90707455299abe69c378cf317d358b941693e985e9.png)
链表的存储方式使得它可以高效的在指定位置插入与删除，时间复杂度均为 O(1)。
在结点 p 之后增加一个结点 q 总共分三步：
1. 申请一段内存用以存储 q (可以使用内存池避免频繁申请和销毁内存)。
2. 将 p 的指针域数据复制到 q 的指针域。
3. 更新 p 的指针域为 q 的地址。
![插入新元素](https://pic.leetcode-cn.com/760677645fd4b8098e3220d164374a45a3a1b313114e79223d90e0142c10802a.png)

删除结点 p 之后的结点 q 总共分两步：
1. 将 q 的指针域复制到 p 的指针域。
2. 释放 q 结点的内存。
![删除结点](https://pic.leetcode-cn.com/9a602bd1c7778415fa9d54efbd7f405d2d70e9197e35e967e127d36b916d5357.png)
# 链表的主要代码

```cpp
#include <bits/stdc++.h>

using namespace std;

//定义一个结点模板
template<typename T>
struct Node {
	T data;
	Node *next;
	Node() : next(nullptr) {}
	Node(const T &d) : data(d), next(nullptr) {}
};

//删除 p 结点后面的元素
template<typename T>
void Remove(Node<T> *p) {
	if (p == nullptr || p->next == nullptr) {
		return;
	}
	auto tmp = p->next->next;
	delete p->next;
	p->next = tmp;
}

//在 p 结点后面插入元素
template<typename T>
void Insert(Node<T> *p, const T &data) {
	auto tmp = new Node<T>(data);
	tmp->next = p->next;
	p->next = tmp;
}

//遍历链表
template<typename T, typename V>
void Walk(Node<T> *p, const V &vistor) {
	while(p != nullptr) {
		vistor(p);
		p = p->next;
	}
}

int main() {
	auto p = new Node<int>(1);
	Insert(p, 2);
	int sum = 0;
	Walk(p, [&sum](const Node<int> *p) -> void { sum += p->data; });
	cout << sum << endl;
	Remove(p);
	sum = 0;
	Walk(p, [&sum](const Node<int> *p) -> void { sum += p->data; });
	cout << sum << endl;
	return 0;
}
```
# 面试问题总结
无法高效获取长度，无法根据偏移快速访问元素，是链表的两个劣势。然而面试的时候经常碰见诸如**获取倒数第k个元素**，**获取中间位置的元素**，**判断链表是否存在环**，**判断环的长度**等和长度与位置有关的问题。这些问题都可以通过灵活运用双指针来解决。

**Tips：双指针并不是固定的公式，而是一种思维方式~**

先来看"倒数第k个元素的问题"。设有两个指针 p 和 q，初始时均指向头结点。首先，先让 p 沿着 next 移动 k 次。此时，p 指向第 k+1个结点，q 指向头节点，两个指针的距离为 k 。然后，同时移动 p 和 q，直到 p 指向空，此时 p 即指向倒数第 k 个结点。可以参考下图来理解：
![移动过程中保持距离为 k ](https://pic.leetcode-cn.com/b6e913997ffa01167ac3c89fef7172a14fb46d22f20c8eb5db3c663b0523cc3e.png)

```cpp
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *p = head, *q = head; //初始化
        while(k--) {   //将 p指针移动 k 次
            p = p->next;
        }
        while(p != nullptr) {//同时移动，直到 p == nullptr
            p = p->next;
            q = q->next;
        }
        return q;
    }
};
```

获取中间元素的问题。设有两个指针 fast 和 slow，初始时指向头节点。每次移动时，fast向后走两次，slow向后走一次，直到 fast 无法向后走两次。这使得在每轮移动之后。fast 和 slow 的**距离就会增加一**。设链表有 n 个元素，那么最多移动 n/2 轮。当 n 为**奇数**时，slow 恰好**指向中间结点**，当 n 为 **偶数**时，slow 恰好**指向中间两个结点的靠前一个**(可以考虑下如何使其指向后一个结点呢？)。
![快慢指针](https://pic.leetcode-cn.com/98314ddf7f9b28c27c2758c0bf9bdecd5027e1ac24375822b2cfe37f1da683ee.png)
下述代码实现了 n 为**偶数**时慢指针指向**靠后结点**。

```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *p = head, *q = head;
        while(q != nullptr && q->next != nullptr) {
            p = p->next;
            q = q->next->next;
        }
        return p;
    } 
};
```

是否存在环的问题。如果将尾结点的 next 指针指向其他任意一个结点，那么链表就存在了一个环。
![一个有环的链表](https://pic.leetcode-cn.com/dbf5a6b5c2e556e5d2d26ceb9ca22dd8604a7d360312888a2a09ddc018d0f114.png)
上一部分中，总结快慢指针的特性 —— 每轮移动之后两者的距离会加一。下面会继续用该特性解决环的问题。
当一个链表有环时，快慢指针都会陷入环中进行无限次移动，然后变成了追及问题。想象一下在操场跑步的场景，只要一直跑下去，快的总会追上慢的。当两个指针都进入环后，每轮移动使得慢指针到快指针的距离增加一，同时快指针到慢指针的距离也减少一，只要一直移动下去，快指针总会追上慢指针。
![快慢指针在环上追及](https://pic.leetcode-cn.com/d4ca41fafe047519c5343b519d4a3b34e0d22790f665f25303fc524965e60bec.gif)
根据上述表述得出，如果一个链表存在环，那么快慢指针必然会相遇。实现代码如下：
```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != nullptr) {
            fast = fast->next;
            if(fast != nullptr) {
                fast = fast->next;
            }
            if(fast == slow) {
                return true;
            }
            slow = slow->next;
        }
        return nullptr;
    }
};
```
最后一个问题，如果存在环，如何判断环的长度呢？方法是，快慢指针相遇后继续移动，直到第二次相遇。两次相遇间的移动次数即为环的长度。

# 扫码关注 快乐加倍
![](https://pic.leetcode-cn.com/e719e4df9c50046dc15126cd351562f601754ef6b15a59e8f58d3dcdea9e7399.jpg)