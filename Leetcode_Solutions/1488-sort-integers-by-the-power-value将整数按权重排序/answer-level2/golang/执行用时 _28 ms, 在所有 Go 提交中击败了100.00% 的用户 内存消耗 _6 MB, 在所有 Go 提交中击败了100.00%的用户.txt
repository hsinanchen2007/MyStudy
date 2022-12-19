
```golang
func getKth(lo int, hi int, k int) int {
    data := make([]int, 1001)
    data[1] = 1
    
    list := make([][]int, 0)
    
    for i := lo; i <=hi; i++ {
        rate := backtrack(i, data) 
        list = append(list, []int{i, rate})
    }
   
    sort.Slice(list, func (i,j int) bool{
        if list[i][1] != list[j][1]{
            return list[i][1] < list[j][1]
        }else {
            return list[i][0] < list[j][0]
        }
    })
    
   return list[k-1][0] 
}

func backtrack(i int, data []int) int {
    if i <= 1000 && data[i] > 0 {
        return data[i]
    }
    
    if i % 2 == 0 {
        
        a := backtrack(i/2, data) + 1
        if i <=1000 {
            data[i] = a
        }
        return a
    }else {
        a := backtrack(3*i+1, data) + 1 
         if i <=1000 {
            data[i] = a
        }
        return a
    }
}
```