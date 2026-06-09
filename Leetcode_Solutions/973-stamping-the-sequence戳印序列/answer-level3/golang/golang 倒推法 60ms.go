这题使用倒退法求解较快。

我们通过不断的遍历target。只要发现target[i:i+len(stamp)] == stamp，那么我就将target中这一段每个字节修改为'?'，'?'作为通配符可以参与到下次的比较中。具体见注释
```
func movesToStamp(stamp string, target string) []int {
	bTarget := make([]byte, len(target))
	bStamp := []byte(stamp)
	for i := 0; i < len(target); i++ {
		bTarget[i] = '?'
	}
	now := []byte(target)
	ret := []int{}
	var flag = true
	for flag {
		flag = false // 如果没有匹配到任何段，说明不能再匹配了，返回。
                 // 如果now中所有值都是‘？’，那么说明成功了，倒置ret，返回结果
		if bytes.Compare(now, bTarget) == 0 {
			for i := 0; i < len(ret)/2; i++ {
				ret[i], ret[len(ret)-1-i] = ret[len(ret)-1-i], ret[i]
			}
			return ret
		}
                 // 每次都从头开始匹配
		for i := 0; i <= len(bTarget) - len(stamp); i++ {
                         // 如果这一段已经全部是‘？’，不需要再匹配
			if bytes.Compare(bTarget[i:i+len(stamp)], now[i:i+len(stamp)]) == 0 {
				continue
			}
			if compare(bStamp, now[i:i+len(stamp)]) {
				ret = append(ret, i)
                                  // 将所有值替换'?'
				for j := i; j < i + len(stamp); j++ {
					now[j] = '?'
				}
				flag = true
				break
			}
		}
	}
	return []int{}
}

// 比较函数
func compare(bs, bt []byte) bool {
	if bytes.Compare(bs, bt) == 0 {
		return true
	}
	for i := 0; i < len(bs); i++ {
		if bs[i] != bt[i] && bt[i] != '?' {
			return false
		}
	}
	return true
}
```