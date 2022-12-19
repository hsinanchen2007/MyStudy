### 解题思路
根据图论，要满足树的条件，需要满足$edge = vertices - 1$
Leetcode测试样例覆盖不全，没有覆盖孤立点的情况
### 代码

```golang
func validateBinaryTreeNodes(n int, leftChild []int, rightChild []int) bool {
    edge := 0
    for _, value := range leftChild {
        if value != -1 {
            edge ++
        }
    }

    for _, value := range rightChild {
        if value != -1 {
            edge ++
        }
    }

    if edge == n - 1 {
        return true
    } else {
        return false
    }
}
```