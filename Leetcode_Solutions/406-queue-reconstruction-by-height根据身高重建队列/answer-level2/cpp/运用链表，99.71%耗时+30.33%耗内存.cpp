### 解题思路
先对人从高到矮排序，同身高则k值小的优先，对排序后的数组从第一个数组元素，到最后一个数组元素，依次插入一个链表，对数组中的每个人，对链表从头开始遍历，直到身高比当前人高的人数大于等于k时结束遍历，并将该人插入链表，依次执行该过程就可以得到答案。
![image.png](https://pic.leetcode-cn.com/5a3e85907f1008a7074f517d51e898d1136239e84ce8ce79f5905f8cf31b6b4f-image.png)

### 代码

```cpp
class Solution {
public:
template<typename T>
class ListNode
{
public:
	ListNode()
	{
		val;
		next = NULL;
	}
	ListNode(T v)
	{
		val = v;
	}
	ListNode(T v, ListNode*n)
	{
		val = v;
		next = n;
	}
	T val;
	ListNode*next;
};
template<typename T>
class List
{
public:
	List()
	{
		head = new ListNode<T>();
	}
	void insert(ListNode<T>*ptr, ListNode<T>*node)
	{
		ListNode<T>*temp = ptr->next;
		ptr -> next = node;
		node->next = temp;
	}
	ListNode<T>*head;
};
struct hk
{
	int h;
	int k;
	bool operator<(const hk&p)
	{
		if (h > p.h)
			return true;
		else if (h == p.h)
			return k < p.k;
        else return false;
	}
	friend bool operator<(const hk&a,const hk&p)
	{
		if (a.h > p.h)
			return true;
		else if (a.h == p.h)
			return a.k < p.k;
            else return false;
	}
	bool operator>(const hk&p)
	{
		if (h < p.h)
			return true;
		else if (h == p.h)
			return k > p.k;
            else return false;
	}
	bool operator<=(const hk&p)
	{
		if (h >= p.h)
			return true;
		else if (h == p.h)
			return k < p.k;
            else return false;
	}
	bool operator>=(const hk&p)
	{
		if (h <= p.h)
			return true;
		else if (h == p.h)
			return k < p.k;
            else return false;
	}
};

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int size = people.size();
	hk*arr = new hk[size];
	for (int i = 0; i < size; i++)
	{
		arr[i].h = people[i][0];
		arr[i].k = people[i][1];
	}
	sort(arr, arr + size);
	List<hk>lst;
	lst.head->val.h = -1;
	lst.head->val.k = 0;
	int count = 0;
	ListNode<hk>*temp;
	for (int i = 0; i < size; i++)
	{
		temp = lst.head;
		count = 0;
		while (count < arr[i].k)
		{
			temp = temp->next;
			if (temp->val.h >= arr[i].h)
				count++;
		}
		ListNode<hk>*ptr = new ListNode<hk>();
		ptr->val = arr[i];
		ptr->next = NULL;
		lst.insert(temp, ptr);
	}
	temp = lst.head->next;
	vector<vector<int>>re;
	while (temp != NULL)
	{
		re.push_back(vector<int>());
		re[re.size() - 1].push_back(temp->val.h);
		re[re.size() - 1].push_back(temp->val.k);
		temp = temp->next;
	}
    return re;
    }
};
```