1. 不能循环就用递归
2. 递归需要终止条件，需要if，但是不能使用if，因此使用短路代替if

当可以使用if的时候

```golang
func sumNums(n int) int {
    if n == 0 {
        return 0
    }
    return n + sumNums(n-1)
}
```

现在要使用 && 构造一个当n为0时停止递归的代码，且golang要求&&两边都是布尔值，即：bool && bool

完整代码1

```golang
func sumNums(n int) int {
    res := n
    func () bool { // 2. 这个函数是为了在语法上符合对 bool && bool 的使用
        return (n>0) && func() bool { // 1. 核心，bool && bool，当前一个为false，后一个不会执行，代替了if n == 0 
            res += sumNums(n-1)
            return true
        }()
    }()
    return res
}
```

完整代码2

```golang
func sumNums(n int) int {
    res := n
    // 2. _ = 为了符合语法，舍弃结果
    _ = (n>0) && func() bool { // 1. 核心，bool && bool，当前一个为false，后一个不会执行，代替了if n == 0 
            res += sumNums(n-1)
            return true
    }()
    return res
}
```