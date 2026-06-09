### 解题思路
排序后可以节省hashmap的空间。

### 代码

```golang
func hasGroupsSizeX(deck []int) bool {

    dl := len(deck)
    if( dl < 2){
        return false
    }
    sd := sort.IntSlice(deck)

    sd.Sort()

    gcd := func(x,y int)int{
        for ; y != 0; {
            t := y
            y = x%y
            x = t
        }

        return x
    }
    t := sd[0]
    c,c2 := 0,0
    for i:=0;i<dl;i++{
        if( sd[i] == t){
            c++
        } else {
            if( c2 != 0){
                c2 = gcd(c,c2)
                if( c2 == 1){
                    return false
                }
            } else {
                if(c == 1){
                    return false
                }
                c2 = c
            }

            t = sd[i]
            c = 1
        }
    }

    if( c2 == 0){
        //single num;;

        cp := c
        for i:=2;i<=cp;i++ {
            if( c%i == 0 ){
                return true
            }

            cp = c/i
        }
        return false
    }

    if( gcd(c,c2) > 1 ){
        return true
    }

    return false
}
```