```
//循环数组
func distributeCandies(candies int, num_people int) []int {
    if candies<=0 || num_people<=0{
        return nil
    }
    res:=make([]int,num_people)
    index:=0
    for candies!=0{
        if candies >= index+1{
            res[index%num_people]+=(index+1)
            candies-=(index+1)
            index++
        }else{
            res[index%num_people]+=candies
            candies-=candies
        }
    }
    return res
}
```
