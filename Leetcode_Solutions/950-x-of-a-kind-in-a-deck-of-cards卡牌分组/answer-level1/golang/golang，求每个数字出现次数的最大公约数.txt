### 解题思路
先把每个数字出现的次数放入map中，再求map中所有值的最大公约数，如果最大公约数等于1，则返回false

### 代码

```golang
func hasGroupsSizeX(deck []int) bool {
    deckMap := make(map[int]int)

    for _,v := range deck {
        deckMap[v]+=1
    }

    minValue := math.MaxInt32

    for _,v := range deckMap {
        minValue=min(minValue,v)
    }

    gcdValue := minValue
    for _,v := range deckMap {
        gcdValue = gcd(v,gcdValue)
        if gcdValue==1 {
            return false
        }
    } 

    return true

}

func gcd(a,b int) int {
    if a%b==0 {
        return b
    }
    return gcd(b,a%b)
}

func min(a,b int) int {
    if a<b {
        return a
    }
    return b
}
```