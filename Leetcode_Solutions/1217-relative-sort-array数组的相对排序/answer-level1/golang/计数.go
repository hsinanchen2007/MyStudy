
```golang
func relativeSortArray(arr1 []int, arr2 []int) []int { 
    if len(arr1) == 0 {
        return []int{}
    }
    mmax := -1
    for i:=0; i < len(arr1); i++ {
        if arr1[i] > mmax {
            mmax = arr1[i]
        }
    }

    al := make([]int, mmax+1) 

    for i:=0; i < len(arr1); i++ {
        al[arr1[i]]++
    }
   
    result := make([]int, 0) 

    for i:= range arr2 {
        num := arr2[i] 

        for i:=0; i < al[num];i++ {
            result = append(result, num)
        }
        al[num] = 0
    }
    
    for i :=  range al {
        
        for j :=0; j < al[i];j++ {
            result = append(result, i)
        }
        al[i] = 0
    } 

    return result
}
```