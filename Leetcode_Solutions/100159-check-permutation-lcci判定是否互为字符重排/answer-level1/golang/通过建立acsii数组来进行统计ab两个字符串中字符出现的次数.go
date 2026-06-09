话不多说，看代码
```
func CheckPermutation(s1 string, s2 string) bool {
	if len(s1) != len(s2) {
		return false
	}
    // 为什么是95？ 因为ascii码 0～31 和 127全是系统指令符，所以不会用到，所以声明了95的长度
	acsii := make([]int8, 95)
	for i, l := 0, len(s1); i < l; i++ {
        // a元素出现一次进行++
		acsii[int(s1[i] - ' ')]++
        // b元素出现一次进行--
		acsii[int(s2[i] - ' ')]--
	}
    // 如果两个字符串相等，则数组的任何元素的值都应该为0
	for _,v := range acsii {
		if v != 0 {
			return false
		}
	}
	return true
}
```
