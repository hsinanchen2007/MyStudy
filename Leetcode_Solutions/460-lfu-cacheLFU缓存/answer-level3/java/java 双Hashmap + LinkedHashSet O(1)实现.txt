首先，使用min binary heap最小堆+哈希表的复杂度是O(log n)
![image.png](https://pic.leetcode-cn.com/8378469bfebf0811bab00419466385f48b17460a50fbe8f537d2fb9a06cdf497-image.png)

LRU里已经讲过，哈希表+排序必须靠链表实现，
单链表的复杂度是O(n)，我们需要使用双向链表实现O(1)复杂度，这篇论文已经提出了怎么用双链表实现O（1）的复杂度，相信不会有更好的办法了，[http://dhruvbird.com/lfu.pdf](http://dhruvbird.com/lfu.pdf)

大致的结构图：

![image.png](https://pic.leetcode-cn.com/aba71627751babb1c2a40c06034626b8ec67ec2669c23a8afdc7fe9b636c0d2c-image.png)

在java里直接用LinkedHashSet/LinkedHashMap实现双向链表。

需要一个node结构key, value, freq  这里的<key,value>就是我们要存储的缓存数据的<key,value>，freq是该数据的出现频率

**两个hashmap**：
CacheMap: hashmap<Integer, Node>  这个map就是为了实现直接put/get数据，不涉及频率更新操作。

freqMap : hashmap<Integer, LinkedHashSet<Node>>   key是出现频率，value是对应出现同样频率的所有Node结点（频率一样使用最近最少使用LRU原则）。这个表不涉及put/get数据，涉及update，负责处理频率相关操作。

**实现的操作：**
get(key) : 
	如果key不存在，返回-1，
		否则得到node，update(node)，返回node.value

put(key,value): 
	如果cap<=0，直接return
	如果key已经存在，update(node)，
		否则，key不存在，为key建立一个新的node，频率设置为1
			如果freqMap没有频率为1的entry，就加一个频率为1的entry
	如果cacheMap的容量>cap，需要通过查找minFreq对应的一串Node，找到LinkedHashset里的第一个node，删掉他，同时在cacheMap里也删掉他。
	最后，reset minFreq=1

update(node):
	首先得到node.freq对应的linkedhashset的那一串node，也就是找出和node频率一样的其他node。然后在这一串node里去掉这个node，因为这个node的频率变了，+1了。
	如果这一串set空了，并且当前node频率是最小的频率，那么minFreq要+1
	node.Freq+1
	如果freqMap里没有node现在的频率，就给他新建一个LinkedHashSet，key为当前node的频率，放到freqMap里
