![image.png](https://pic.leetcode-cn.com/8253474fdd27145983c1affd7d348adb23394b3c312f5e567a11a58c4462a2a1-image.png)

因为题目中假定数组中一定存在众数，所以我们找出现次数最多的那个数就可以了。

```
func majorityElement(nums []int) int {  
    max := nums[0]                  // 出现次数最多的数
    hash := map[int]int{max:1}      // hash 表存储每个元素出现次数
    for i:=1; i<len(nums); i++ {
        hash[nums[i]]++
        if hash[nums[i]] > hash[max] {
            max = nums[i]
        }
    }
    return max
}
```