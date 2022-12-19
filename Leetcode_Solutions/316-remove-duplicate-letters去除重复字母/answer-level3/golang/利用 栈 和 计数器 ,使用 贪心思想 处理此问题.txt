* 利用 栈 和 计数器 ,使用 贪心思想 巧妙的处理此问题

* 解题思想:
    * 如果当前的 栈顶元素 比当前的元素字典序 大,且 当前元素的位置后面还有 栈顶元素, 将栈顶元素出栈, 将当前元素入栈, 这样来找到最优的排列, 例如 dcd , 先入栈 d , 然后入栈c 时, 栈顶元素大于 c , 而且 c 后面的位置. 那么就将 d 出栈抛弃,然后把 c 入栈, 到d的时候 c小于d, 从而得到结果 cd

* 时间复杂度: O(nLogn)
* 空间复杂度: O(1)

* 过程:
    * 首先遍历一遍字符串, 获取每个字符的出现次数, 保存在计数器中
    * 类似于解题思路中的那样

```go
func removeDuplicateLetters(s string) string {
    stack := make([]uint8, 0)
    charMap := map[uint8]int{}
    
    // 获取每个字符的出现次数, 保存在计数器中
    for i := 0; i < len(s); i++ {
        charMap[s[int(i)]]++
    }
    
    //
    for i := 0; i < len(s); i++ {
        // 栈中是否存在该字符
        if isHaveChar(s[int(i)], stack) {
            charMap[s[int(i)]]--
            continue
        } else {
            for {
                if len(stack) != 0 && charMap[stack[len(stack)-1]] != 0 && stack[len(stack)-1] > s[int(i)] {
                    stack = stack[0 : len(stack)-1]
                } else {
                    stack = append(stack, s[int(i)])
                    charMap[s[int(i)]]--
                    break
                }
            }
        }
    }
    
    // 获取结果 输出
    var str string
    for _, v := range stack {
        str += string(v)
    }
    
    return str
}

// 栈中是否存在该字符
func isHaveChar(char uint8, stack []uint8) ( bool) {
    for _, v := range stack {
        if v == char {
            return true
        }
    }
    return false
}

```