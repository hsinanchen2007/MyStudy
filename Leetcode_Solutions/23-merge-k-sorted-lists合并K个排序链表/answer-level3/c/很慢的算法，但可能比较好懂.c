![图片.png](https://pic.leetcode-cn.com/a7a65ea1745659fb9b45c8d1eb942c542ff6475bde95e211cb027b567ab848f4-%E5%9B%BE%E7%89%87.png)

每轮都在 k 个链表中找一个最小值插入

```
typedef struct ListNode *List;

List
mergeKLists( List *lists, int listsSize )
{
	List Head = NULL, P = NULL;
	int i = 0, min = 0, minPos = listsSize - 1;
	int flag = 1;

	Head = calloc( 1, sizeof( struct ListNode ) );
	Head->next = NULL;
	P = Head;


	while ( flag == 1 )
	{
		flag = 0;
		min = INT_MAX;
		for ( i = 0; i < listsSize; i++ )
		{
			if ( lists[ i ] != NULL )
			{
				if ( lists[ i ]->val <= min )
				{
					min = lists[ i ]->val;
					minPos = i;
					flag = 1;
				}
			}
		}

		if ( flag == 1 )
		{
			P->next = lists[ minPos ];
			lists[ minPos ] = lists[ minPos ]->next;
			P = P->next;
		}
	}

	P = Head->next;
	free( Head );
	
	return P;
}
```
