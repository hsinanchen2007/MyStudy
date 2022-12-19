## 基本思想
1. 先使用map定义括号关系,即key=>val
2. 借用切片加指针i模拟栈操作

## 需要注意
1.  指针i回到0时,表示栈空.
2. 压栈时i++
3. 出栈时,需要注意栈为空时不需要再--啦,否则切片越界
4. 当指针i=0时,则表示栈空,匹配成功

## 具体代码实现

```
func isValid(s string) bool {
    bm := map[byte]byte{
		')':'(',
		'}':'{',
		']':'[',
	}
	i := 0 //声明一个指针,使用跟踪stack切片的,模拟栈的操作.
	stack := make([]byte, len(s))
	sb := []byte(s)
	for _, b := range sb {
		if _, ok := bm[b]; !ok {//判断是否在map里,不在则压栈
			stack[i] = b
			i ++
		} else {//不存在map键里,则向栈中弹出一个元素进行比较.
			if val, ok := bm[b]; ok {
                if i != 0 {//当栈不为空时,即i!=0时才--,否则会越界
                    i --
                }				
				sVal := stack[i]//出栈操作
				if sVal != val {//判断插号是否匹配.只要检测到一个不匹配则返回false
					return false
				}
			}
		}
	}
	if i == 0 {//当i == 0时则表示栈为空,匹配完成.
		return true
	}
	return false //否则说明括号匹配不成功
}
```
