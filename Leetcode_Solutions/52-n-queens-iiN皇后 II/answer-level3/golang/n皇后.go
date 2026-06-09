### 代码

```golang
var x,y,ty []int
var sum int
func totalNQueens(n int) int {
    sum=0
    x=make([]int,n+1)
    ty=make([]int,n+1)
    todo(1,n)
    return sum
}


func todo(xx,n int){
    for i:=1;i<=n;i++{
        if ty[i]==0&&chack(xx,i,i){
            ty[i]=1
            x[xx]=i
            if xx==n{
                sum++
            }else{
                todo(xx+1,n)
            }
            ty[i]=0
        }
    }
}

func chack(xx,lie,n int)bool{
     x[xx]=lie
    for i:=1;i<xx;i++{
        for j:=i+1;j<=xx;j++{
            if j-i==int(math.Abs(float64(x[i]-x[j]))){
                x[xx]=0
                return false
            }
        }
    }
    return true
}
```