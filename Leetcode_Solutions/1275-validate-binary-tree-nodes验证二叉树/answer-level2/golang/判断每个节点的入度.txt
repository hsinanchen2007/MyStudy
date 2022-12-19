### 解题思路
判断每个节点的入度，只有一个是0其他是1。还要从root开始先序遍历，最后都能联通

### 代码

```golang
func validateBinaryTreeNodes(n int, leftChild []int, rightChild []int) bool {
    // 判断0 ~ n - 1 每个只出先一次，0不出现
    if n < 1 {
        return false
    }
    if len(leftChild) < n || len(rightChild) < n {
        return false
    }
    var cache = make([]int, n)
   
    for i := 0; i < n; i++ {
        if leftChild[i] != -1 {
            cache[leftChild[i]]++
        }
        if rightChild[i] != -1 {
            cache[rightChild[i]]++
        }
    }
    // 先找到入度是0的，定位根节点
    root := -1
    for i := 0; i < len(cache); i++ {
        if cache[i] == 0 {
            root = i
            break
        }
    }
    // 没有根，说明图有环
    if root == -1 {
        return false
    }
    // 先序遍历看看结果是不是n
    var queue = []int{}
    var res = make(map[int]int, n)
    queue = append(queue, root)

    for len(queue) > 0 {
        x := queue[0]
        queue = queue[1:]

        if leftChild[x] != -1 {
            if _, ok := res[leftChild[x]]; ok {
                return false
            }
            res[leftChild[x]] = 1
            queue = append(queue, leftChild[x])
        }
        if rightChild[x] != -1 {
            if _, ok := res[rightChild[x]]; ok {
                return false
            }
            res[rightChild[x]] = 1
            queue = append(queue, rightChild[x])
        }
    }

    return len(res) == n - 1
}
```