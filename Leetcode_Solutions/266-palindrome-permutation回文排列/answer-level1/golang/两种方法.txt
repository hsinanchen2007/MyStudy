# 方法一

![image.png](https://pic.leetcode-cn.com/67ab1191e23a9dbe841307908ebe15966ca87b9ce66e61b6fc2b8186a3dd04ec-image.png)
```
func canPermutePalindrome(s string) bool {
    var bs []byte = []byte(s)
    ns := make([]int, len(s))
    for k, v := range bs {
        ns[k] = int(v)
    }
    sort.Ints(ns)
    i := 0
    j := len(s)-1
    for i<j {
        if ns[j] == ns[j-1] {
            j-=2
        } else if ns[i] == ns[i+1] {
            i+=2
        } else {
            return false
        }
    }
    return true
}
```
使用排序数组
# 方法二

![image.png](https://pic.leetcode-cn.com/5244a109cf557c96cbf44d39231227fbcc213b0b6168343562e0ceb30f6262fb-image.png)
```
func canPermutePalindrome(s string) bool {
    var bs []byte = []byte(s)
    ns := make(map[byte]int, len(s))
    for _, v := range bs {
        ns[v]++
    }
    fmt.Println(ns)
    find := 0
    for _, v := range ns {
        if v % 2 == 0 {
            continue
        } else if find == 0 {
            find = 1
        } else {
            return false
        }
    }
    return true
}
```
使用map
