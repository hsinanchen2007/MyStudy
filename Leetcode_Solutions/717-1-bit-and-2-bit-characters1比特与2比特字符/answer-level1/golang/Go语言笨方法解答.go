总体思路：
```
总体思路：
在遍历字符数组过程中如果当前字符为0则下标+1，如果当前字符为1则下标+2
设置一个标记变量flag来存储遍历数组过程中字符类型，如果是单字节的(0开头的字符)，则设置flag为true，如果是双字节的（1开头的字符）则设置flag为false
具体实现如下：
func isOneBitCharacter(bits []int) bool {
    length := len(bits)
    var flag bool
    for i:= 0; i < length;{
        if bits[i] == 1{
            i +=2
            flag = false
        }else{
            i++
            flag = true
        }
    }
    return flag
    
}

```