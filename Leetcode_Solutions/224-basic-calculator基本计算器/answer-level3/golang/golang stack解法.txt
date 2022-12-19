### 解题思路一
使用一个stack协助求解（性能差，费空间）

### 代码
执行用时 :16 ms, 在所有 Go 提交中击败了21.21%的用户
内存消耗 :5.2 MB, 在所有 Go 提交中击败了10.00%的用户

```golang

func calculate(s string) int {
	stack := NewStack()
	for i := 0 ; i < len(s); i++ {
		if s[i] >= '0' && s[i] <= '9' {
			j := i
			for ; j < len(s); j++ {
				if s[j] < '0' || s[j] > '9' {
					break
				}
			}
			stack.Push(s[i:j])
			stack.calc()
			i = j-1
		}else{
			if s[i] == '(' || s[i] == '+' || s[i] == '-' {
				stack.Push(string(s[i]))
			}else if s[i] == ')' {
				n:= stack.Pop()
				stack.Pop() //remove "("
				stack.Push(n)
				stack.calc()
			}
		}
	}
	result,_ := strconv.Atoi(stack.Pop())
	return result
}

type Stack struct {
	arr []string
}
func NewStack() *Stack {
	return &Stack{arr: make([]string, 0)}
}
func (this *Stack)Push(str string) {
	if str == "" {
		return
	}
	this.arr = append(this.arr, str)
}

func (this *Stack)Pop() string {
	if len(this.arr) == 0 {
		return ""
	}
	n := len(this.arr) - 1
	x := this.arr[n]
	this.arr = this.arr[:n]
	return x
}
func (this *Stack)calc() {
	if len(this.arr) < 3 {
		return
	}
	n := len(this.arr)-1
	j,err1 := strconv.Atoi(this.arr[n])
	i, err2 := strconv.Atoi(this.arr[n-2])
	if nil != err1 || nil != err2 {
		return
	}
	op := this.arr[n-1]
	newNum := 0
	if op == "+" {
		newNum = i + j
	}else if op == "-" {
		newNum = i - j
	}else{
		return
	}
	this.arr[n-2] = fmt.Sprintf("%d", newNum)
	this.arr = this.arr[:len(this.arr)-2]
}
```

### 解题思路二
参考一份非常优秀的代码
https://github.com/aQuaYi/LeetCode-in-Go/blob/master/Algorithms/0224.basic-calculator/basic-calculator.go

在遍历s的过程中，再未遇到(之前，一直计算并累计当前的计算结果；遇到(时，将当前计算结果压栈。
另外，通过引入sign符号，避免对"+"、“-”号的多次判断：

### 代码
执行用时 :4 ms, 在所有 Go 提交中击败了83.33%的用户
内存消耗 :3.2 MB, 在所有 Go 提交中击败了90.00%的用户
```golang
func calculate(s string) int {
	stack := make([]int, 0)
	res := 0
	sign := 1
	for i := 0 ; i < len(s); i++ {
		if s[i] >= '0' && s[i] <= '9' {
			num := 0
			for ; i < len(s); i++ {
				if s[i] < '0' || s[i] > '9' {
					break
				}
				num = num*10 + int(s[i]-'0')
			}
			res = res + sign*num
			i--
		}else{
			switch s[i] {
			case '+':
				sign = 1
			case '-':
				sign = -1
			case '(':
				stack = append(stack, res, sign)
				res, sign = 0, 1
			case ')':
				sign := stack[len(stack)-1]
				num := stack[len(stack)-2]
				res = num + sign*res
				stack = stack[:len(stack)-2]
			}
		}
	}
	return res
}
```