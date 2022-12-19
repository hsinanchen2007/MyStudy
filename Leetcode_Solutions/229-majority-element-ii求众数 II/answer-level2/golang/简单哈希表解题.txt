第一种比较简单，就是放入哈希表，最后将哈希表中计数大于n/3的键进行输出。
```go
func majorityElement(nums []int) []int {
    dic := make(map[int]int,0)
    threshold := len(nums) / 3
    var res []int
    for _,v := range nums{
        dic[v]++
    }
    for i,v := range dic{
        if v > threshold{
            res = append(res, i)
        }
    }
    return res
}
```

第二种，借助一个额外的哈希表，记录是否已经进行过输出，这样可以少遍历一次。但空间上有额外开销。
```go
func majorityElement(nums []int) []int {
    dic := make(map[int]int,0)
    threshold := len(nums) / 3
    majDic := make(map[int]bool,0)
    var res []int
    for _,v := range nums{
        dic[v]++
        if dic[v] > threshold && majDic[v] == false{
            majDic[v] = true
            res = append(res,v)
        }
    }    
    return res
}
```

