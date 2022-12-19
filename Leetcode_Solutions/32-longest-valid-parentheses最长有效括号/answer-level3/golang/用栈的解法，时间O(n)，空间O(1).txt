### 解题思路
思路在注释里：左括号入栈，右括号出栈，一次遍历找到被')'截断的最长子串，再一次遍历找到尾部被'('截断的最长子串
执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :2.3 MB, 在所有 Go 提交中击败了93.37%的用户
### 代码

```golang
//没看题解自己做的，感觉没用到动态规划，用到了栈的思想
//代码乱的像屎一样，懒得改，待会直接看官方题解好了
//时间复杂度O(n),空间复杂度O(1)

func longestValidParentheses(s string) int {
    
    l := len(s)
    max := 0 //全局最长有效子串

    temMax := 0 //当前阶段匹配括号的对数
    temStack := 0 //模拟栈
    lastR := -1 //当被')'截断时，最后一个')'所在位置

    for i:=0; i<l; i++ {
        if s[i] == '(' { //入栈
            temStack++
        }
        if s[i] == ')' { //出栈
            if temStack > 0{ //顺利出栈
                temStack--
                temMax++
            } else { //栈中没有与之匹配的'(',当前子串被')'截断了
                if temMax*2 > max{
                    max = temMax*2
                }
                temMax = 0
                temStack = 0
                lastR = i
            }
        }
    }

    //上面的步骤可以得到最后被')'截断前的最长子串，')'后面需要反向找一次
    temStackR := 0 //重新起个名
    temMax = 0
    for i:=l-1; i>=lastR; i-- {
        if temStack == 0 { //正向搜的时候，尾巴多了几个'('，反向搜的时候就会多几个子串
            if i-lastR > max {
                max = i-lastR
            }
            break
        }

        if s[i] == ')' {
            temStackR++
        }
        if s[i] == '(' {
            if temStackR > 0 {
                temStackR--
                temMax++
            } else {
                if temMax*2 > max {
                    max = temMax*2
                }
                temMax = 0
                temStackR= 0
                temStack -- //找到了一个多余的'('
            }
        }
    }
    return max
}
```