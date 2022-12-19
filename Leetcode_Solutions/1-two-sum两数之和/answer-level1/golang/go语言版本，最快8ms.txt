根据大神的思路，提供go语言版本，实测8ms，下面直接上代码

func twoSum(nums []int, target int) []int {

	maps := make(map[int]int)
	nes := make([]int,0)

	for key,val := range nums {
		ant := target - val
		_,st := maps[ant]
		if st {
			nes = append(nes,maps[ant])
			nes = append(nes,key)
			return  nes
		}
		maps[val] = key
	}
	return nes
}