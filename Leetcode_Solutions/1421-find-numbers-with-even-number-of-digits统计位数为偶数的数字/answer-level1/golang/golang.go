### 解题思路
int转string思路没错，但是不能使用string(data)

### 代码

```golang
func findNumbers(nums []int) int {
    var n int 
    for _, data := range nums {
        if len(strconv.Itoa(data))  % 2 == 0 {
            n= n + 1
        }
    }
    return n 
}

```