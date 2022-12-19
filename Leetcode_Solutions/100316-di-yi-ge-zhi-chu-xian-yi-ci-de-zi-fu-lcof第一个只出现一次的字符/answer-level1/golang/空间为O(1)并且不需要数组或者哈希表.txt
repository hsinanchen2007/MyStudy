题目没有明确说明只有字母(如果只有字母的话后面就不需要分高低位了，一个数字就能满足)
所以这里使用的byte的所有范围, 也就是0-128，然后分组成高低位(0-63, 64-128(这里没有严格处理128这个字符))
使用4个变量hn(唯一存在的高位字符), ln(唯一存在的低位字符), ehn(已经存在的高位字符), eln(已经存在的低位字符)
其余逻辑请查阅代码注释
```
func firstUniqChar(s string) byte {
    // byte的范围0-128分开计算
	hn := uint64(0) // 64-128
	ln := uint64(0) // 0-63
	// 存放已经存在的
	ehn := uint64(0)
	eln := uint64(0)
	l := uint64(0)
    // 先循环找出所有只出现一次的字符
	for i := range s {
		if s[i] >= 64 {
			l = 1 << (s[i] - 64) // 没有严格处理128这个字符，128这里会报错，需要额外一个来储存(这里就不不实现了)，该解法只是提供思路
			if l&ehn == 0 {
				ehn |= l
				hn |= l
				continue
			}
			if hn&l != 0 {
				hn ^= l
			}
			continue
		}
		l = 1 << s[i]
		if l&eln == 0 {
			eln |= l
			ln |= l
			continue
		}
		if ln&l != 0 {
			ln ^= l
		}
	}
	ans := byte(' ')
	// 找到最新出现一次的字符
	for i := range s {
		if s[i] >= 64 {
			l = 1 << (s[i] - 64)
			if hn&l != 0 {
				ans = s[i]
				break
			}
			continue
		}
		l = 1 << s[i]
		if ln&l != 0 {
			ans = s[i]
			break
		}
	}
	return ans
}
```
