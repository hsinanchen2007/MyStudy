本题关键之处（完整代码见文末）：
- 因为要找最长 “公共” 前缀，那么意味着我们可以任一一个元素找到
- 通过任一元素建立 “基准” 元素，不断更新比较，即可正确求解

![image.png](https://pic.leetcode-cn.com/154bfb43b6d9b186b88f0fd01547027ebaacd210ad65b5b81cea2c4dc6c39c0d-image.png)


```go []
func longestCommonPrefix(strs []string) string {
    if len(strs) < 1 {
        return ""
    }
    prefix := strs[0]
    for _,k := range strs {
        for strings.Index(k,prefix) != 0 {
            if len(prefix) == 0 {
                return ""
            }
            prefix = prefix[:len(prefix) - 1]
        }
    }
    return prefix
}
```
