本题解用编译原理中的确定有穷自动机原理, 先定义字符:

1. BLANK: 空格, tab等
2. DIGIT: 数字
3. OTHER: 其他无关字符
4. SIGN: 符号字符

然后画出DFA(草稿纸, 比较粗糙, 看不下就看下面的状态表吧):

![101686869.jpg](https://pic.leetcode-cn.com/d2f383e3de314d35b16c8da241cb7b2feb012ffccda95f87d3849e03aec5ad65-101686869.jpg)

然后是状态表:

![833364875.jpg](https://pic.leetcode-cn.com/dd88438b39030f72f9a8920702c2caaabedd8adfc103a44af76554483da32e44-833364875.jpg)

然后是代码:
```GO
// 状态表
var table = [][]int{
  []int{5, 1, 4, 3},
  []int{2, 1, 2, 2},
  []int{2, 2, 2, 2},
  []int{4, 1, 4, 4},
  []int{4, 4, 4, 4},
  []int{5, 1, 4, 3}}

func myAtoi(str string) int {
  var currentState int = 0
  sign := 1
  res := 0
LOOP:
  for i := 0; i < len(str); i++ {

    currentState = table[currentState][getType(str[i])]
    fmt.Printf("Get: %v, To State: %d\n", getType(str[i]), currentState)
    switch currentState {
    // 数字累加
    case 1:
      {
        res = res*10 + ToNum(str[i])
        if withSign := res * sign; withSign > math.MaxInt32 {
          return math.MaxInt32
        } else if withSign < math.MinInt32 {
          return math.MinInt32
        }
        fmt.Println(res)
      }
    // 返回合法结果
    case 2:
      break LOOP
    // 记录符号
    case 3:
      {
        if str[i] == '-' {
          sign = -1
        } else {
          sign = 1
        }
      }
    // 非法字符, 返回0
    case 4:
      {
        return 0
      }
    default:
      break
    }
  }
  return res * sign                                                                 
}
```

结果还是比较理想的:
![深度截图_选择区域_20200221124400.png](https://pic.leetcode-cn.com/a004ed6fe6f15f4f70877cba96bf7daba76c199afefa40bb321c3cb99c5cf6d3-%E6%B7%B1%E5%BA%A6%E6%88%AA%E5%9B%BE_%E9%80%89%E6%8B%A9%E5%8C%BA%E5%9F%9F_20200221124400.png)
