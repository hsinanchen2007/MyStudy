### 解题思路
此处撰写解题思路

### 代码

```golang
func minArray(numbers []int) int {
    if len(numbers) == 0 {
        return 0
    }

    for i:= 1;i<len(numbers);i++ {
        if numbers[i] < numbers[i-1] {
            return numbers[i]
        }
    }

    return numbers[0]
}
```