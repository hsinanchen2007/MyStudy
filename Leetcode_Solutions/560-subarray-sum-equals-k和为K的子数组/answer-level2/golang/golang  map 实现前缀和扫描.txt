### 解题思路
1. map 的 key 为遍历过的前缀和 value 是表示此前缀在遍历过程中出现的次数
2. 假设存在区间 [a,b] 使得区间和为k, 也就是 b 前缀和 - a 前缀和 = k
3. 得  a 前缀和 = b前缀和 - k
4. a 前缀和就是曾经扫描过的 前缀和 在map中存储
5. b 前缀和 就当前遍历i处的前缀和
6. 因此在一次遍历的过程中我们只需要判断当前前缀和减k的值 是否存在map中而得知这个区间[a,b]是否存在
7. 并且根据累计map的值的和 可得到所有连续子数组的个数

### 代码

```golang
func subarraySum(nums []int, k int) int {   
    res , m , sum := 0, make(map[int]int,0),0
    m[0] = 1
    for i:=0;i<len(nums);i++{
        sum += nums[i]
        if _,ok := m[sum-k];ok{
            res += m[sum-k]
        }
        m[sum]++
    }
    return res
}
```