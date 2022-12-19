### 题目
根据题目描述，正面突破，就按照他的方法折腾。  

示例:  

输入：  
|      |      |      |      |      |      |      |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 1    | 2    | 3    | 4    | 5    | 6    | NULL |
|      |      | \|   |      |      |      |      |
|      |      | 7    | 8    | 9    | 10   | NULL |
|      |      |      | \|   |      |      |      |
|      |      |      | 11   | 12   | NULL |      |

输出:  
1-2-3-7-8-11-12-9-10-4-5-6-NULL

↑↑ 可以结合示例查看 ↑↑

### 思路
1. 按照正常链表那么遍历。```pNode = pNode->next;```
2. 当child不为空时进行特殊处理。
3. 先把原来的next存一份。（例：把4号存起来）
4. 把next接成新的child，因为双向链表，记得接新next的prev。
5. 然后把child干掉。```pNode->child = NULL;```
6. 这一步递归去扁平化原来child的链表，因为新的链表有可能有新的分支。
7. 递归之后把结点跑到最后一个结点。（例：跑了7--8--11--12--9--10。多亏了上一步操作，8号那里又递归了）
8. 把跑到最后的那个结点的next接上。
9. 如果第3步存的next不为空，记得接上prev。
10. 返回原head。

**大功告成**  


### 答题
```C++
Node* flatten(Node* head) 
{
	Node *pNode = head;
	while (pNode != NULL)
	{
		if (pNode->child != NULL)
		{
			Node *pNext = pNode->next;
			pNode->next = pNode->child;
			pNode->next->prev = pNode;
			pNode->child = NULL;
			flatten(pNode);
			while (pNode != NULL && pNode->next != NULL) pNode = pNode->next;
			pNode->next = pNext;
			if (pNext != NULL) pNext->prev = pNode;		
		}
		pNode = pNode->next;
	}
	return head;
}
```



### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)