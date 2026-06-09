### 解题思路
此处撰写解题思路

### 代码

```golang
func decompressRLElist(nums []int) []int {
    count := len(nums)/2
    var res[] int
    for i:=0; i < count ; i++ {
        freq := nums[2 * i]
        val := nums[2*i + 1]
        for j:=0; j<freq; j++ {
            res = append(res, val)
        }
    }
    return res
}
```