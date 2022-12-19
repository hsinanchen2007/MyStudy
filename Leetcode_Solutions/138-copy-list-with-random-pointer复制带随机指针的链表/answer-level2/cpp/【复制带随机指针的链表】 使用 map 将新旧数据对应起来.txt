### 思路
1. 思路和 133.CloneGraph 差不多。  
2. 利用 map ，将原始数据和新数据对应起来。  

### 方法  
1. 建立 map 。`map<Node *, Node *> visited;`
2. 别忘了 NULL 指针加入 map ，这样当指针为 NULL 时也能好好对应。`visited[NULL] = NULL;`
3. 使用标准链表遍历方式。 `while (pNode != NULL) pNode = pNode->next;`
4. new 新的 Node ，并保存在 map 中。
5. 指针回到 head ，再遍历一遍链表，用来复制 Node 中的数据。
6. 需要复制的有：`val`, `random`, `next`。
7. 返回新数据的 head 指针，没错，就是 `visited[head]` 。


### 答题
``` C++
Node* copyRandomList(Node* head)
{
	map<Node *, Node *> visited;
	visited[NULL] = NULL;

	Node *pPrev = NULL;
	Node *pNode = head;
	while (pNode != NULL)
	{
		Node *pNew = new Node();
		visited[pNode] = pNew;
		pNode = pNode->next;
	}
	pNode = head;
	while (pNode != NULL)
	{
		Node *pNew = visited[pNode];
		pNew->val = pNode->val;
		pNew->random = visited[pNode->random];
		pNew->next = NULL;
		if (pPrev != NULL)
		{
			visited[pPrev]->next = pNew;
		}
		pPrev = pNode;
		pNode = pNode->next;
	}
	return visited[head];
}
```



### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)