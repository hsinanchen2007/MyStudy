```
func generate(numRows int) [][]int {
    var res [][]int
    switch numRows{
        case 0:{
            return [][]int{}
        }
        case 1:{
            return [][]int{[]int{1}}
        }
        case 2:{
            return [][]int{[]int{1},[]int{1,1}}
        }
        default:{
            res = [][]int{[]int{1},[]int{1,1}}
            for i:=2;i<numRows;i++{
                var temp []int = make([]int,i+1)
                temp[0]=1
                temp[i]=1
                for j:=1; j < i;j++{
                    temp[j]= res[i-1][j-1]+res[i-1][j]
                }
                res = append(res,temp)
            }
        }
    }

    return res
}
```