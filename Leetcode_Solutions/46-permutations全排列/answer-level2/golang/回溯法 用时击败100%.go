看着题解里很多代码篇幅挺大的，感觉自己写得还挺简洁的，上传上来供大家检验。

![image.png](https://pic.leetcode-cn.com/677d9c976c5763d68d6c10bae6a2c6177ae23a48b7f4beb397fcca544e0d9dec-image.png)


```go
    func permute(nums []int) [][]int {

        result := [][]int{}

        trackback(nums, []int{}, &result)
        
        return result
    }

    func trackback(nums []int, prev []int, result *[][]int) {
        if len(nums) == 1 {
            prev = append(prev, nums[0])
            tmpPrev := make([]int, len(prev))
            copy(tmpPrev, prev)
            *result = append(*result, tmpPrev)
            return
        }
        prevIndex := len(prev)
        prev = append(prev, -1)
        for i:=0; i<len(nums); i++ {
            prev[prevIndex] = nums[i]
            tmp := []int{}
            tmp = append(tmp, nums[:i]...)
            tmp = append(tmp, nums[i+1:]...)
            trackback(tmp, prev[:prevIndex + 1], result)
        }
    }
```
