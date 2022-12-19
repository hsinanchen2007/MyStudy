### 解题思路
![2.png](https://pic.leetcode-cn.com/b008be3c2621f54df5f2a38924a227fb62648ea16dc98e6b34cae6426d3edd8d-2.png)

向每一位深夜刷题的大牛致敬！

好的，这道题我的思路其实很清晰，就是用map统计每个数字出现的次数，并看看这些次数的最大公约数是不是大于1，如果大于1就返回true，否则就返回false。

### 代码

```golang
func hasGroupsSizeX(deck []int) bool {
    if len(deck)<2{
        return false
    }
    var gcd func(a int,b int)int
    gcd = func(a int,b int)int{
        for a%b!=0{
            a,b=b,a%b
        }
        return b
    }
    g:=0
    map1 := make(map[int]int)
    for i:=0;i<len(deck);i++{
        map1[deck[i]]++
    }
    for _,value := range map1{
        if g==0{
            g = value
        }
        g = gcd(g,value)
    }
    return g>1
}
```