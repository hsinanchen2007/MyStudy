## 题目

给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。 

示例 1：

> 输入：head = [3,2,0,-4], pos = 1
> 输出：true
> 解释：链表中有一个环，其尾部连接到第二个节点。

![circularlinkedlist](https://pic.leetcode-cn.com/0a4cb8d4a76aee4b2e9c7a0466b877402df56cc3a935a14fa5b273038849ccea.jpg)

示例 2：

> 输入：head = [1,2], pos = 0
> 输出：true
> 解释：链表中有一个环，其尾部连接到第一个节点。

![circularlinkedlist_test2](https://pic.leetcode-cn.com/4232a411876797e3c667bc0ad1fc3fd1837a6291a68dcf9cdfdde5967cd9be17.jpg)

示例 3：

> 输入：head = [1], pos = -1
> 输出：false
> 解释：链表中没有环。

![circularlinkedlist_test3](https://pic.leetcode-cn.com/afb5979a957464ea0787e756842c89f7a9fca27e614ab6e4fe0c6d3c4a812cfc.jpg)


进阶：

你能用 O(1)（即，常量）内存解决此问题吗？

## 解答

> 作者：chitanda-eru
>
> 链接：https://leetcode-cn.com/problems/two-sum/solution/liang-chong-fang-fa-by-chitanda-eru/

### 哈希表

想法是遍历所有节点，并记一下之前有没有走过，如果有走过就发true。

```js
var hasCycle = function (head) {
  let dataMap = new Map()
  while (head) {
    if (dataMap.has(head)) {
      return true
    }
    dataMap.set(head, 1)
    head = head.next
  }
  return false
};
```

> Runtime: 60 ms, faster than 93.20% of JavaScript online submissions for Linked List Cycle.
>
> Memory Usage: 37.7 MB, less than 33.76% of JavaScript online submissions for Linked List Cycle.

#### go

> 作者：elliotxx
> 链接：https://leetcode-cn.com/problems/two-sum/solution/8mskuai-man-zhi-zhen-hashsi-lu-de-go-shi-xian-by-e/

```go
func hasCycle(head *ListNode) bool {
	m := make(map[*ListNode]int)
	for head != nil {
		if _, ok := m[head]; ok {
			return true
		}
		m[head] = 1
		head = head.Next
	}
	return false
}
```

> Runtime: 4 ms, faster than 99.12% of Go online submissions for Linked List Cycle.
>
> Memory Usage: 6.1 MB, less than 12.20% of Go online submissions forLinked List Cycle.

判断`head`是否存在卡了一下。go中判断是`head != nil`。

其实不需要用到第四行`if`的值，因此`if`也可以这么写：

```go
...
		if m[head] != 0 {
			return true
		}
...
```

> Runtime: 8 ms, faster than 34.60% of Go online submissions for Linked List Cycle.
>
> Memory Usage: 6.1 MB, less than 12.20% of Go online submissions forLinked List Cycle.

感觉这么写更精确：

```go
...
    if m[head] == 1 {
			return true
		}
...
```

> Runtime: 8 ms, faster than 34.60% of Go online submissions for Linked List Cycle.
>
> Memory Usage: 6.1 MB, less than 12.20% of Go online submissions forLinked List Cycle.

这俩效果都没啥差别，不过似乎用官方标准写法优化得更好。可能因为判断不用具体到是否为`int`了。

### 双指针

一个跑得快，一个跑得慢。如果跑得快的遇上了跑得慢的，就有环，不然就没有。

```js
const hasCycle = function (head) {
  let fast = slow = head
  while (fast && fast.next) {
    fast = fast.next.next
    slow = slow.next
    if (fast === slow) {
      return true
    }
  }
  return false
};
```

> Runtime: 56 ms, faster than 97.85% of JavaScript online submissions for Linked List Cycle.
>
> Memory Usage: 36.6 MB, less than 64.28% of JavaScript online submissions for Linked List Cycle.

#### go

```go
func hasCycle(head *ListNode) bool {
	fast := head
	slow := head
	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
		if fast == slow {
			return true
		}
	}
	return false
}
```

> Runtime: 4 ms, faster than 99.12% of Go online submissions for Linked List Cycle.
>
> Memory Usage: 3.8 MB, less than 24.39% of Go online submissions forLinked List Cycle.

这是根据js的思路写的，看到[elliotxx](https://leetcode-cn.com/problems/two-sum/solution/8mskuai-man-zhi-zhen-hashsi-lu-de-go-shi-xian-by-e/)对此的解法，似乎这个`slow`也不必设置了：

```go
func hasCycle(head *ListNode) bool {
	if head == nil {									// 开头多了校验
		return false
	}
	fast := head
	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		head = head.Next								// 不用设立slow，因为可以直接破坏原有的head
		if fast == head {
			return true
		}
	}
	return false
}
```

> Runtime: 4 ms, faster than 99.12% of Go online submissions for Linked List Cycle.
>
> Memory Usage: 3.8 MB, less than 100.00% of Go online submissions for Linked List Cycle.

对内存的占用简直出色

换言之js也能这么搞

```js
const hasCycle = function (head) {
  if (!head) {
    return false
  }
  let fast = head
  while (fast && fast.next) {
    fast = fast.next.next
    head = head.next
    if (fast === head) {
      return true
    }
  }
  return false
};
```

> Runtime: 64 ms, faster than 80.26% of JavaScript online submissions for Linked List Cycle.
>
> Memory Usage: 36.8 MB, less than 41.38% of JavaScript online submissions for Linked List Cycle.

反而比之前慢了。。神奇。。

猜不出原因。

### symbol

```js
var hasCycle = function (head) {
  const flag = Symbol();
  while (head) {
    if (head.val === flag) return true;
    head.val = flag;
    head = head.next;
  }
  return false;
};
```

> Runtime: 64 ms, faster than 80.26% of JavaScript online submissions for Linked List Cycle.
>
> Memory Usage: 36.6 MB, less than 57.76% of JavaScript online submissions for Linked List Cycle.

[symbol](http://es6.ruanyifeng.com/#docs/symbol)新建的变量，是独一无二的。这是 JavaScript 语言的第七种数据类型。

这里第二行新建了一个`symbol`。新建`symbol`不用`new`，而是直接等于。这下flag里面存的内容就是一个独一无二的`symbol`了。

然后跑链表。把跑过的链表全改写成建立的`symbol`，如果跑的时候遇到了这个`symbol`，就说明有环。

#### go

看到[elliotxx](https://leetcode-cn.com/problems/two-sum/solution/8mskuai-man-zhi-zhen-hashsi-lu-de-go-shi-xian-by-e/)对这个解法的描述：

> 走自己的路让别人无路可走

笑死了

他的做法是“将遍历过的节点值修改为一个后台不太可能设置的值”，这里我就用一个随机数代替

```go
func hasCycle(head *ListNode) bool {
	rand.Seed(time.Now().UnixNano())
	key1 := rand.Int()
	for head != nil {
		if head.Val == key1 {
			return true
		}
		head.Val = key1
		head = head.Next
	}
	return false
}
```

> Runtime: 4 ms, faster than 99.12% of Go online submissions for Linked List Cycle.
>
> Memory Usage: 3.8 MB, less than 21.95% of Go online submissions forLinked List Cycle.

但中感觉这就是一个漏洞，万一后台设置了呢？

查了半天找不到go中对应js的`symbol`，可能因为go是强类型，已经规定了输入是`int`了，就不能再重新赋值为其他类型了。而js就不用管这些。

因此只能想到这么一个补救措施：用随机数跑两遍。

- 如果是环，那么跑两遍的结果都是true
- 如果有个节点的值恰好为第一个随机数，导致了返回true，那么第二个值也能校验是否为环
- 如果这个链表恰好先有个节点，值为第一个随机数，又恰好后有个节点，值为第二个随机数
  这种极小概率的事件，能出现我也认了。

没有`symbol`的话我只能想到这么做了。

```go
func testCylce(head *ListNode) bool {
	fmt.Println("head", head)
	rand.Seed(time.Now().UnixNano())
	key := rand.Int()
	for head != nil {
		if head.Val == key {
			return true
		}
		head.Val = key
		head = head.Next
	}
	return false
}

func hasCycle(head *ListNode) bool {
	return testCylce(head) && testCylce(head)
}
```

> Runtime: 4 ms, faster than 99.12% of Go online submissions for Linked List Cycle.
>
> Memory Usage: 3.8 MB, less than 21.95% of Go online submissions forLinked List Cycle.

不知道为啥跑两遍的结果是一样的。。。

##### go的随机数：

生成随机数有两种方法：

```go
rand.Seed(time.Now().Unix())

key1 := rand.Int()
key2 := rand.Int()

r := rand.New(rand.NewSource(time.Now().Unix()))

key3 := r.Int()
key4 := r.Int()
```

结果key1和key3一样，key2和key4一样。

![image-20190804164057357](https://pic.leetcode-cn.com/e4671493bfb6c77a79949668e23092d49e4b9938671bf1b5b5e16f2896ae9659.jpg)

经测试，同一个函数内，`time.Now().Unix()`生成的值都是一样的。因为go的执行都是以毫秒计时的，而`Unix()`只能换算到秒，因此随机数的种子都是一样的。而同一个种子下算出的随机数是一样的，所以才会有这种结果。

因此要用`UnixNano()`，用毫秒来统计，种子就不同了，随机数也就不同了。

```go
rand.Seed(time.Now().UnixNano())
...
r := rand.New(rand.NewSource(time.Now().UnixNano()))
```

感觉这个奇怪的冷知识就是为了防止两个函数的随机数设置重复吧，用毫秒最保险。

## 测试环境

这题完全无法测试。。自己做出来的链表不会有闭环的。。

如果要做的话，每个测试样例都要专门做，感觉就很麻烦。。


