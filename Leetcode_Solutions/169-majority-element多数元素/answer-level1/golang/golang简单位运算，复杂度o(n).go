### 解题思路
1：把每个数字转换成二进制，二进制位全部加和塞到一个定长的int数组
2：遍历定长int数组，如果当前位的值超过n/2，那这一定是目标数据的组成之一
3：需要注意一下负数的情况，这里我把所有的数字都转化为正数，用flag来记录，遇到一个正数就+1，负数就减一，于是最后目标数据如果是负数，那flag一定为负数，最后可以根据flag的正负判断目标数据是正还是负

### 代码

```golang
func majorityElement(nums []int) int {
	p := [40]int{}
	flag := 0
	for _, v := range nums {
		if v < 0 {
			flag--
			v = -v
		} else {
			flag++
		}

		temp := v
		j := 0
		for temp != 0 {
			if temp%2 == 1 {
				p[j]++
			}
			temp /= 2
			j++
		}
	}

	res := 0
	v := 1
	for i := range p {
		if p[i] > len(nums)/2 {
			res = res + v
		}
		v = v << 1
	}
	if flag < 0 {
		res = -res
	}
	return res
}
```