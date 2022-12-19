### 解题思路
使用栈结构，左括号入栈，碰到右括号时从栈中弹出元素 

### 代码

```golang
func isValid(s string) bool {
    if len(s) % 2 != 0 { // 奇数长度
		return false
	}
	var (
		stackIndex int = -1
		stack = make([]int32, len(s) / 2 + 1,len(s) / 2 + 1)
	)
	pop := func() int32 {
		b := stack[stackIndex]
		stackIndex--
		return b
	}
	push := func(c int32) {
        stackIndex++
		stack[stackIndex] = c
	}
	bracketPari := map[int32]int32{
		'{': '}',
		'[': ']',
		'(': ')',
	}

	for _, v := range s {
		if v == '{' || v == '(' || v == '[' {
			push(v)
			continue
		}
        if stackIndex == -1 {
			return false
		}
		lastBracket := pop()
		if bracketPari[lastBracket] != v {
			return false
		}
	}
    if stackIndex != -1 { // 栈内还有元素未匹配
		return false
	}
	return true
}
```
### 执行结果
![image.png](https://pic.leetcode-cn.com/c10b48b4b731f19cd87bd24937f9fd4d87b35d4d24d4be9b2f68ebbc6d049e9c-image.png)
