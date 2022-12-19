![33.png](https://pic.leetcode-cn.com/18a589248d6317a1638d17bd90a29e7d0ad048f378457368cf6a52ca280a5516-33.png)

### 十进制移位
- 十进制移动两位 `n := n /10*10`
- 检查余数位数
- 递归
## [https://mojotv.cn/](https://mojotv.cn/)
### 代码

```golang
func findNumbers(nums []int) int {
    c := 0 
    for _,n := range nums {
        if cheker(n){
            c++
        }
    }
    return c
}

func cheker(num int) bool {
    r := num %100
    num = num/100
    if num == 0 {
        //余数是两位数字就是true
        return r >= 10
    }else {
        return cheker(num)
    }
}
```