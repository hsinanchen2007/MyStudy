![屏幕快照 2020-04-07 下午3.54.28.png](https://pic.leetcode-cn.com/1050806fd899840f0b044234304a3edf8820c09d75edbab3c69883a94468f877-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-04-07%20%E4%B8%8B%E5%8D%883.54.28.png)

### 解题思路

模拟法，每次迭代减少i个硬币

### 代码

```golang
func arrangeCoins(n int) int {
    i:=1
    for ;i<=n;i++ {
        n -=i
    }
    return i-1
}
```
**更多题解可以在我的[github](https://github.com/LZH139/leetcode_Go)上看到，每天都在持续更新，觉得还不错的话，记得点个小星星哈，谢谢啦**