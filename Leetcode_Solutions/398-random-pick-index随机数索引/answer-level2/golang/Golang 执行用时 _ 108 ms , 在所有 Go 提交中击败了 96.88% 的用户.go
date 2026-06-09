### 解题思路
水塘抽样，只不过这一次是从和target相等的数字中抽样

### 代码

```golang
type Solution struct {
    nums []int
    r *rand.Rand
}


func Constructor(nums []int) Solution {
    solution := Solution{
        nums: nums,
        r: rand.New(rand.NewSource(time.Now().UnixNano())),
    }
    return solution
}


func (this *Solution) Pick(target int) int {
    index := 0
    count := 1
    for i := 0; i < len(this.nums); i++ {
        if this.nums[i] == target {
            if this.r.Intn(count)+1 == count {
                index = i
            }
            count++
        }
    }
    return index
}

### 复杂度分析
时间复杂度：O（n）遍历一遍数组
空间复杂度：O（1）常数额外空间


/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.Pick(target);
 */
```