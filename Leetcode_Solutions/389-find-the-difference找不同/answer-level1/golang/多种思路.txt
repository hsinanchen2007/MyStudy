![image.png](https://pic.leetcode-cn.com/2714d37629393533e08c522e3d8255abf0d4c4f22c2c629ed4ac5bd6c4547b7d-image.png)

思路一：加减法（也可以用乘除法）
```
func findTheDifference(s string, t string) byte {
    var count int = 0
    for i:=0; i<len(t); i++{
        count += int(t[i])
    }
    for i:=0; i<len(s); i++{
        count -= int(s[i])
    }
    return byte(count)
}
```
思路二：排序
代码自行实现

思路三：map
代码自行实现
