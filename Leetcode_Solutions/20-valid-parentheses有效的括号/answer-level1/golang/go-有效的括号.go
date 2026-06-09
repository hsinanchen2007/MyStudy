## 解题思路

给定一段只包括 `'('，')'，'{'，'}'，'['，']'` 的字符串中，出现了一次左侧括号，那么下一次出现的右侧括号如果是与之对应的，输出 `true`，否则输出 `false`。字符串是空时，也要输出 `true`。

1. 使用一个 `map` 保存括号的对应关系。

2. 创建一个容器用于保存字符串中的左侧括号。

3. 遍历字符串，每遇到一个左侧括号，就将该括号放入容器中。

4. 如果遇到的符号是右侧括号，则判断容器A中最后一次添加的左侧括号，是否是与之对应的：

	如果是，则从容器中移除最后一次添加的左侧括号，然后继续执行；

	如果不是，则直接返回 `false`。

5. 遍历结束后，如果容器中数据的个数为 0，那么返回 `true` 。有两种情况会得到 `true` 。

	1. 因为如果给定字符串长度为 0，则容器中数据的个数为 0，那么应该输出 `true` 。
	2. 左右括号为成对出现，最后容器中的数据全被移除了，也应该输出 `true` 。

## 代码

```go
package main

import "fmt"

func main() {
   fmt.Println(isValid("()"))
}

func isValid(s string) bool {
   symbolMap := map[string]string {
      "(": ")",
      "[": "]",
      "{": "}",
   }

   stack := NewStack()
   for _, val := range s {
      character := string(val)
      if rightSymbol := symbolMap[character]; rightSymbol != "" {
         stack.Push(character)
      } else if symbolMap[stack.Pop()] != character {
         return false
      }
   }
   return 0 == stack.Length()
}

type Stack struct {
   data []string
}

func NewStack() *Stack {
   return &Stack{}
}

func (s *Stack) Push(item string) {
   s.data = append(s.data, item)
}

func (s *Stack) Pop() string {
   if s.Length() == 0 {
      return ""
   } else {
      lastCharacter := s.data[s.Length()-1]
      s.data = s.data[0:s.Length()-1]
      return lastCharacter
   }
}

func (s *Stack) Length () int {
   return len(s.data)
}
```

> Title: 20.有效的括号
>
> Date: 2019.11.09
>
> Author: zhangpeng