### 解题思路
主要考察位操作，不过全部切换到位计算后，性能居然没有提升。

### 代码

```golang
func hammingDistance(x int, y int) int {
    // 异或运算
    result := x ^ y

    resultCount := 0
    for result != 0 {
        // 和1进行异或操作，判定最后一位是否为1，提升性能
        if result & 1 == 1 {
            resultCount++
        }

        // 用位移操作取代除法
        result = result >> 1
    }

    return resultCount
}
```