### 解题思路
此处撰写解题思路

### 代码

```golang
func twoSum(nums []int, target int) []int {
            m := make(map[int]int)
            for i , v := range nums {
                if d , ok := m[target - v] ; ok {
                    return []int{d,i}
                } 
                m[v] = i
            }
            return nil
}


```