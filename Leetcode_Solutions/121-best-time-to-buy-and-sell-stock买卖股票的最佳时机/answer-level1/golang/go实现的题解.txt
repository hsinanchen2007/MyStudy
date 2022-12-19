### 解题思路
参考C++最佳题解完成的go题解，初学go，没有泛型有点头疼

### 代码

```golang
func maxProfit(prices []int) int {
    if len(prices)<=1{
        return 0
    }
    max,temp := 0,0
    for i:=0;i<len(prices)-1;i++{
        temp = cmp(temp+prices[i+1]-prices[i],prices[i+1]-prices[i])
        max = cmp(temp,max)
    }
    if max<0{
        return 0
    }else{
        return max
    }
}

func cmp(x,y int) int{
    if x>y{
        return x
    }else{
        return y
    }
}
```