### 解题思路
此处撰写解题思路
既然求幂集，则首先知道幂集个数是2^len(nums), 从0到2^len(nums) 遍历，遍历的每一个数用长度为len(nums) 的对应二进制数表示，不足则前缀补0，
然后遍历这个二进制数的每一个位，如若对应位为1则表示nums对应位置在该子集中
如示例[1,2,3]
0 - 000: []
1 - 001: [3]
2 - 010: [2]
3 - 011: [2,3]
4 - 100: [1]
5 - 101: [1,3]
6 - 110: [1,2]
7 - 111: [1,2,3]
(2^3-1)

### 代码

```golang
func subsets(nums []int) [][]int {
	result := make([][]int, 0)
	for i:=0;i<int(math.Pow(2, float64(len(nums))));i++ {
		item := make([]int, 0)
		bitI := strconv.FormatInt(int64(i), 2)
		for len(bitI) < len(nums) {
			bitI = "0" + bitI
		}
		for k,v:= range bitI {
			if v == '1' {
				item = append(item, nums[k])
			}
		}
		result = append(result, item)
	}
	return result
}
```