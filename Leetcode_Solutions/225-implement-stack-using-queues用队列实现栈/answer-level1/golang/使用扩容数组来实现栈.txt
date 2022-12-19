### 解题思路
使用数组实现，用一个int N表示栈中的元素个数。
数组最大的毛病是容量有限，所以我们要解决的是数组的扩容问题，虽然Go中的slice支持逐个扩容，这样会影响增加元素的速度。因此我们以长度为1的数组为基础，每次扩容扩大到原来的2倍，这样我们在增加元素的扩容次数就会减少。
另外还有一点就是如果栈中元素不断取出，那么会导致后面的空间浪费，所以我们也要制定一个缩减的策略，显然如果缩减的策略是数组中元素减少到原来的一半就缩减的话，会导致在该处不断地push和pop的时候会重复的扩容和缩减，不划算。所以我们的缩减策略必须要与扩容策略不对称，我选择的是缩减为数组长度的四分之一的时候改变数组的大小。当然你也可以选择扩容到原来的4倍，然后缩减到原来的1/2，只要不对成即可。


```
func (this *MyStack) Push(x int)  {
<!-- push之间检查是否需要扩容 -->
    if this.N == len(this.arr) {
		this.resize(2 * len(this.arr))
	}
	this.arr[this.N] = x
	this.N++
}
```

```
func (this *MyStack) Pop() int {
<!-- pop之前检查是否需要进行缩减 -->
    if this.N == len(this.arr) / 4 {
		this.resize(len(this.arr) / 4)
	}
	this.N--
	return this.arr[this.N]
}
```

```
<!-- 数组resize的函数 -->
func (s *MyStack)resize(capacity int) {
	copy := make([]int, capacity, capacity)
	for i := 0; i < s.N; i++ {
		copy[i] = s.arr[i]
	}
	s.arr = copy
}
```


