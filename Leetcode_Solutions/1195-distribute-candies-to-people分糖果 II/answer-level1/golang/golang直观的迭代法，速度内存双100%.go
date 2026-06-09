``` go
func distributeCandies(candies int, num_people int) []int {
    res := make([]int, num_people)
    base := 1
    for candies > 0 {
        for i := 0; i < num_people; i++ {
            if candies < base + i {
                res[i] += candies
                candies = 0
                break
            }
            res[i] += base + i
            candies -= base + i
        }
        base += num_people;
    }
    
    return res
}
```
水个题解，hard题我唯唯诺诺，easy题我重拳出击。