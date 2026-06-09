
反复比对了题解区的一些高赞题解，认为从代码逻辑上是一致的，但代码在golang提交中的成绩却并不理想。可能的优化：

- 取消子函数调用
- map的实现使用了通用的哈希函数（没有去查阅），运算较慢，可以针对题目都是整型数据设计专用的哈希表。这点等到做到哈希表相关的题再回来优化。

## 思路与实现

![image.png](https://pic.leetcode-cn.com/df69694fbbedc546142b179992842d173535fbbe6386393ec7f427655902f1e2-image.png)


```go
package lt146

import "fmt"

// LRU(Least Recently Use) 缓存淘汰算法
// 要求：在O(1)时间复杂度完成get/put操作，由于put和get还会包含del操作，所以增删查的时间复杂度都要是O(1)

// 实现思路：
// 单链表，每次查询缓存时 若存在则将目标数据取出放到链表头部；若不存在且未满，则直接加到头部； 若不存在且已满，则把原先尾部删除，把目标加到头部
// 优化：借助哈希表
// 还可以使用数组实现

// LRU缓存淘汰需要保证：
// 1.键值查找快
// 2.插入要快
// 3.删除要快
// 4.要有顺序

// 哈希表能实现O(1)的查找插入删除，但是哈希表的数据是无序的，不能让我们实现LRU
// 因此需要一种有顺序的数据结构存储各个缓存主体，然后用哈希表来存储所有缓存的键，值为缓存节点的指针。
// 链表、数组都可以实现。
// 1.单链表中删除某个节点由于需要其前驱节点，只能从头遍历，所以没法实现O(1)删除，那么导致LRU其他操作也没办法O(1)
// 2.双链表记载了前驱节点指针，可以通过在哈希表中按键找到目标缓存地址，再通过双链表删除该节点再挂到双链表头部。
// 3.数组的话，插入和删除没有办法，必然产生大量数据搬迁，即便对数据搬迁作优化处理（标记然后集中搬迁等策略），
// 由于缓存是频繁访问更新的一种数据结构，没办法实现O(1)

// 还有要特别注意的是，当链表中删除缓存节点时，哈希表也要删除对应的键值对

// 有个问题是：双链表中缓存节点是否需要存缓存的键？能不能只存缓存的值？
// 答案是不行。当链表满时，要删除最后一个节点并删除哈希表中键值对，如果链表节点不存键，就不知道删哈希表中哪个了。
// 毕竟哈希表是无序的，它可不知道哪个是最后一个节点。

// 那么最终就是使用 哈希表+双向链表 实现。这也是Java中LinkedHashMap的实现方式。

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */

// -----实现基于双链表+哈希表的最简单的LRU-----------------------------------

// 双链表节点
type cacheNode struct {
	key int
	val int
	prev, next *cacheNode
}

// LRU就是一个借助了哈希表的双链表结构。
type LRUCache struct {

	// key-*node映射
	m map[int]*cacheNode

	// 头/尾结点，不存有效缓存值
	head, tail *cacheNode

	// 容量
	cap int
}

func Constructor(capacity int) LRUCache {

	lru := LRUCache{
		m:    make(map[int]*cacheNode, capacity),
		head: &cacheNode{},
		tail: &cacheNode{},
		cap:  capacity,
	}

	lru.head.next = lru.tail
	lru.tail.prev = lru.head

	return lru
}

func (this *LRUCache) Get(key int) int {

	// 若没有则返回-1
	if targetCache, ok := this.m[key]; !ok {
		return -1
	} else {
		// 缓存历史中已经有，则将这个缓存节点摘下，放到头结点之后，再返回其值

		// 1. 摘下 （尽管有可能节点本身就是头结点之后第一个节点，但如果因此加上一个判断语句明显很浪费时间）
		this.del(targetCache)

		// 2. 放到头结点之后
		this.prepend(targetCache)

		// 3. 返回其值
		return targetCache.val
	}
}

func (this *LRUCache) Put(key int, value int)  {

	// 如果该缓存已经存在，则放到最前面去，且用value更新其值
	if targetCache, ok := this.m[key]; ok {
		// 1. 摘下 （尽管有可能节点本身就是头结点之后第一个节点，但如果因此加上一个判断语句明显很浪费时间）
		this.del(targetCache)

		// 2、3 步骤可以与下面的构建并添加到头部步骤一起合并，放到if else 代码块的外面。
		// 但那样做多了一些内存分配的消耗

		// 2. 追加到头部之后
		this.prepend(targetCache)

		// 3. 更新val
		targetCache.val = value
	} else {
		// 到这里，说明该缓存（该键）在链表中不存在

		// 如果已满，需要先删掉尾部
		if len(this.m) == this.cap {

			last := this.tail.prev

			// 先删除哈希表中末尾缓存节点的键，
			delete(this.m, last.key)
			// 再摘掉末尾缓存节点
			this.del(last)
		}

		// 构建新节点并插到头部(不管是缓存已存在还是不存在但满还是第三种)
		node := &cacheNode{
			key:  key,
			val:  value,
		}
		this.prepend(node)

		// 将新节点键存到this.m
		this.m[key] = node
	}
}

// 从双链表删除节点. 这里不检查node的前后是否为空的情况，因为我们不会删head和tail
func (this *LRUCache) del(node *cacheNode) {
	node.prev.next = node.next
	node.next.prev = node.prev
}

// 将某节点插到双链表头部之后
func (this *LRUCache) prepend(node *cacheNode) {
	node.next = this.head.next
	this.head.next.prev = node
	node.prev = this.head
	this.head.next = node
}

// 用作调试
func (this *LRUCache) printLRU() {
	fmt.Println("============start printLRU=============")

	fmt.Print("this.m: ")
	printMap(this.m)

	fmt.Printf("this.head.next = %v\n", this.head.next)
	fmt.Printf("this.tail.prev = %v\n", this.tail.prev)

	fmt.Printf("this.cap = %d\n", this.cap)

	fmt.Println("============end printLRU=============")
}

func printLinkedList(head *cacheNode) {

}

func printMap(m map[int]*cacheNode) {
	for k, v := range m {
		fmt.Printf("\tk=%d, v=%v\t", k, v)
	}
	fmt.Print("\n")
}

```

## 推荐阅读

没有那么多精力去进行详细阐述，在此贴上几篇优秀题解：

- <https://leetcode-cn.com/problems/lru-cache/solution/lru-ce-lue-xiang-jie-he-shi-xian-by-labuladong/>
- <https://leetcode-cn.com/problems/lru-cache/solution/tu-wen-bing-mao-xiang-jie-lruji-zhi-by-user7439t/>
- <https://leetcode-cn.com/problems/lru-cache/solution/shu-ju-jie-gou-fen-xi-python-ha-xi-shuang-xiang-li/>

## 链接

- 博客： <https://eiger.me/post/algo/lt146/>
- Github: <https://github.com/azd1997/Leetcode-training/blob/master/lt146/1.go>