```
func distributeCandies(candies int, num_people int) []int {
    ret := make([]int, num_people)
    start, n := 0, 1
    for candies != 0 {
        if n <= candies {
            ret[start] += n
            candies -= n
        }else{
            ret[start] += candies
            break
        }
        n++
        start = (start+1)%num_people
    }
    return ret
}
```
