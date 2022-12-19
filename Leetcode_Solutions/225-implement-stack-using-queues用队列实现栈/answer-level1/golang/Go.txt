### 解题思路
执行用时 :
0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :
2 MB, 在所有 Go 提交中击败了73.75%的用户

双slice，来回倒换，如果是Top，最后一个元素不倒换


### 代码

```golang
type MyStack struct {
	repo []int
}

/** Initialize your data structure here. */
func Constructor() MyStack {
	return MyStack{repo: make([]int, 0)}
}

/** Push element x onto stack. */
func (this *MyStack) Push(x int) {
	this.repo = append(this.repo, x)
}

/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
	r := make([]int, 0)
	var i int
	for !this.Empty() {
		i = this.repo[0]
		this.repo = this.repo[1:]
		if !this.Empty() {
			r = append(r, i)
		}
	}
	this.repo = r
	return i
}

/** Get the top element. */
func (this *MyStack) Top() int {
	r := make([]int, 0)
	var i int
	for !this.Empty() {
		i = this.repo[0]
		this.repo = this.repo[1:]
		r = append(r, i)
	}
	this.repo = r
	return i
}

/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
	return len(this.repo) == 0
}
```