### 解题思路
此处撰写解题思路

### 代码

```cpp
class LRUCache {
protected:
	//哈希函数 算槽位 求mod
	//这样能快速查找
	//槽位再被组织成链表
	struct node
	{
		int m_nMe;//自己的索引ID 找到自己
		int m_nPre;//这2个是用来表示先后关系的
		int m_nNext;//这2个是用来表示先后关系的
		int m_nBefore;//这两个是用来对哈希进行拉链的(如果为负数表示指向m_pIndexs的索引)
		int m_nAfter;//这两个是用来对哈希进行拉链的
		int m_nKey;//健
		int m_nValue;//数值
	};
	int NewSlot()
	{
		int nIndexResult = 0;
		if (m_nIdle != 0)
		{
			nIndexResult = m_nIdle;
			m_nIdle = m_pCaches[m_nIdle].m_nNext;
			return nIndexResult;
		}
		//进行回收
		nIndexResult = m_nTail;
		//维护最近最少使用队列
		m_nTail = m_pCaches[m_nTail].m_nPre;
		if (m_nTail != 0)
		{
			m_pCaches[m_nTail].m_nNext = 0;
		}
		else
		{
			//这种情况下头跟尾是一个，所以要影响头
			m_nHead = 0;
		}
		//被释放的节点要处理他的拉链
		if (m_pCaches[nIndexResult].m_nBefore<0)
		{
			//他是第一个节点
			//m_pIndexs的指向
			m_pIndexs[-m_pCaches[nIndexResult].m_nBefore] = m_pCaches[nIndexResult].m_nAfter;
			
		}
		else
		{
			//不是第一个节点
			//到了这个分支，肯定有before 节点
			m_pCaches[m_pCaches[nIndexResult].m_nBefore].m_nAfter = m_pCaches[nIndexResult].m_nAfter;
			
		}
		//处理在他后面的节点
		if (m_pCaches[nIndexResult].m_nAfter != 0)
		{
			m_pCaches[m_pCaches[nIndexResult].m_nAfter].m_nBefore = m_pCaches[nIndexResult].m_nBefore;
		}
		return nIndexResult;
	}
	void visited(int nIndex)
	{
		if (m_nHead != nIndex)
		{
			//本来在头部不该有啥变化
			//断开他原来的链接
			int nPre = m_pCaches[nIndex].m_nPre;
			int nNext = m_pCaches[nIndex].m_nNext;
			if (nPre != 0)
			{
				m_pCaches[nPre].m_nNext = m_pCaches[nIndex].m_nNext;
			}
			if (nNext != 0)
			{
				m_pCaches[nNext].m_nPre = m_pCaches[nIndex].m_nPre;
			}
		
			//避免自己指向自己
			m_pCaches[nIndex].m_nNext = m_nHead;
			m_pCaches[m_nHead].m_nPre = nIndex;
			m_nHead = nIndex;
		}
		if (nIndex == m_nTail)
		{
			//尾巴指向了他
			if (m_pCaches[m_nTail].m_nPre != 0)
			{
				m_nTail = m_pCaches[m_nTail].m_nPre;
			}
			//否则只有1个节点，还指向它吧
		}
		m_pCaches[nIndex].m_nPre = 0;
	}
public:
	LRUCache(int capacity)
	{
		if (capacity<0)
		{
			capacity = 1;
		}
		m_capacity = capacity;
		//0号不用，不然判定太不习惯了
		m_pCaches = new node[m_capacity + 1];
		m_pIndexs = new  int[m_capacity + 1];
		m_nHead = 0;
		m_nTail = 0;
		m_nIdle = 1;//指向第一个空闲
		for (int i = 1; i <= m_capacity; ++i)
		{
			m_pCaches[i].m_nMe = i;
			m_pCaches[i].m_nNext = i + 1;
		}
		m_pCaches[m_capacity].m_nNext = 0;//尾巴的一个
		memset(m_pIndexs, 0, (m_capacity + 1) * sizeof(int));
	}

	int get(int key) 
	{
		int nIndex = key%m_capacity + 1;
		nIndex = m_pIndexs[nIndex];
		while (nIndex != 0)
		{
			if (m_pCaches[nIndex].m_nKey == key)
			{
				//更新队列
				visited(nIndex);

				return m_pCaches[nIndex].m_nValue;
			}
			nIndex = m_pCaches[nIndex].m_nAfter;
		}
		return  -1;
	}

	void put(int key, int value) 
	{
		int nIndex = key%m_capacity + 1;
		if(nIndex!=0)
		{
			//处理重复数据
			nIndex = m_pIndexs[nIndex];
			while (nIndex != 0)
			{
				if (m_pCaches[nIndex].m_nKey == key)
				{
					m_pCaches[nIndex].m_nValue = value;
					visited(nIndex);
					return;
				}
				nIndex = m_pCaches[nIndex].m_nAfter;
			}
		}
		nIndex = key%m_capacity + 1;
		int nNewSlot = NewSlot();//这里回收可能让槽没数据
		if (m_pIndexs[nIndex] == 0)
		{
			//这个槽是空的
			m_pIndexs[nIndex] = nNewSlot;
			m_pCaches[nNewSlot].m_nBefore = -nIndex;
			m_pCaches[nNewSlot].m_nAfter = 0;
		}
		else
		{
			//这个槽有数据了，放到头部
			int nOldSlot = m_pIndexs[nIndex];
			m_pIndexs[nIndex]= nNewSlot;
			
			m_pCaches[nNewSlot].m_nBefore = -nIndex;
			m_pCaches[nNewSlot].m_nAfter = nOldSlot;
			m_pCaches[nOldSlot].m_nBefore = nNewSlot;
			/*
			nIndex = m_pIndexs[nIndex];
			while (m_pCaches[nIndex].m_nAfter != 0)
			{
				nIndex = m_pCaches[nIndex].m_nAfter;
			}
			m_pCaches[nIndex].m_nAfter = nNewSlot;
			m_pCaches[nNewSlot].m_nBefore = nIndex;
			m_pCaches[nNewSlot].m_nAfter = 0;
			*/
			
		}
		//把这个节点放到访问队列的头部
		m_pCaches[nNewSlot].m_nPre = 0;
		m_pCaches[nNewSlot].m_nNext = m_nHead;
		m_pCaches[nNewSlot].m_nKey = key;
		m_pCaches[nNewSlot].m_nValue = value;
		//维护头尾节点
		if (m_nHead != 0)
		{
			m_pCaches[m_nHead].m_nPre = nNewSlot;
		}
		m_nHead = nNewSlot;
		if (m_nTail == 0)
		{
			//初始状态或者 容量为1然后还被回收了
			m_nTail = m_nHead;
		}
	}
protected:
	int *m_pIndexs;//用于哈希拉链的
	node *m_pCaches;//具体存数据的地方
	int m_nHead;//更新的时候用到
	int m_nTail;//删除的时候用到
	int m_nIdle;//空闲链表
	int m_capacity;//容积
};
```