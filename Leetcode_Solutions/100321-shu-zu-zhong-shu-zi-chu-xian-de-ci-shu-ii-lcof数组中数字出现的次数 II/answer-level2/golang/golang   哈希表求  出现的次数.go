### 解题思路
golang map 的创建、遍历。
哈希表的概念。

### 代码

```golang
func singleNumber(nums []int) int {
    nmap := make(map[int]int)
    for _, m := range nums {
        nmap[m]++
    }
    for key, value := range nmap {
        if value == 1 {
            return key
        }
    }
    return 0
}


```