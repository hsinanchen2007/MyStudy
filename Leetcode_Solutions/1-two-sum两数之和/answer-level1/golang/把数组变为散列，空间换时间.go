### 解题思路
此处撰写解题思路

此处就是把数组作为一个散列存储，例如
[2, 7, 11, 15] 

变为一个map 

{
    2 => 0,
    7 => 1, 
    11 => 2,
    15 => 3
}

然后通过map[target - v] 查询出对应的index，就可以快速的找到[i, j]

### 代码

```golang
func twoSum(nums []int, target int) []int {

    m := map[int]int{}
    for i, v := range nums {
        
        if j , ok := m[target - v]; ok {

            if i < j {
                return []int{i, j}
            } else {

                return []int{j, i}
            }
        }

        m[v] = i
    }
    return nil
}
```