```
func poorPigs(buckets int, minutesToDie int, minutesToTest int) int {
    times := minutesToTest/minutesToDie
    times = times + 1
    result := math.Log(float64(buckets))/math.Log(float64(times))
    return int(math.Ceil(result))
}
```
