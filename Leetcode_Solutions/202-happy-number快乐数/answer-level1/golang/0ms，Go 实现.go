
![image.png](https://pic.leetcode-cn.com/867789de1b5f1266ab19c9818da38059fe75c5e7593e91989ca7162302026cf3-image.png)

如果计算出结果是1，说明是快乐数；同时，如果出现了循环说明不是快乐数。

```
func isHappy(n int) bool {
    hash := make(map[int]bool)      // 开一个 map 判断是否循环
    for n!=1 {
        if _,ok := hash[n]; ok {    // 出现了循环，证明不是快乐数
            return false
        }
        hash[n] = true
        next := 0
        for n!=0 {                  // 计算下一个数字
            next += (n%10) * (n%10)
            n /= 10
        }
        n = next
    }
    return true
}
```