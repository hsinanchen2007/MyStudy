
```golang
func maxSatisfied(customers []int, grumpy []int, X int) int {
    temp, sum := 0, 0 
    for i:=0; i < len(customers); i++ { 
        if grumpy[i] == 0 {
            sum = sum + customers[i] 
        }
    } 

    for j := 0; j < X;j++ {
        if grumpy[j]==1{
            temp += customers[j]
        }        
    }
   
    result := sum + temp
    max := result 
    for i := 1; i <= len(customers) - X; i++{   //用于处理 grumpy[i] == 1 的情况
        if grumpy[i-1]==1{
            result-=customers[i-1]
        }
        if grumpy[i+X-1]==1 {
            result+=customers[i+X-1]
        }
        if result>max {
            max = result
        }
    }

    return max
}
```