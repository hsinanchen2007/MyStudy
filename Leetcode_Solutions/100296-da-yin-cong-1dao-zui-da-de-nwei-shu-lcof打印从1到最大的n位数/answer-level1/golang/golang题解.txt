思路是: 先算出n位最大的数，然后循环打印即可
func printNumbers(n int) []int {
    if n <= 0 {
        return nil
    }
    max := 1
    for n != 0 {
        max *= 10
        n--
    }
    res := []int{}
    for i := 1; i < max; i++ {
        res = append(res, i)
    } 
    return res
}