
![image.png](https://pic.leetcode-cn.com/adca8db36fde98786af5f1f143500504ecdcf14a292383520fd6ad081fed680e-image.png)

模拟题，二进制求和，字符串从尾部向前遍历相加，存储进位，累加到下一次计算。

Go 语言中注意类型的强制类型转换，容易报错。

代码：
```
func addBinary(a string, b string) string {
    result := ""
    flag := 0       // 存储进位
    i,j := len(a)-1,len(b)-1
    for i>=0 || j>=0 {
        t1,t2 := 0,0
        if i>=0 {
            t1 = int(a[i]-'0')
        }
        if j>=0 {
            t2 = int(b[j]-'0')
        }
        sum := t1 + t2 + flag   // 计算当前位置
        switch sum {
            case 3: flag = 1; result = "1" + result
            case 2: flag = 1; result = "0" + result
            case 1: flag = 0; result = "1" + result
            case 0: flag = 0; result = "0" + result
        }
        i--
        j--
    }
    if flag == 1 {  // 最终进位
        result = "1" + result
    }
    return result
}
```