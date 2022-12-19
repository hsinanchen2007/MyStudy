### 解题思路
思路很简单，主要看代码实现

边界条件：当节点为nil的时候，直接返回；

### 代码

```golang
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func preorder(root *Node) []int {
    ret := make([]int, 0)
    var f func(*Node)

    f = func(node *Node) {
        if node == nil {
            return 
        }
        ret = append(ret, node.Val)
        for _, e := range node.Children {
            f(e)
        }
    }
    f(root)
    return ret
}
```
### 微信公众号：互联网技术窝
![image.png](https://pic.leetcode-cn.com/a0ab9af68ee764a323e9978a229aa3e2777fe2e9ed4bd2408ff22e43b0070a31-image.png)


![qrcode.png](https://pic.leetcode-cn.com/27051d45202cd2e861bebc67faedc1caf572bd24aa6970bff62da07b3fc65317-qrcode.png)
