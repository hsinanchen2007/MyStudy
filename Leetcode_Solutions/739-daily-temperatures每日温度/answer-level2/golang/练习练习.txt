### 解题思路

执行用时 :56 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :7.1 MB, 在所有 Go 提交中击败了100.00%的用户

利用栈,此栈用来存储温度值以及对应的下标
1.遍历温度,第一个元素入栈没得说,之后拿到温度以后
2.和栈顶元素比较,如果大于该栈顶元素,则出栈,且遍历到的该温度的下标和栈顶元素的下标之差,就是代表该栈顶元素几天后升温
3.重复第2步,如果遇到小于栈顶元素或者栈空了,则跳出出栈的内循环,且该温度入栈
4.重复第1步

### 代码

```golang
type Tem struct {
	Tem int
	index int
}

type TemStack struct {
	Data []Tem
}


func dailyTemperatures(T []int) []int {
	temStack := TemStack{Data:nil}
	dailyTem := make([]int, len(T))
	for i, val := range T {
		tem := Tem{
			Tem:   val,
			index: i,
		}
		if i == 0 {
			temStack.Push(tem)
			continue
		}
		for len(temStack.Data) > 0 {
			if temStack.Top().Tem < val {
				temp := temStack.Pop()
				dailyTem[temp.index] = i - temp.index
			}else{
				break
			}
		}
		temStack.Push(tem)
	}
	return dailyTem
}

func (this *TemStack) InitStack() TemStack {
	stack := TemStack{Data:nil}
	return stack
}

func (this *TemStack) Push( x Tem) {
	this.Data = append(this.Data, x)
}

func (this *TemStack) Pop() Tem{
	tem := this.Data[len(this.Data) - 1]
	this.Data = this.Data[:len(this.Data) - 1]
	return tem
}
func (this *TemStack) Top() Tem{
	return this.Data[len(this.Data) - 1]
}
```