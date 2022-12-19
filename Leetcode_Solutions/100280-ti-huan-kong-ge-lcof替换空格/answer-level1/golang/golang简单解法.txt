### 解题思路
使用switch简单的替换就好
![截屏2020-02-17下午12.12.28.png](https://pic.leetcode-cn.com/923cf42f56655844529b34a93db1fd0c58a7f9f438cd3a0a9e649ac0f2d06217-%E6%88%AA%E5%B1%8F2020-02-17%E4%B8%8B%E5%8D%8812.12.28.png)

### 代码

```golang
func replaceSpace(s string) string {
    ns := ""
    for _, v := range s {
        switch v {
        case ' ':
            ns += "%20"
        default:
            ns += string(v)
        }
    }
    return ns
}
```