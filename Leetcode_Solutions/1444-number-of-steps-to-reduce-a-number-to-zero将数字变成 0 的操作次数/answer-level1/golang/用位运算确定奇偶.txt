# 用位运算确定奇偶,申请变量放后面
```
func numberOfSteps (num int) int {
    times := 0
    for {
        if (num == 0) {
            return times
        }

        if (num & 1) == 1 {
            // 奇数
            num--
        } else {
            num = num / 2
        }
        times++
    }  
}
```
