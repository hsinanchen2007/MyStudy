![wjywsnb.png](https://pic.leetcode-cn.com/851518cac90b186a5020902b5fc176850f62d0bbbfcf055098c66d13172c4c6b-wjywsnb.png)
```
func canMeasureWater(x int, y int, z int) bool {

    if x==z||y==z||x+y==z{
        return true
    }
    if x+y<z{
        return false
    }
    var res int=gongyue(&x,&y)
    return z%res==0
    
}
func gongyue(a *int,b *int) int{
    
    var temp int=0
    if *a<*b{
        
        temp=*a
        *a=*b
        *b=temp
    }
    for{
        if *b==0{
            break
        }
        temp=*a%*b
        *a=*b
        *b=temp
    }
    return *a
}
```

