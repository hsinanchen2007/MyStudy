```
func minimumTotal(triangle [][]int) int {
    
    n := len(triangle)
    
    a := make([]int,n) // 用来记录最小值
    
    
    for j,item:=range(triangle[n-1]){
        a[j] = item
    }
    
    
    for i:=n-2;i >=0;i --{
        
        for j,item:=range(triangle[i]){
            
            new_item:= min(item + a[j],item + a[j+1])
            a[j] = new_item  // 用于暂时记录上一层的数据
        }
        
    }
    
    return a[0]
    
}

func min(a int,b int) int{
    if a < b{
        return a
    }else{
        return b
    }
}
```