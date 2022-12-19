
由于Go对类型的操作十分严谨，```uint32```必须和同类型的**内置**```uint32```类型进行操作。所以```count```不能简单地声明为```int```或者其他整型, 因此当```count```为0的时候需要多插入一个if statement去结束for循环，不然会引起死循环。

```
func reverseBits(num uint32) uint32 {
    bits, count := uint32(0), uint32(31)
    
    for count >= 0 {
        bits |= (num & 1) << count
        num >>= 1
        if (count == 0) {
            return bits
        }
        count--
    }
    return bits
}
```

另外一种写法：
这种写法有个需要注意的地方是```<< (count-1)```这里需要上一个圆括号，因为移位符操作符```<<```的优先级比减号```-```的优先级要高，不然会造成计算错误。
```
func reverseBits(num uint32) uint32 {
    bits, count := uint32(0), uint32(32)
    
    for count > 0 {
        bits |= (num & 1) << (count-1)
        num >>= 1
        count--
    }
    return bits
}
```

