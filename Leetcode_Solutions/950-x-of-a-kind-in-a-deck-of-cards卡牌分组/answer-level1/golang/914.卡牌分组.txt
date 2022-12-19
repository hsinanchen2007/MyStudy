### 解题思路
第一次用golang写题有点不熟悉 wa了好多次
思路： 
map储存数字出现次数
遍历比较 每个数字的gcd 是否大于 2
全部成立 就是true
否则 false 
时间复杂度大概应该比O(n*n)快一点吧

### 代码

```golang
func hasGroupsSizeX(deck []int) bool {
    num := make(map[int]int)
    for _,v := range deck{
        num[v]++
    }
    
    
    for _,v := range num{
        for _,k := range num{
            if(gcd(v,k) < 2) {
                return false
            }
        }
        
    }
    return true
}

func gcd(a,b int) int {
    if (b == 0 ){
        return a
    }
    return gcd(b,a%b)
}
```